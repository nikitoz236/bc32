#include "flashsaver.h"
#include "flash.h"
#include "debug.h"


u32 fs_get_block_address(u16 bn)
{
	u32 addr = FLASH_BASE + FS_PAGESIZE * FS_FIRST_PAGE;
	addr += (bn * FS_BLOCK_SIZE);
	return addr;
}


u32 fs_get_word_address(u16 bn, u16 wordn)
{
	u32 addr = FLASH_BASE + FS_PAGESIZE * FS_FIRST_PAGE;
	addr += (bn * FS_BLOCK_SIZE);
	addr += 2 * wordn;
	return addr;
}


u8 fs_check_block_free(u16 bn)
{
	u8 flag = 1;

	for (u16 i = 0; i < FS_WORDS_IN_BLOCK; i++)
	{
		if (flash_read16(fs_get_word_address(bn, i)) != 0xFFFF)
		{
			flag = 0;
		}
	}
	return flag;
}

u16 fs_find_free_block(void)
{
	u16 bn = 0;

	while (bn < FS_AVAILABLE_BLOCKS)
	{
		if (fs_check_block_free(bn))
		{
			break;
		}
		bn++;
	}
	return bn;
}


u16 fs_get_buf_sum(u16 * buffer, u16 len)
{
	u16 sum = 0;
	for (u16 i = 0; i < len; i++ )
	{
		sum += buffer[i];
	}
	return sum;
}


u8 fs_check_block_sum(u16 bn)
{
	u16 sum = 0;
	for (u16 i = 0; i < (FS_WORDS_IN_BLOCK - 1); i++ )
	{
		sum += flash_read16(fs_get_word_address(bn, i));
	}
	if (sum == flash_read16(fs_get_word_address(bn, FS_WORDS_IN_BLOCK - 1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void fs_write_block(u16 * buffer, u16 len, u16 bn)
{
	dbn_d("Flash write block: ", bn);
	u16 sum = fs_get_buf_sum(buffer, len);
	u16 free_words = FS_WORDS_IN_BLOCK - len - 1;
	sum -= free_words;

	dbn_h16("CS: ", sum);

	flash_unlock();
	dbn_h32("Flash write address: ", fs_get_block_address(bn));
	flash_write_arr(fs_get_block_address(bn), buffer, len);
	flash_write16(fs_get_block_address(bn) + FS_BLOCK_SIZE - 2, sum);
	flash_lock();
}

u8 fs_read_block(u16 * buffer, u16 len, u16 bn)
{
	dbn_d("Flash read block: ", bn);
	if(fs_check_block_sum(bn))
	{
		dbn("CS correct!");
		dbn_h32("Flash read address: ", fs_get_block_address(bn));
		flash_read_arr16(buffer, fs_get_block_address(bn), len);
		return 1;
	}
	else
	{
		dbn("CS wrong!");
		return 0;
	}
}

void fs_format(void)
{
	dbn_h32("Flash erase page: ", fs_get_block_address(0));
	flash_unlock();
	flash_erase_page(fs_get_block_address(0));
	flash_lock();
}
