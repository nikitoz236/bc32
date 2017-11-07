#include "gpio.h"

void init_gpio( GPIO_TypeDef * port, u8 n, u8 mode )
{
	if( mode == 0b10001000 )
	{
		port->BSRR |= (1 << n);
	}
	else
	{
		port->BSRR |= (1 << (n + 16));
	}
	if (n > 7)
	{
		n -= 8;
		port->CRH &= ~( 0x0F << (4 * n));
		port->CRH |= ( 0x0F & mode ) << (4 * n);
	}
	else
	{
		port->CRL &= ~( 0x0F << (4 * n));
		port->CRL |= ( 0x0F & mode ) << (4 * n);
	}
}

void set_gpio( GPIO_TypeDef * port, u8 n, u8 value )
{
	if(value)
	{
		port->BSRR |= (1 << n);
	}
	else
	{
		port->BSRR |= (1 << (n + 16));
	}
}

u32 get_gpio ( GPIO_TypeDef * port)
{
	return port->IDR;
}
