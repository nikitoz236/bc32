#ifndef PRINT_H
#define PRINT_H

#include "core.h"

void printHEX8(u8 value, void (*write)(char c));
void printHEX16(u16 value, void (*write)(char c));
void printHEX32(u32 value, void (*write)(char c));

void print(char* str, void (*write)(char c));
void print_L(char* str, u16 field_width, void (*write)(char c));
void printDEC(u32 value, void (*write)(char c));
void printDEC_L(u32 value, u16 field_width, void (*write)(char c));
void printCRLF(void (*write)(char c));
void printHEXbuf(u8 * buffer, u16 amount, void (*write)(char c));


#endif
