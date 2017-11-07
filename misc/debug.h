#ifndef DEBUG_H
#define DEBUG_H

#include "uart.h"
#include "print.h"



#define db_hb(str, val, l)		print(str, &write_u1); printHEXbuf(val, l, &write_u1)
#define db_h32(str, val)		print(str, &write_u1); printHEX32(val, &write_u1)
#define db_h16(str, val)		print(str, &write_u1); printHEX16(val, &write_u1)
#define db_h8(str, val)			print(str, &write_u1); printHEX8(val, &write_u1)
#define db_d(str, val)			print(str, &write_u1); printDEC(val, &write_u1)
#define db_dl(str, val, l)		print(str, &write_u1); printDEC_L(val, l, &write_u1)
#define db(str)					print(str, &write_u1)

#define dbi_hb(str, val, l)		print(str, &write_u1_now); printHEXbuf(val, l, &write_u1_now)
#define dbi_h32(str, val)		print(str, &write_u1_now); printHEX32(val, &write_u1_now)
#define dbi_h16(str, val)		print(str, &write_u1_now); printHEX16(val, &write_u1_now)
#define dbi_h8(str, val)		print(str, &write_u1_now); printHEX8(val, &write_u1_now)
#define dbi_d(str, val)			print(str, &write_u1_now); printDEC(val, &write_u1_now)
#define dbi_dl(str, val, l)		print(str, &write_u1_now); printDEC_L(val, l, &write_u1_now)
#define dbi(str)				print(str, &write_u1_now)

#define dbn_hb(str, val, l)		print(str, &write_u1); printHEXbuf(val, l, &write_u1); printCRLF(&write_u1_now)
#define dbn_h32(str, val)		print(str, &write_u1); printHEX32(val, &write_u1); printCRLF(&write_u1_now)
#define dbn_h16(str, val)		print(str, &write_u1); printHEX16(val, &write_u1); printCRLF(&write_u1_now)
#define dbn_h8(str, val)		print(str, &write_u1); printHEX8(val, &write_u1); printCRLF(&write_u1_now)
#define dbn_d(str, val)			print(str, &write_u1); printDEC(val, &write_u1); printCRLF(&write_u1_now)
#define dbn_dl(str, val, l)		print(str, &write_u1); printDEC_L(val, l, &write_u1); printCRLF(&write_u1_now)
#define dbn(str)				print(str, &write_u1); printCRLF(&write_u1_now)

#define dbni_hb(str, val, l)	print(str, &write_u1_now); printHEXbuf(val, l, &write_u1_now); printCRLF(&write_u1_now)
#define dbni_h32(str, val)		print(str, &write_u1_now); printHEX32(val, &write_u1_now); printCRLF(&write_u1_now)
#define dbni_h16(str, val)		print(str, &write_u1_now); printHEX16(val, &write_u1_now); printCRLF(&write_u1_now)
#define dbni_h8(str, val)		print(str, &write_u1_now); printHEX8(val, &write_u1_now); printCRLF(&write_u1_now)
#define dbni_d(str, val)		print(str, &write_u1_now); printDEC(val, &write_u1_now); printCRLF(&write_u1_now)
#define dbni_dl(str, val, l)	print(str, &write_u1_now); printDEC_L(val, l, &write_u1_now); printCRLF(&write_u1_now)
#define dbni(str)				print(str, &write_u1_now); printCRLF(&write_u1_now)







#endif



