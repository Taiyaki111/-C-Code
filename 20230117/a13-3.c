#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
    int num1, num2;

    if (argc != 3) {
        fprintf(stderr, "Usage: ./a.out num1 num2\n");
        exit(1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    while (num2 != 0) {
        int c = (num1 & num2) << 1;
        num1 ^= num2;
        num2 = c;
    }

    fprintf(stdout, "%d\n", num1);

    return 0;
}