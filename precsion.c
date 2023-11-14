#include "main.h"

/**
* h_precision - functions for handling the precsiong
* @format: Formatt.
* @i: List of arguments.
* @list: list of arguments2
* Return: Precision
*/

int h_precision(const char *format, int *i, va_list list)
{
int precision = -1;
int c_i = *i + 1;
if (format[c_i] != '.')
return (precision);
precision = 0;
for (c_i += 1; format[c_i] != '\0'; c_i++)
{
if (isDigit(format[c_i]))
{
precision *= 10;
precision += format[c_i] - '0';
}
else if (format[c_i] == '*')
{
c_i++;
precision = va_arg(list, int);
break;
}
else
break;
}
*i = c_i - 1;
return (precision);
}

