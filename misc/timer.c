#include "timer.h"

volatile u32 global_ms = 0;

void init_systick(void)
{
	SysTick->LOAD = F_CPU/1000 - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = (1 << 2) + (1 << 1) + (1 << 0);		// CLKSOURCE + TICKINT + ENABLE
}

void SysTick_Handler(void)
{
	global_ms++;
}


//==============================================================================

void delay_ms(u32 time)
{
	int start_time = global_ms;
	while(global_ms - start_time < time);
}

void delay_us(u32 time)
{
	uint32_t ticks = time * 24;
	uint32_t start = SysTick->VAL;
	volatile uint32_t countflag = SysTick->CTRL & (1 << 16);
	countflag = 1;
	u32 systick_val;
	while (countflag)
	{
		systick_val = SysTick->VAL;
		if (systick_val > start)
		{
			start += F_CPU/1000;
		}
		if (start - systick_val > ticks) countflag = 0;
	}
}



//==============================================================================


u8 timerIsOver(struct Timer * timer)
{
	if (global_ms > timer->start + timer->timeout) return 1;
	else return 0;
}

void timerSetTimeout(struct Timer * timer, uint32_t timeout)
{
	timer->timeout = timeout;
}

void timerReset(struct Timer * timer)
{
	timer->start = global_ms;
}

void timerStartTimeout(struct Timer * timer, u16 timeout)
{
	timer->timeout = timeout;
	timer->start = global_ms;
}

u32 timerGetTime(struct Timer * timer)
{
	return global_ms - timer->start;
}
