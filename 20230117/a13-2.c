#include <stdio.h>
#include <stdlib.h>

int ack(int m, int n);

main(int argc, char *argv[])
{
    int m, n, result;

    if (argc != 3) {
        fprintf(stderr, "Usage: a.out m n\n");
        exit(1);
    }

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    if (m < 0 || n < 0) {
        fprintf(stderr, "Error: Invalid number\n");
        exit(1);
    }

    result = ack(m ,n);

    fprintf(stdout, "ack(%d, %d) = %d\n", m, n, result);

    return 0;
}
int ack(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ack(m-1, 1);
    } else {
        return ack(m-1, ack(m, n-1));
    }
}