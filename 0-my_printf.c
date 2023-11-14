#include "main.h"

/**
* print_buff - function to print the buffer
* @buff: atgumet of buffer
* @buff_ind: Index
*/

void print_buff(char buff[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buff[0], *buff_ind);
*buff_ind = 0;
}

/**
* _printf - my print f function
* @format: argument of the format
* Return: pointer
*/

int _printf(const char *format, ...)
{
int flg, wid, pre, siz, buff_ind = 0;
int i, pr = 0, printed_cha = 0;
va_list list;
char buff[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buff[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buff(buff, &buff_ind);
printed_cha++;
}
else
{
print_buff(buff, &buff_ind);
flg = ha_flg(format, &i);
wid = ha_wid(format, &i, list);
pre = ha_pre(format, &i, list);
siz = ha_siz(format, &i);
++i;
pr = ha_printf(format, &i, list, buff, flg, wid, pre, siz);
if (pr == -1)
return (-1);
printed_cha += pr;
}
}
print_buff(buff, &buff_ind);
va_end(list);
return (printed_cha);
}
