#include "core.h"

#define RING_BUFFER_SIZE	64

struct Rb
{
	u8 head;
	u8 tail;
	char buf[RING_BUFFER_SIZE];
};




void rbClear(struct Rb * rbuf);
char rbGetNoShift(struct Rb * rbuf);
char rbAvailable(struct Rb * rbuf);
void rbPut(struct Rb * rbuf, char value);
char rbGet(struct Rb * rbuf);
