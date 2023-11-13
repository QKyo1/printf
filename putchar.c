#include <unistd.h>
#include "main.h"

/**
* putchar - writes the character
* @c: The character to print
* @buff: buffer
* @counts: counter
* Return: On success 1 On error -1
*/
stu putchar(char c, char *buff, stu counts)
{
stu new_counts;
if (counts.counter == BUFFER_SIZE)
{
flush(buff, counts.counter);
counts.counter = 0;
}
buff[counts.counter] = c;
counts.counter++;
counts.ret_count++;
new_counts.counter = counts.counter;
new_counts.ret_count = counts.ret_count;
return (new_counts);
}
