#include <stdio.h>

#define swap(type, x, y)  \
do { \
    type tmp = x; \
    x = y; \
    y = tmp; \
} while (0)

main(int argc, char *argv[])
{
    int int_a, int_b;
    double d_a, d_b;

    printf("before swap(int): ");
    scanf("%d%d", &int_a, &int_b);
    swap(int, int_a, int_b);
    printf("after swap(int): %d %d\n", int_a, int_b);


    printf("before swap(double): ");
    scanf("%lf%lf", &d_a, &d_b);
    swap(double, d_a, d_b);
    printf("after swap(double): %.3lf %.3lf\n", d_a, d_b);
    // 上の行, doubleの出力は %f でよい

	return 0;
}
