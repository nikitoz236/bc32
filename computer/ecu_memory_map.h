#include "core.h"

typedef struct
{
	u16 rpm;				// 	0x00	������� ��������� 2 �����
	u8 speed;				// 	0x02	��������
	u8 na_03[5];			// 		-��� ������-
	u8 digital_sensors[8];	// 	0x08	���������� �������
} HondaMemoryMap_0;

typedef struct
{
	u8 t_engine;			// 	0x10	����������� �� (����)
	u8 t_intake;			// 	0x11	����������� ��������� ������� (����)
	u8 p_intake;			// 	0x12	������ ����������� �������� (���)
	u8 p_atm;				// 	0x13	������ ������������ �������� (���)
	u8 tps;					// 	0x14	������ ��������� �� (%)
	u8 oxy;					// 	0x15	���������� ������������ �� (�)
	u8 na_16;				// 		-��� ������-
	u8 voltage;				// 	0x17	���������� ���� (�)
	u8 alt_load;			// 	0x18	�������� �� ��������� ALT_FR (%)
	u8 eld_load;			// 	0x19	������������� �������� ���� ELD (�)
	u8 na_1A;				// 		-��� ������-
	u8 erg;					// 	0x1B	������ ��������� ������� EGR (�)
	u8 na_1C[4];			// 		-�� ��������-
} HondaMemoryMap_1;

typedef struct
{
	u8 correction_short;	// 	0x20	������������� ��������� (%)
	u8 na_21;				// 		-��� ������-
	u8 correction_long;		// 	0x22	������������ ��������� (%)
	u8 na_23;				// 		-��� ������-
	u16 injection;			// 	0x24	����� ������� (��)
	u8 ign_adv;				// 	0x26	���� ���������� ��������� - IngAdv
	u8 ign_knock_limit;		// 	0x27	����������� ��� �� �� - IngLim
	u8 idle_position;		// 	0x28	������ ��������� ���� (%)
	u8 idle_current;		// 	0x29	������ ��������� ���� (��)
	u8 na_2A;				// 		-�� ��������-
	u8 egr_control;			// 	0x2B	���������� �������� EGR (%)
	u8 egr_position;		// 	0x2C	������ ��������� ������� EGR (%)
	u8 na_2D;				// 		-��� ������-
	u8 air_fuel;			// 	0x2E	��������� ������/������� AF FB CMD
	u8 pcs_evap_position;	// 	0x2F	������ PCS EVAP (%)
} HondaMemoryMap_2;

typedef struct
{
	u8 na_30[12];			// 		-��� ������-
	u8 knock;				// 	0x3C	������ ���������
	u8 na_3D[3];			// 		-��� ������-
} HondaMemoryMap_3;

typedef struct				// 		Freeze Frame 1
{
	u8 na_60;				// 		-��� ������-
	u8 speed;				// 	0x61	��������
	u16 rpm;				// 	0x62	������� ��������� (2 �����)
	u8 t_engine;			// 	0x64	����������� �� (����)
	u8 t_intake;			// 	0x65	����������� ��������� ������� (����)
	u8 p_intake;			// 	0x66	������ ����������� �������� (���)
	u8 p_atm;				// 	0x67	������ ������������ �������� (���)
	u8 tps;					// 	0x68	������ ��������� �� (%)
	u8 voltage;				// 	0x69	���������� ���� (�)
	u16 injection;			// 	0x6A	����� ������� (��)
	u8 oxy;					// 	0x6C	���������� ������������ �� (�)
	u8 correction_short;	// 	0x6D	������������� ��������� (%)
	u8 idle_position;		// 	0x6E	������ ��������� ����
	u8 egr_position;		// 	0x6F	������ ��������� ������� EGR (�)
} HondaMemoryMap_6;

typedef struct
{
	u8 na_70[8];			//
	u8 ecu_id[5];			// 	0x78	ECU ID (5 ����)
	u8 na_7D[3];			//
} HondaMemoryMap_7;

