#include <stdio.h>
#include <stdlib.h>

#define EVENODD(x) (((x) % 2) == 0 ? 0 : 1)

#define SQUARE(x) ((x) * (x))

#define PRINTEVEN(x) printf("%d is an even number.\n", x)

main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Invalid arguments\n");
        exit(1);
    }

    int num = atoi(argv[1]);

    if (EVENODD(num) == 1) {
        printf("%d * %d = %d\n", num, num, SQUARE(num));
    } else {
        PRINTEVEN(num);
    }

	return 0;
}
