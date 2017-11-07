#include "computer.h"

struct BC bc;

u32 t_convert(u8 x)
{
	double result = (155.04149 - x*3.0414878 + x*x*0.03952185 - x*x*x*0.00029383913 + x*x*x*x*0.0000010792568 - x*x*x*x*x*0.0000000015618437) * 1000;
	return (u32)result;
}


void calc_kline (u8 * frame, u8 page)
{
	switch(page)
	{
	case 0 :
		bc.rpm.value = ((HondaMemoryMap_0*)frame)->rpm >> 2;
		bc.speed.value = ((HondaMemoryMap_0*)frame)->speed;
		break;

	case 1 :
		bc.temp_engine.value = t_convert(((HondaMemoryMap_1*)frame)->t_engine);
		bc.temp_intake.value = t_convert(((HondaMemoryMap_1*)frame)->t_intake);
		bc.pressure_intake.value = ((HondaMemoryMap_1*)frame)->p_intake * 716 - 5000;
		bc.pressure_atm.value = ((HondaMemoryMap_1*)frame)->p_atm * 716 - 5000;
		bc.throttle.value = (((HondaMemoryMap_1*)frame)->tps - 24) * 500;
		bc.voltage_obd.value = mul(((HondaMemoryMap_1*)frame)->voltage, 95.693779);
		bc.alternator_load.value = mul(((HondaMemoryMap_1*)frame)->alt_load, 392.156862);
		bc.current.value = 77060 - mul(((HondaMemoryMap_1)frame)->eld_load, 394.150802);

		break;

	case 2 :
//		correction_short->value = (((double)buffer[0] / 128 - 1) * 100);
//		correction_long->value = (((double)buffer[2] / 128 - 1) * 100);
//		injection->value = (double)(256 * buffer[4] + buffer[5]) / 250;
//		idling_valve->value = buffer[8] / 2.55;
		break;

	case 9 :
//		engine_load->value = buffer[0xC] / 2.55;
		break;

	default:
		break;
	}

}
