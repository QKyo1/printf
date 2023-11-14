#include "main.h"
/**
* ha_printf - function to print
* @ft: argum3nts
* @list: list
* @end: end
* @buff: Buffer
* @flg: flag
* @wid: width
* @pre: spe
* @siz: size
* Return: 1 or 2..
*/
int ha_printf(const char *fm, int *end, va_list list, char buff[], int flg, int wid, int pre, int siz)
{
int i, leen = 0, pchars = -1;
match f_m[] = {
{'c', printchr}, {'s', printstr}, {'%', print37}, {'i', printine}, {'d', printine}, {'b', printbin}, {'u', printund}, {'o', printoct}, {'x', printhex}, {'X', printHEX}, {'p', printpoi}, {'S', printex_str}, {'r', printrev}, {'R', printro13}, {'\0', NULL}
};
for (i = 0; f_m[i].fm != '\0'; i++)
if (fm[*end] == f_m[i].fm)
return (f_m[i].fn(list, buff, flg, wid, pre, siz));
if (f_m[i].fm == '\0')
{
if (fm[*end] == '\0')
return (-1);
leen += write(1, "%%", 1);
if (fm[*end - 1] == ' ')
leen += write(1, " ", 1);
else if (wid)
{
--(*end);
while (fm[*end] != ' ' && fm[*end] != '%')
--(*end);
if (fm[*end] == ' ')
--(*end);
return (1);
}
leen += write(1, &fm[*end], 1);
return (leen);
}
return (pchars);
}
