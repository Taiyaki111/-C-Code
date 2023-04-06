#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define MAXBUF 100


int myprintf(const char *format, ...);
void myitoa(int val, char *buf);
char *input(char *buf);


main()
{
    char str1[] = "Pro3";
    char str2[] = "Sugoku";
    myprintf("%s %s %s 100%% Tanoshii!\n", str1, str2, str2);
    myprintf("%c %d %d %s\n", 'A', 123, -45, "xyz");
    myprintf("%choge%dfoo%dhehe%s\n", 'X', 256, 0, str1);
    return 0;
}

int myprintf(const char *format, ...)
{
    va_list va_ptr;
	char buf[MAXBUF], type, c, *str;
	int i;

	va_start(va_ptr, format);

	for (i = 0; type = *format++; i++) {
        switch (type) {
        case '%':
            type = *format++;
            i++;
            switch (type) {
		    case 'd':
        	    myitoa(va_arg(va_ptr, int), buf);
                fputs(buf, stdout);
			    break;
            case 'c':
                c = va_arg(va_ptr, int);
                putchar(c);
			    break;
            case 's':
                str = va_arg(va_ptr, char*);
                fputs(str, stdout);
                break;
            case '%':
        	    putchar('%');
			    break;
		    }
            break;
        default:
    		putchar(type);
	    	break;
        }
	}
    
	return i;
}