#include "main.h"

/**
* printf_hexal - functin fpr [rinting hexaa
* @types: argumen
* @map_to: Array o
* @buffer: Buffers
* @flags:  activeflags
* @flag_ch: flags ch
* @width: widths
* @precision: sp3cfication
* @size: specifi3r
* @size: specification.
* Return: function.
*/
int printf_hexal(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int numb = va_arg(types, unsigned long int),  i_num = numb;
UNUSED(width);
numb = con_un_si(numb, size);
if (numb == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (numb > 0)
{
buffer[a--] = map_to[numb % 16];
numb /= 16;
}
if (flags & F_HASH && i_num != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
* printf_un - function for printing insigned
* @types: argumentsss
* @buffer: Buff3r
* @flags: flagss
* @width: width.
* @precision: sp3cification
* @size:specifi3r
* Return: functio.n
*/
int printf_un(va_list types, char buffer[], int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int numb = va_arg(types, unsigned long int);
numb = con_un_si(numb, size);
if (numb == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (numb > 0)
{
buffer[a--] = (numb % 10) + '0';
numb /= 10;
}
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
* printf_oct - function for octaaa
* @types: argumens
* @buffer: baffah
* @flags: flags.
* @width: widths
* @precision: sp3cification
* @size: specifie.r
* Return: functios
*/
int printf_oct(va_list types, char buffer[], int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int numb = va_arg(types, unsigned long int), i_num = numb;
UNUSED(width);
numb = con_un_si(numb, size);
if (numb == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (numb > 0)
{
buffer[a--] = (numb % 8) + '0';
numb /= 8;
}
if (flags & F_HASH && i_num != 0)
buffer[a--] = '0';
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
* printf_hex - functionfor hexa to be printed
* @types: arguments.
* @buffer: Baffah
* @flags: flag
* @width: widtsh
* @precision: sp3cification
* @size: specifi3r
* Return: function.
*/
int printf_hex(va_list types, char buffer[], int flags, int width, int precision, int size)
{
return (printf_hexal(types, "0123456789abcdef", buffer,	flags, 'x', width, precision, size));
}

/**
* printf_hexU - func to Prints an unsigned numbe
* @types: arguments type
* @buffer: Buffers
* @flags: flagsss
* @width: widths
* @precision: sp3cification
* @size: specifi3r
* Return: function.
*/
int printf_hexU(va_list types, char buffer[], int flags, int width, int precision, int size)
{
return (printf_hexal(types, "0123456789ABCDEF", buffer,	flags, 'X', width, precision, size));
}