typedef struct
{
	u8 na_90[8];			//
	u8 errors;				// 	0x98	���������� �������
	u8 na_99;				//
	u8 fss;					// 	0x9A	��������� ��������� ������� FSS
	u8 na_9B;				//
	u8 engine_load;			// 	0x9C	�������� �� ��������� (%)
	u8 na_9D[3];			//
} HondaMemoryMap_9;

typedef struct
{
	u8 oxy_voltage;			// 	0xA0	���������� ������������ �� (�)
	u8 na_A1[12];			//
	u8 digital_sensors;		// 	0xAD	���������� �������	�������� ��-2
	u8 na_AE[2];			//
} HondaMemoryMap_A;

typedef struct
{
	u8 na_B0[6];			//
	u8 ign_fails;			// 	0xB6	������� ��������� MisF_Cyl
	u8 na_B7[5];			//
	u8 ckp_learn;			// 	0xBC	�������� CKP_Learn
	u8 na_BD[3];			//
} HondaMemoryMap_B;

typedef struct				// 	Freeze Frame 2
{
	u8 fss;					// 	0xE0	��������� ��������� ������� FSS
	u8 na_E1;				// 	0xE1
	u8 correction_long;		// 	0xE2	������������ ��������� (%)
	u8 na_E3;				// 	0xE3
	u8 oxy_voltage;			// 	0xE4	���������� ������������ �� (�)
	u8 na_E5;				// 	0xE5
	u8 engine_load;			// 	0xE6	�������� �� ��������� (%)
	u8 na_E7[];				// 	0xE7
} HondaMemoryMap_E;



#define DS_0_START				( 1 << 0 )		// 	�������										1-���, 0-����
#define DS_0_AC_BUTTON			( 1 << 1 )		// 	������ ������������							1-�������, 0-���������
#define DS_0_WHEEL_FORCER		( 1 << 2 )		// 	������ ��������� ����						1-�������, 0-���������
#define DS_0_BREAK				( 1 << 3 )		// 	������ �������								1-�������, 0-���������
#define DS_0_AT_SELECTOR		( 1 << 4 )		// 	�������� ����
#define DS_0_VTEC_SENSOR		( 1 << 7 )		// 	������ �������� VTEC						1-�������, 0-���������
#define DS_1_DIAGNOSTIC			( 1 << 4 )		// 	��������������� SCS							1-�������, 0-���������
#define DS_2_VTEC_VALVE			( 1 << 3 )		// 	������ VTEC									1-���, 0-����
#define DS_3_FUEL_PUMP			( 1 << 0 )		// 	������� ���� (��������� �����)				1-���, 0-����
#define DS_3_AC_CLUTCH			( 1 << 1 )		// 	����� ������������							1-���, 0-����
#define DS_3_OXY1_HEAT			( 1 << 2 )		// 	������ ������ ��������� 1					1-���, 0-����
#define DS_3_CHECK_ENGINE		( 1 << 5 )		// 	����� Check Engine							1-���, 0-����
#define DS_3_OXY2_HEAT			( 1 << 7 )		// 	������ ������ ��������� 2					1-���, 0-����
#define DS_4_ALT_CONTROL		( 1 << 0 )		// 	���������� ����������� ALT_C				1-���, 0-����
#define DS_4_FAN_CONTROL		( 1 << 1 )		// 	���������� ������������ ���������� FAN_C	1-���, 0-����
#define DS_4_IAB				( 1 << 2 )		// 	���������� �������� ����������� IAB			1-���, 0-����
#define DS_4_VTEC_E				( 1 << 3 )		// 	VTEC-E										1-���, 0-����
#define DS_4_ECONO				( 1 << 7 )		// 	����� Econo									1-���, 0-����
#define DS_5_AT_SUPPORT			( 1 << 4 )		// 	���������� ������ ��������� � ����			1-���, 0-����
#define DS_7_CLOSED_LOOP		( 1 << 0 )		// 	�������� ����� ��������� �� ��				1-���, 0-����
