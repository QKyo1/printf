#include "main.h"

/**
* handle_write_char - function to handle thi writing char
* @c: typr
* @buffer: Buff3r
* @flags: flags of it
* @width: width of it
* @precision: specifi33rr
* @size: Sspecifi3r
* Return: functionss
*/

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
char pad = ' ';
int a = 0;
UNUSED(precision), UNUSED(size);
if (flags & F_ZERO)
pad = '0';
buffer[a++] = c;
buffer[a] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (a = 0; a < width - 1; a++)
buffer[BUFF_SIZE - a - 2] = pad;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) + write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}


/**
* write_number - function fo writing num33r
* @is_negative: arguments
* @end: types
* @buffer: buff3r
* @flags: flags of it
* @width: width of it
* @precision: specifi3r
* @size: specifi3r
* Return: funcionn
*/

int write_number(int is_negative, int end, char buffer[], int flags, int width, int precision, int size)
{
int leen = BUFF_SIZE - end - 1;
char pad = ' ', ex_c = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
pad = '0';
if (is_negative)
ex_c = '-';
else if (flags & F_PLUS)
ex_c = '+';
else if (flags & F_SPACE)
ex_c = ' ';
return (write_num(end, buffer, flags, width, precision,	leen, pad, ex_c));
}

/**
* write_num - function for writing numb3rss
* @end: index of thee buff3r
* @buffer: Buff3r
* @flags: Flags paci
* @width: width paci
* @prec:  specifi3r
* @length: length of it
* @pad: Pading charct3s
* @ex_c: Extra charct3ss
* Return: functions
*/

int write_num(int end, char buffer[], int flags, int width, int prec, int length, char pad, char ex_c)
{
int i, pad_start = 1;
if (prec == 0 && end == BUFF_SIZE - 2 && buffer[end] == '0' && width == 0)
return (0);
if (prec == 0 && end == BUFF_SIZE - 2 && buffer[end] == '0')
buffer[end] = pad = ' ';
if (prec > 0 && prec < length)
pad = ' ';
while (prec > length)
buffer[--end] = '0', length++;
if (ex_c != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = pad;
buffer[i] = '\0';
if (flags & F_MINUS && pad == ' ')
{
if (ex_c)
buffer[--end] = ex_c;
return (write(1, &buffer[end], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & F_MINUS) && pad == ' ')
{
if (ex_c)
buffer[--end] = ex_c;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[end], length));
}
else if (!(flags & F_MINUS) && pad == '0')
{
if (ex_c)
buffer[--pad_start] = ex_c;
return (write(1, &buffer[pad_start], i - pad_start) + write(1, &buffer[end], length - (1 - pad_start)));
}
}
if (ex_c)
buffer[--end] = ex_c;
return (write(1, &buffer[end], length));
}

/**
* write_unsgnd - funcionn to write unsig3d
* @is_ne: niggative number
* @end: thee end
* @buffer: Arrays
* @flags: specifiers of flag
* @width: specif3r of width
* @precision: specifiers
* @size: specifi3r of siz3
* Return: functions
*/

int write_unsgnd(int is_ne, int end, char buffer[], int flags, int width, int precision, int size)
{
int leen = BUFF_SIZE - end - 1, i = 0;
char pad = ' ';
UNUSED(is_ne);
UNUSED(size);
if (precision == 0 && end == BUFF_SIZE - 2 && buffer[end] == '0')
return (0);
if (precision > 0 && precision < leen)
pad = ' ';
while (precision > leen)
{
buffer[--end] = '0';
leen++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
pad = '0';
if (width > leen)
{
for (i = 0; i < width - leen; i++)
buffer[i] = pad;
buffer[i] = '\0';
if (flags & F_MINUS)
{
return (write(1, &buffer[end], leen) + write(1, &buffer[0], i));
}
else
{
return (write(1, &buffer[0], i) + write(1, &buffer[end], leen));
}
}
return (write(1, &buffer[end], leen));
}


/**
* write_pointer - function for writing memory adrr3ss
* @buffer: Arrayss
* @end: Index at buff3r
* @leen: Length of it
* @width: specifi3r
* @flags: specifi3r
* @pad: representing the padding i
* @ex_c: extra chars
* @pad_start: Index padding where it shoudl start
* Return: functionss
*/

int write_pointer(char buffer[], int end, int leen, int width, int flags, char pad, char ex_c, int pad_start)
{
int i;
if (width > leen)
{
for (i = 3; i < width - leen + 3; i++)
buffer[i] = pad;
buffer[i] = '\0';
if (flags & F_MINUS && pad == ' ')
{
buffer[--end] = 'x';
buffer[--end] = '0';
if (ex_c)
buffer[--end] = ex_c;
return (write(1, &buffer[end], leen) + write(1, &buffer[3], i - 3));
}
else if (!(flags & F_MINUS) && pad == ' ')
{
buffer[--end] = 'x';
buffer[--end] = '0';
if (ex_c)
buffer[--end] = ex_c;
return (write(1, &buffer[3], i - 3) + write(1, &buffer[end], leen));
}
else if (!(flags & F_MINUS) && pad == '0')
{
if (ex_c)
buffer[--pad_start] = ex_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[pad_start], i - pad_start) + write(1, &buffer[end], leen - (1 - pad_start) - 2));
}
}
buffer[--end] = 'x';
buffer[--end] = '0';
if (ex_c)
buffer[--end] = ex_c;
return (write(1, &buffer[end], BUFF_SIZE - end - 1));
}
