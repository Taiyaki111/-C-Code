#include <stdio.h>
#include <stdlib.h>

#define LINE_MAX 30
#define CAPITAL_NUM 8

void output(FILE *);

struct capital {
    int id;
    char name[LINE_MAX];
    double latitude;
    double longitude; 
};

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
    int i;
    FILE *fpNew;
    struct capital capitals[CAPITAL_NUM];

    fpNew = fopen("a10data_withid2.txt", "w");

    for (i = 0; i < CAPITAL_NUM; i++) {
        fscanf(fp, "%d%s%lf%lf", 
            &capitals[i].id, capitals[i].name, &capitals[i].latitude, &capitals[i].longitude);
        
        fprintf(stdout, "ID = %d, Capital = %s, Latitude = %.2lf, Longtitude = %.2lf\n"
            , capitals[i].id, capitals[i].name, capitals[i].latitude, capitals[i].longitude);
        fprintf(fpNew, "ID = %d, Capital = %s, Latitude = %.2lf, Longtitude = %.2lf\n"
            , capitals[i].id, capitals[i].name, capitals[i].latitude, capitals[i].longitude);
        
    }

    fclose(fpNew);
}