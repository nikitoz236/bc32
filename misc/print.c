#include "print.h"

static const char hexvalues[] = "0123456789ABCDEF";

void printHEX8(u8 value, void (*write)(char c))
{
	write(hexvalues[(value >> 4) & 0x0F]);
	write(hexvalues[value & 0x0F]);
}

void printHEX16(u16 value, void (*write)(char c))
{
	write(hexvalues[(value >> 12) & 0x0F]);
	write(hexvalues[(value >> 8) & 0x0F]);
	write(hexvalues[(value >> 4) & 0x0F]);
	write(hexvalues[value & 0x0F]);
}

void printHEX32(u32 value, void (*write)(char c))
{
	write(hexvalues[(value >> 28) & 0x0F] );
	write(hexvalues[(value >> 24) & 0x0F]);
	write(hexvalues[(value >> 20) & 0x0F]);
	write(hexvalues[(value >> 16) & 0x0F]);
	write(hexvalues[(value >> 12) & 0x0F]);
	write(hexvalues[(value >> 8) & 0x0F]);
	write(hexvalues[(value >> 4) & 0x0F]);
	write(hexvalues[value & 0x0F]);
}

void print(char* str, void (*write)(char c))
{
	while (*str != 0)
	{
		write(*str++);
	}
}

void print_L(char* str, u16 field_width, void (*write)(char c))
{
	int over = 0;
	while (field_width--)
	{
		if (over)
		{
			write(' ');
		}
		else
		{
			if(*str != 0) write(*str++);
			else
			{
				write(' ');
				over = 1;
			}
		}
	}
}


void printDEC(u32 value, void (*write)(char c))
{
	int devider = 1;
	int razr = 1;

	while ((devider * 10) <= value)
	{
		devider = devider * 10;
	}

	while (devider != 1)
	{
		razr = value / devider;
		write('0' + razr);
		value -= razr * devider;
		devider = devider / 10;
	}
	write('0' + value);
}

void printDEC_L(u32 value, u16 field_width, void (*write)(char c))
{
	int devider = 1;
	int razr = 1;

	while ((devider * 10) <= value)
	{
		devider = devider * 10;
		razr++;
	}

	if ((field_width != 0) && (field_width > razr))
	{
		razr = field_width - razr;
		while (razr--)
		{
			write(' ');
		}
	}

	while (devider != 1)
	{
		razr = value / devider;
		write('0' + razr);
		value -= razr * devider;
		devider = devider / 10;
	}
	write('0' + value);
}

void printCRLF(void (*write)(char c))
{
	write('\n');
	write('\r');
}

void printHEXbuf(u8 * buffer, u16 amount, void (*write)(char c))
{
	while(amount--)
	{
		printHEX8(*buffer++, write);
		write(' ');
	}
}
