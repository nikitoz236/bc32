#include "core.h"

typedef struct
{
	u16 rpm;
	u8 speed;
	u8 na_03[5];
	u8 digital_sensors[8];
} HondaMemoryMap_0;

typedef struct
{
	u8 t_engine;
	u8 t_intake;
	u8 p_intake;
	u8 p_atm;
	u8 tps;
	u8 oxy;
	u8 na_16;
	u8 voltage;
	u8 alt_load;
	u8 eld_load;
	u8 na_1A;
	u8 erg;
	u8 na_1C[4];
} HondaMemoryMap_1;

typedef struct
{
	u8 correction_short;
	u8 na_21;
	u8 correction_long;
	u8 na_23;
	u16 injection;
	u8 ign_adv;
	u8 ign_knock_limit;
	u8 idle_position;
	u8 idle_current;
	u8 na_2A;
	u8 egr_control;
	u8 egr_position;
	u8 na_2D;
	u8 air_fuel;
	u8 pcs_evap_position;
} HondaMemoryMap_2;

typedef struct
{
	u8 na_30[12];
	u8 knock;
	u8 na_3D[3];
} HondaMemoryMap_3;
