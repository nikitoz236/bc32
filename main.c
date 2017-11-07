#include "core.h"
#include "uart.h"
#include "debug.h"

int main(void)
{

	init_u1(9600);

	write_u1('A');

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
