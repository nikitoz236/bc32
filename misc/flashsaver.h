#include <stm32f10x.h>


#define		FS_PAGESIZE			1024
#define		FS_PAGES			1
#define 	FS_FIRST_PAGE		126
#define 	FS_BLOCK_SIZE		32


#define 	FS_WORDS_IN_BLOCK	(FS_BLOCK_SIZE / 2)
#define		FS_AVAILABLE_BLOCKS	(FS_PAGESIZE * FS_PAGES / FS_BLOCK_SIZE)



u32 fs_get_block_address(u16 bn);
u32 fs_get_word_address(u16 bn, u16 wordn);

u8 fs_check_block_free(u16 bn);
u8 fs_check_block_sum(u16 bn);

u16 fs_get_buf_sum(u16 * buffer, u16 len);
u16 fs_find_free_block(void);

void fs_write_block(u16 * buffer, u16 len, u16 bn);
u8 fs_read_block(u16 * buffer, u16 len, u16 bn);

void fs_format(void);
