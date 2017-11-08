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
		bc.current.value = 77060 - mul(((HondaMemoryMap_1*)frame)->eld_load, 394.150802);

		break;

	case 2 :
		bc.correction_short.value = mull(((HondaMemoryMap_2*)frame)->correction_short, 781.25) - 100000;
		bc.correction_long.value = mull(((HondaMemoryMap_2*)frame)->correction_long, 781.25) - 100000;
		bc.injection.value = ((HondaMemoryMap_2*)frame)->injection * 4;
		bc.idling_valve.value = mul(((HondaMemoryMap_2*)frame)->idle_position, 392.156862);
		break;

	case 3 :
		bc.knock.value = mull(((HondaMemoryMap_3*)frame)->knock, 18,181818);
		break;

	case 9:
		bc.engine_load.value = mull(((HondaMemoryMap_3*)frame)-> , 392.156862);

	default:
		break;
	}

}
