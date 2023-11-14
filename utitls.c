#include "main.h"

/**
* is_ex - function to be printtrd
* @c: arguments
* Return:0
*/

int is_ex(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}

/**
* append_code - function to print appended
* @buffer: arrays
* @i: arguments
* @asciiCode: ASSCI CODE.
* Return: 3
*/

int append_code(char asciiCode, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (asciiCode < 0)
asciiCode *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[asciiCode / 16];
buffer[i] = map_to[asciiCode % 16];
return (3);
}

/**
* isDigit - Verifies ifitis a digit
* @ch: arguments
* Return: 0
*/

int isDigit(char ch)
{
if (ch >= '0' && ch <= '9')
return (1);
return (0);
}

/**
* con_si_nu - function to Casts nu,berss
* @nu: argumenys
* @size: arguments
* Return: nu.
*/

long int con_si_nu(int size, long int nu)
{
if (size == S_LONG)
return (nu);
else if (size == S_SHORT)
return ((short)nu);
return ((int)nu);
}


/**
* con_un_si - function to Casts a number to the specified size..
* @numb: argumentss
* @size: arguments
* Return: numb.
*/

long int con_un_si(unsigned long int numb, int size)
{
if (size == S_LONG)
return (numb);
else if (size == S_SHORT)
return ((unsigned short)numb);
return ((unsigned int)numb);
}
