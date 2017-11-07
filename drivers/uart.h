#ifndef USART_H
#define USART_H

#include "core.h"


#define UART1_TX_BUFFER		16
#define UART1_RX_BUFFER		16

//#define UART2_TX_BUFFER		16
#define UART2_RX_BUFFER		16

//#define UART3_TX_BUFFER		16
//#define UART3_RX_BUFFER		16

char available_u1(void);
char available_u2(void);
char available_u3(void);

u8 read_u1(void);
u8 read_u2(void);
u8 read_u3(void);

void init_u1(u32 baud);
void init_u2(u32 baud);
void init_u3(u32 baud);

void write_u1_now(char c);
void write_u2_now(char c);
void write_u3_now(char c);

void write_u1(char c);
void write_u2(char c);
void write_u3(char c);



#endif
