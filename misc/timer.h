#ifndef TIMER_H
#define TIMER_H

#include "core.h"

extern volatile u32 global_ms;

struct Timer
{
	u32 timeout;
	u32 start;
};

void init_systick(void);
void delay_ms(u32 time);
void delay_us(u32 time);

u8 timerIsOver(struct Timer * timer);
void timerSetTimeout(struct Timer * timer, u32 timeout);
void timerReset(struct Timer * timer);
u32 timerGetTime(struct Timer * timer);

void timerStartTimeout(struct Timer * timer, u16 timeout);


#endif
