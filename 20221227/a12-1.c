#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


double averageif(int num, double threshold, ...);

main()
{
    printf("averageif(3, 0.0, 2.2, -3.3, 1.7) = %f\n",
    averageif(3, 0.0, 2.2, -3.3, 1.7));
    printf("averageif(4, 2.1, 2.2, 3.3, 1.4, 0.5) = %f\n",
    averageif(4, 2.1, 2.2, 3.3, 1.4, 0.5));
    printf("averageif(0, 2.2) = %f\n", averageif(0, 2.2));

	return 0;
}

double averageif(int num, double threshold, ...)
{
    if (num == 0) {
        fprintf(stderr, "First argument is 0\n");
        exit(1);
    }
	int i;
    double count = 0, tmp, sum;
	va_list va_ptr;					  /* ポインタの宣言 */
	
	va_start(va_ptr, threshold);			   /* ポインタの初期化 */
	
	for (sum = 0, i = 0; i < num; i++) {
		tmp = va_arg(va_ptr, double);	  /* 引数へのアクセス */
        if (tmp > threshold) {
            sum += tmp;
            count++;
        }
    }
	va_end(va_ptr);					  /* ポインタの後処理 */
	
	return sum / count;
}