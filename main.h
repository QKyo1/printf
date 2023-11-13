#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFF_SIZE 1024


/**
* cr - counter + return count
* @counter: counter
* @ret_count: return counter
* @Describtion: tracks the buffer index and the return
*/

typedef struct cr {
int counter;
int ret_count;
} stu;

int _printf(const char *format, ...);
stu putchar(char c, char *buff, stu counter);
stu printD(long a, stu counter, char *buf);
stu printI(long a, stu counter, char *buf);
stu printB(unsigned int a, stu counter, char *buf);
stu printS(char *a, stu counter, char *buf);

#endif
