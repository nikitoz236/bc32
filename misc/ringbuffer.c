#include "ringbuffer.h"


void rbClear(struct Rb * rbuf)
{
	rbuf->head = 0;
	rbuf->tail = 0;
}

char rbGetNoShift(struct Rb * rbuf)
{
	return rbuf->buf[rbuf->tail];
}

char rbAvailable(struct Rb * rbuf)
{
	return rbuf->head != rbuf->tail;
//	return (RING_BUFFER_SIZE + rbuf->head - rbuf->tail) % RING_BUFFER_SIZE;
}

void rbPut(struct Rb * rbuf, char value)
{
	rbuf->buf[rbuf->head] = value;
	rbuf->head++;
	if(rbuf->head >= RING_BUFFER_SIZE) rbuf->head = 0;

}

char rbGet(struct Rb * rbuf)
{
	char value = rbuf->buf[rbuf->tail];
	rbuf->tail++;
	if (rbuf->tail >= RING_BUFFER_SIZE) rbuf->tail = 0;
	return value;
}

