#include "core.h"
#include "uart.h"
#include "debug.h"
#include "timer.h"

#define mul(a, b) 		((a) * (u32)((b) * (1 << 16))) >> 16

int main(void)
{
	init_systick();
	init_u1(9600);


	u8 param = 135;
	u32 val;
	val = mul( param , 392.156862);

	db_d("calculated 52941,17637: ", val);

    while(1)
    {
    	if(available_u1())
    	{
    		char a = read_u1();
    		dbn("Recieved char: ");
    		write_u1(a);
    		db_h8("    code: ", a);
    	}
    }
}
