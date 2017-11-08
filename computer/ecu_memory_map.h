#include "core.h"

typedef struct
{
	u16 rpm;				// 	0x00	Обороты двигателя 2 байта
	u8 speed;				// 	0x02	Скорость
	u8 na_03[5];			// 		-нет данных-
	u8 digital_sensors[8];	// 	0x08	Дискретные датчики
} HondaMemoryMap_0;

typedef struct
{
	u8 t_engine;			// 	0x10	Температура ОЖ (град)
	u8 t_intake;			// 	0x11	Температура входящего воздуха (град)
	u8 p_intake;			// 	0x12	Датчик абсолютного давления (кПа)
	u8 p_atm;				// 	0x13	Датчик атмосферного давления (кПа)
	u8 tps;					// 	0x14	Датчик положения ДЗ (%)
	u8 oxy;					// 	0x15	Напряжение управляющего ЛЗ (В)
	u8 na_16;				// 		-нет данных-
	u8 voltage;				// 	0x17	Напряжение сети (В)
	u8 alt_load;			// 	0x18	Нагрузка на генератор ALT_FR (%)
	u8 eld_load;			// 	0x19	Электрическая нагрузка блок ELD (А)
	u8 na_1A;				// 		-нет данных-
	u8 erg;					// 	0x1B	Датчик положения клапана EGR (В)
	u8 na_1C[4];			// 		-не известно-
} HondaMemoryMap_1;

typedef struct
{
	u8 correction_short;	// 	0x20	Краткосрочная коррекция (%)
	u8 na_21;				// 		-нет данных-
	u8 correction_long;		// 	0x22	Долгосрочная коррекция (%)
	u8 na_23;				// 		-нет данных-
	u16 injection;			// 	0x24	Время впрыска (мс)
	u8 ign_adv;				// 	0x26	Угол Опережения Зажигания - IngAdv
	u8 ign_knock_limit;		// 	0x27	Ограничение УОЗ по ДД - IngLim
	u8 idle_position;		// 	0x28	Клапан холостого хода (%)
	u8 idle_current;		// 	0x29	Клапан холостого хода (мА)
	u8 na_2A;				// 		-не известно-
	u8 egr_control;			// 	0x2B	Управление клапаном EGR (%)
	u8 egr_position;		// 	0x2C	Датчик положения клапана EGR (%)
	u8 na_2D;				// 		-нет данных-
	u8 air_fuel;			// 	0x2E	Отношение воздух/топливо AF FB CMD
	u8 pcs_evap_position;	// 	0x2F	Клапан PCS EVAP (%)
} HondaMemoryMap_2;

typedef struct
{
	u8 na_30[12];			// 		-нет данных-
	u8 knock;				// 	0x3C	Датчик детонации
	u8 na_3D[3];			// 		-нет данных-
} HondaMemoryMap_3;

typedef struct				// 		Freeze Frame 1
{
	u8 na_60;				// 		-нет данных-
	u8 speed;				// 	0x61	Скорость
	u16 rpm;				// 	0x62	Обороты двигателя (2 байта)
	u8 t_engine;			// 	0x64	Температура ОЖ (град)
	u8 t_intake;			// 	0x65	Температура входящего воздуха (град)
	u8 p_intake;			// 	0x66	Датчик абсолютного давления (кПа)
	u8 p_atm;				// 	0x67	Датчик атмосферного давления (кПа)
	u8 tps;					// 	0x68	Датчик положения ДЗ (%)
	u8 voltage;				// 	0x69	Напряжение сети (В)
	u16 injection;			// 	0x6A	Время впрыска (мс)
	u8 oxy;					// 	0x6C	Напряжение управляющего ЛЗ (В)
	u8 correction_short;	// 	0x6D	Краткосрочная коррекция (%)
	u8 idle_position;		// 	0x6E	Клапан холостого хода
	u8 egr_position;		// 	0x6F	Датчик положения клапана EGR (В)
} HondaMemoryMap_6;

typedef struct
{
	u8 na_70[8];			//
	u8 ecu_id[5];			// 	0x78	ECU ID (5 байт)
	u8 na_7D[3];			//
} HondaMemoryMap_7;

