#include "uart.h"
#include "gpio.h"
#include "ringbuffer.h"



void uart_write_int(USART_TypeDef * port, IRQn_Type irqn, char c, struct Rb * buf);

#ifdef UART1_RX_BUFFER
struct Rb uart1_rx_buf;
char available_u1(void) { return rbAvailable(&uart1_rx_buf); };
u8 read_u1(void) { return rbGet(&uart1_rx_buf); };
#endif

#ifdef UART2_RX_BUFFER
struct Rb uart2_rx_buf;
char available_u2(void) { return rbAvailable(&uart2_rx_buf); };
u8 read_u2(void) { return rbGet(&uart2_rx_buf); };
#endif

#ifdef UART3_RX_BUFFER
struct Rb uart3_rx_buf;
char available_u3(void) { return rbAvailable(&uart3_rx_buf); };
u8 read_u3(void) { return rbGet(&uart3_rx_buf); };
#endif



#ifdef UART1_TX_BUFFER
struct Rb uart1_tx_buf;
void write_u1(char c) {	uart_write_int( USART1, USART1_IRQn, c, &uart1_tx_buf); };
#endif

#ifdef UART2_TX_BUFFER
struct Rb uart2_tx_buf;
void write_u2(char c) {	uart_write_int( USART2, USART2_IRQn, c, &uart2_tx_buf); };
#endif

#ifdef UART3_TX_BUFFER
struct Rb uart3_tx_buf;
void write_u3(char c) {	uart_write_int( USART3, USART3_IRQn, c, &uart3_tx_buf); };
#endif





//============================================================================================================================================
//INIT SECTION
//============================================================================================================================================

void uart_init(USART_TypeDef * port, IRQn_Type irqn, u32 baud)
{
	port->CR1 |= USART_CR1_UE + USART_CR1_TE + USART_CR1_RE;		// UE + TE + RE
	port->CR1 |= USART_CR1_RXNEIE;									// Bit 5 RXNEIE: RXNE interrupt enable
	port->BRR = F_APB2 / baud;
	NVIC_EnableIRQ (irqn);
}

void init_u1(u32 baud)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	init_gpio(GPIOA, 9, OUTPUT_ALT_PP);
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
#ifdef UART1_RX_BUFFER
	rbClear(&uart1_rx_buf);
#endif
#ifdef UART1_TX_BUFFER
	rbClear(&uart1_tx_buf);
#endif
	uart_init(USART1, USART1_IRQn, baud);
}

void init_u2(u32 baud)
{
//	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//	init_gpio(GPIOA, 9, OUTPUT_ALT_PP);
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
#ifdef UART2_RX_BUFFER
	rbClear(&uart2_rx_buf);
#endif
#ifdef UART2_TX_BUFFER
	rbClear(&uart2_tx_buf);
#endif
	uart_init(USART2, USART2_IRQn, baud);
}

void init_u3(u32 baud)
{
//	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//	init_gpio(GPIOA, 9, OUTPUT_ALT_PP);
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
#ifdef UART3_RX_BUFFER
	rbClear(&uart3_rx_buf);
#endif
#ifdef UART3_TX_BUFFER
	rbClear(&uart3_tx_buf);
#endif
	uart_init(USART3, USART3_IRQn, baud);
}

//============================================================================================================================================
//WRITE SECTION
//============================================================================================================================================

void uart_write_int(USART_TypeDef * port, IRQn_Type irqn, char c, struct Rb * buf)
{
	NVIC_DisableIRQ (irqn);
	rbPut(buf, c);
	NVIC_EnableIRQ (irqn);
	USART1->CR1 |= USART_CR1_TXEIE;									// Bit 7 TXEIE: TXE interrupt enable
}


void uart_write_now(USART_TypeDef * port, char c)
{
	while(!(port->SR & USART_SR_TC)); 								//∆дем пока бит TC в регистре SR станет 1
	port->DR = c; 													//ќтсылаем байт через UART
}


void write_u1_now(char c) { uart_write_now( USART1, c); };
void write_u2_now(char c) { uart_write_now( USART2, c); };
void write_u3_now(char c) { uart_write_now( USART3, c); };










//============================================================================================================================================
//IRQ SECTION
//============================================================================================================================================

void uart_irq_handler_rx(USART_TypeDef * port, struct Rb * rxbuf)
{
	if (port->SR & USART_SR_RXNE)							// Bit 5 RXNE: Read data register not empty
	{
		rbPut(rxbuf, port->DR);
	}
}



void uart_irq_handler_tx(USART_TypeDef * port, struct Rb * txbuf)
{
	if (port->SR & USART_SR_TXE)							// Bit 7 TXE: Transmit data register empty
	{
		if(rbAvailable(txbuf))
		{
			port->DR = rbGet(txbuf);
		}
		else
		{
			port->CR1 &= ~USART_CR1_TXEIE;				// Bit 7 TXEIE: TXE interrupt enable
		}
	}
}

void USART1_IRQHandler(void)
{
#ifdef UART1_RX_BUFFER
	uart_irq_handler_rx(USART1, &uart1_rx_buf);
#endif
#ifdef UART1_TX_BUFFER
	uart_irq_handler_tx(USART1, &uart1_tx_buf);
#endif
}

void USART2_IRQHandler(void)
{
#ifdef UART2_RX_BUFFER
	uart_irq_handler_rx(USART2, &uart2_rx_buf);
#endif
#ifdef UART2_TX_BUFFER
	uart_irq_handler_tx(USART2, &uart2_tx_buf);
#endif
}

void USART3_IRQHandler(void)
{
#ifdef UART3_RX_BUFFER
	uart_irq_handler_rx(USART3, &uart3_rx_buf);
#endif
#ifdef UART3_TX_BUFFER
	uart_irq_handler_tx(USART3, &uart3_tx_buf);
#endif
}
