#ifndef GPIO_H
#define GPIO_H

#include "core.h"

#define INPUT_FLOATING			0b00000100
#define INPUT_PULL_UP			0b10001000
#define INPUT_PULL_DN			0b00001000
#define INPUT_ANALOG			0b00000000
#define OUTPUT_PP				0b00000011
#define OUTPUT_OD				0b00000111
#define OUTPUT_ALT_PP			0b00001011
#define OUTPUT_ALT_OD			0b00001111

void init_gpio( GPIO_TypeDef * port, u8 n, u8 mode );
void set_gpio( GPIO_TypeDef * port, u8 n, u8 value );
u32 get_gpio ( GPIO_TypeDef * port);

#endif