typedef struct
{
	u8 na_90[8];			//
	u8 errors;				// 	0x98	Дискретные датчики
	u8 na_99;				//
	u8 fss;					// 	0x9A	Состояние топливной системы FSS
	u8 na_9B;				//
	u8 engine_load;			// 	0x9C	Нагрузка на двигатель (%)
	u8 na_9D[3];			//
} HondaMemoryMap_9;

typedef struct
{
	u8 oxy_voltage;			// 	0xA0	Напряжение проверяющего ЛЗ (В)
	u8 na_A1[12];			//
	u8 digital_sensors;		// 	0xAD	Дискретные датчики	Подогрев ЛЗ-2
	u8 na_AE[2];			//
} HondaMemoryMap_A;

typedef struct
{
	u8 na_B0[6];			//
	u8 ign_fails;			// 	0xB6	Пропуск зажигания MisF_Cyl
	u8 na_B7[5];			//
	u8 ckp_learn;			// 	0xBC	Обучение CKP_Learn
	u8 na_BD[3];			//
} HondaMemoryMap_B;

typedef struct				// 	Freeze Frame 2
{
	u8 fss;					// 	0xE0	Состояние топливной системы FSS
	u8 na_E1;				// 	0xE1
	u8 correction_long;		// 	0xE2	Долгосрочная коррекция (%)
	u8 na_E3;				// 	0xE3
	u8 oxy_voltage;			// 	0xE4	Напряжение проверяющего ЛЗ (В)
	u8 na_E5;				// 	0xE5
	u8 engine_load;			// 	0xE6	Нагрузка на двигатель (%)
	u8 na_E7[];				// 	0xE7
} HondaMemoryMap_E;



#define DS_0_START				( 1 << 0 )		// 	Стартер										1-Вкл, 0-Выкл
#define DS_0_AC_BUTTON			( 1 << 1 )		// 	Кнопка кондиционера							1-Замкнут, 0-Разомкнут
#define DS_0_WHEEL_FORCER		( 1 << 2 )		// 	Датчик усилителя руля						1-Замкнут, 0-Разомкнут
#define DS_0_BREAK				( 1 << 3 )		// 	Педаль тормоза								1-Замкнут, 0-Разомкнут
#define DS_0_AT_SELECTOR		( 1 << 4 )		// 	Селектор АКПП
#define DS_0_VTEC_SENSOR		( 1 << 7 )		// 	Датчик давления VTEC						1-Замкнут, 0-Разомкнут
#define DS_1_DIAGNOSTIC			( 1 << 4 )		// 	Самодиагностика SCS							1-Замкнут, 0-Разомкнут
#define DS_2_VTEC_VALVE			( 1 << 3 )		// 	Клапан VTEC									1-Вкл, 0-Выкл
#define DS_3_FUEL_PUMP			( 1 << 0 )		// 	Главное реле (топливный насос)				1-Вкл, 0-Выкл
#define DS_3_AC_CLUTCH			( 1 << 1 )		// 	Муфта кондиционера							1-Вкл, 0-Выкл
#define DS_3_OXY1_HEAT			( 1 << 2 )		// 	Нагрев Датчик Кислорода 1					1-Вкл, 0-Выкл
#define DS_3_CHECK_ENGINE		( 1 << 5 )		// 	Лампа Check Engine							1-Вкл, 0-Выкл
#define DS_3_OXY2_HEAT			( 1 << 7 )		// 	Нагрев Датчик Кислорода 2					1-Вкл, 0-Выкл
#define DS_4_ALT_CONTROL		( 1 << 0 )		// 	Управление генератором ALT_C				1-Вкл, 0-Выкл
#define DS_4_FAN_CONTROL		( 1 << 1 )		// 	Управление вентилятором охлаждения FAN_C	1-Вкл, 0-Выкл
#define DS_4_IAB				( 1 << 2 )		// 	Управление впускным коллектором IAB			1-Вкл, 0-Выкл
#define DS_4_VTEC_E				( 1 << 3 )		// 	VTEC-E										1-Вкл, 0-Выкл
#define DS_4_ECONO				( 1 << 7 )		// 	Лампа Econo									1-Вкл, 0-Выкл
#define DS_5_AT_SUPPORT			( 1 << 4 )		// 	Управление опорой двигателя с АКПП			1-Вкл, 0-Выкл
#define DS_7_CLOSED_LOOP		( 1 << 0 )		// 	Обратная связь коррекции по ДК				1-Вкл, 0-Выкл
