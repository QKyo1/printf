#include "main.h"

/**
* print_buffer - function to Prints thee buff3r
* @buffer: thee buff3r
* @buff_ind: Index to add next char
*/

void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}

/**
* _printf - function to my first print f
* @format: argum3nt
* Return: Printed values
*/
int _printf(const char *format, ...)
{
int flags, width, precision, size, buff_ind = 0;
int i, pr = 0, printed_cha = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_cha++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = h_flags(format, &i);
width = h_width(format, &i, list);
precision = h_precision(format, &i, list);
size = h_size(format, &i);
++i;
pr = h_printf(format, &i, list, buffer, flags, width, precision, size);
if (pr == -1)
return (-1);
printed_cha += pr;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_cha);
}
