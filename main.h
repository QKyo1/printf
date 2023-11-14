#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

/**
* cr - counter and restaring of counter
* @coun: start of the counter
* @ret: restarting of the counter
* @Describtion: tracks buffer and the restaring of the count3r
*/

typedef struct cr {
int coun;
int ret;
} cn;

int _printf(const char *format, ...);

#endif
