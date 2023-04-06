#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define MAXBUF 100


int myprintf(const char *format, ...);
void myitoa(int val, char *buf);
char *input(char *buf);


main()
{
    myprintf("ddd", 0, 123, 45);
    myprintf("ddddd", 0, -1, -12, -123, -1234);
    myprintf("abc", 1, 2, 3);

	return 0;
}

int myprintf(const char *format, ...)
{
    va_list va_ptr;
	char buf[MAXBUF], type;
	int i;

	va_start(va_ptr, format);

	for (i = 0; type = *format++; i++) {
		switch (type) {
		case 'd':
        	myitoa(va_arg(va_ptr, int), buf);
            fputs(buf, stdout);
            putchar(' ');
			break;
		default:
			fprintf(stderr, "Illegal format type.\n");
			return EOF;
		}
	}

    putchar('\n');
    
	return i;
}