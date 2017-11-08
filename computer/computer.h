#include "core.h"
#include "ecu_memory_map.h"


#define INJECTOR_PERFOMANCE		235

#define OBD_WAITING_TIMEOUT				2000





typedef struct
{
	u32 value;
	u16 factor;
} BCvalue;

struct BC
{
	BCvalue rpm;
	BCvalue speed;
	BCvalue throttle;
	BCvalue temp_engine;
	BCvalue temp_intake;
	BCvalue pressure_atm;
	BCvalue pressure_intake;
	BCvalue injection;
	BCvalue fuel_consumption_h;
	BCvalue fuel_consumption_km;
	BCvalue fuel_consumption;
	BCvalue fuel_total;
	BCvalue fuel_average;
	BCvalue alternator_load;
	BCvalue engine_load;
	BCvalue correction_short;
	BCvalue correction_long;
	BCvalue idling_valve;
	BCvalue current;
	BCvalue voltage_obd;
	BCvalue voltage_adc;
	BCvalue tank;
	BCvalue obd_period;
	BCvalue knock;
};

extern struct BC bc;

void calc_kline (u8 * frame, u8 page);
