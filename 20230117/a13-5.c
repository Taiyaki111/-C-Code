#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hour;
    int wind;
    int pol;
} psensor;

int getrows(FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp, *fp_out;
    psensor *psensors;
    int c, num, memorySize, i;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: a.out inputFile outputFile\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(1);
    }

    if ((fp_out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
        exit(1);
    }

    num = getrows(fp);
    memorySize = sizeof(psensor) * num;

    if ((psensors = (psensor *) malloc(memorySize)) == NULL) {
        fprintf(stderr, "Error: cannot allocate memory %d bytes\n", memorySize);
        exit(1);
    }

    for (i = 0; i < num; i++) {
        if (fscanf(fp, "%d%d%d", &psensors[i].hour,
                    &psensors[i].wind, &psensors[i].pol) == EOF) {
            break;
        }

        fprintf(stdout, "hour = %d, wind = %d, pol = %d\n",
                psensors[i].hour, psensors[i].wind, psensors[i].pol);
        fprintf(fp_out, "hour = %d, wind = %d, pol = %d\n",
                psensors[i].hour, psensors[i].wind, psensors[i].pol);
    }

    free(psensors);
    fclose(fp);
    fclose(fp_out);

    return 0;
}

int getrows(FILE *fp)
{
    int chr, enter = 1;
    
    while((chr = fgetc(fp)) != EOF) {
        if (chr == '\n') {
            enter++;
        }
    }
    
    rewind(fp);
    
    return enter;
}