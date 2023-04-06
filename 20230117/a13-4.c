#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int imax(const int num, ...);

int main()
{
printf("%d\n", imax(3, 1, 2, 3));
printf("%d\n", imax(3, 2, 3, 1));
printf("%d\n", imax(3, 3, 1, 2));
printf("%d\n", imax(8, 1, 2, 3, 5, 888, 999, 3, 10));
printf("%d\n", imax(3, -3, -7, -9));
return 0;
}

int imax(const int num, ...)
{
    int i, tmp;
    int max = INT_MIN;
    va_list va_ptr;
    va_start(va_ptr, num);

    for (i = 0; i < num; i++) {
        tmp = va_arg(va_ptr, int);

        if (tmp > max) {
            max = tmp;
        }
    }
    va_end(va_ptr);

    return max;
}