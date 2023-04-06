#include <stdio.h>

union number {
    double input; // 8byte
    unsigned char output1[8]; // 1byte x 8
    unsigned short output2[4]; // 2byte x 4
};

main()
{
    union number a;

    printf("double: ");
    scanf("%lf", &a.input);

    printf("unsigned char: %#x %#x %#x %#x %#x %#x %#x %#x\n"
        , a.output1[7], a.output1[6], a.output1[5], a.output1[4]
        , a.output1[3], a.output1[2], a.output1[1], a.output1[0]);
    printf("unsigned short: %hu %hu %hu %hu\n"
        , a.output2[3], a.output2[2], a.output2[1], a.output2[0]);

    return 0;
}