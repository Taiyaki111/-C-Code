#include <stdio.h>
#include <stdlib.h>

void output(FILE *);

main(int argc, char *argv[])
{
    int c, i;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: a.out <filename>\n");
        exit(1);
    } else {
        if ((fp = fopen(argv[1], "r")) == NULL) {
            fprintf(stderr, "Error: %s can't be opened\n", argv[1]);
            exit(1);
        }
        output(fp);
        fclose(fp);
    }

    return 0;
}

void output(FILE *fp)
{
    int c;
    int i = 0;
    FILE *fpNew;

    fpNew = fopen("a10data_withid.txt", "w");

    while ((c = fgetc(fp)) != EOF) {
        if (i == 0) {
            fprintf(stdout, "0 ");
            fprintf(fpNew, "0 ");
            i++;
        }

        if (c == '\n') {
            fprintf(stdout, "\n%d ", i);
            fprintf(fpNew, "\n%d ", i);
            i++;
            continue;
        }
        fputc(c, stdout);
        fputc(c, fpNew);
    }
    fputc('\n', stdout);
    fputc('\n', fpNew);
    
    fclose(fpNew);
}