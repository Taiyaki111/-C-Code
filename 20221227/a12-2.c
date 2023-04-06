#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define MAXBUF 100


int myprintf(int num, ...);
void myitoa(int val, char *buf);
char *input(char *buf);


main()
{
    int a = 123;
    int b = 45;
    myprintf(2, a, b);
    myprintf(3, 1, 2, 3);
    myprintf(4, 0, 1, 12, 123);
    myprintf(5, 0, -1, -12, -123, -1234);

	return 0;
}

int myprintf(int num, ...)
{
    va_list va_ptr;
	char buf[MAXBUF];
	int i;

	va_start(va_ptr, num);

	for (i = 0; i < num; i++) {
		myitoa(va_arg(va_ptr, int), buf);
        fputs(buf, stdout);
        putchar(' ');
	}

    putchar('\n');
    
	return i;
}