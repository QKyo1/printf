#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define BUFF_SIZE 1024

/**
* struct fm - structure
* @fm: Format
* @fn: Thee function
*/
struct fm
{
char fm;
int (*fn)(va_list, char[], int, int, int, int);
};


/**
* typedef struct fm match - Structure
* @fm: format of it
* @match: The function associated.
*/
typedef struct fm match;

int _printf(const char *format, ...);
int ha_printf(const char *fm, int *i, va_list list, char buff[], int flg, int wid, int pre, int siz);


int _putchar(char c);
int printchr(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printstr(va_list types, char buff[], int flg, int wid, int pre, int siz);
int print37(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printine(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printbin(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printfund(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printoct(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printhex(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printHEX(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printhexa(va_list types, char map_to[], char buff[], int flg, char flg_ch, int wid, int pre, int siz);
int printex_str(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printpoi(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printfrev(va_list types, char buff[], int flg, int wid, int pre, int siz);
int printro13(va_list types, char buff[], int flg, int wid, int pre, int siz);


int ha_flg(const char *format, int *i);
int ha_wid(const char *format, int *i, va_list list);
int ha_pre(const char *format, int *i, va_list list);
int ha_siz(const char *format, int *i);


int handle_write_char(char c, char buff[], int flg, int wid, int pre, int siz);
int write_number(int is_positive, int end, char buff[], int flg, int wid, int pre, int siz);
int write_num(int end, char buff[], int flg, int wid, int pre, int leen, char pad, char ex_c);
int write_pointer(char buff[], int end, int leen, int wid, int flg, char pad, char ex_c, int pad_start);

int write_unsgnd(int is_neg, int end, char buff[], int flg, int wid, int pre, int siz);


long int con_si_nu(int size, long int nu);
long int con_un_si(unsigned long int numb, int siz);

int is_ex(char);
int append_code(char, char[], int);
int isDigit(char);

#endif
