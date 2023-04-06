#include <stdio.h>
#include <stdlib.h>

#define LINE_MAX 30


void output(FILE *);
int getrows(FILE *fp);

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
    int i, captital_num;
    FILE *fpNew;
    struct capital* capitals;

    fpNew = fopen("a10data_withid3.txt", "w");

    capital_num = getrows(fp);
    
    if ((capitals = (struct capital *) malloc(sizeof(struct capital) * capital_num))) {
        fprintf(stderr, "Error: cannot allocate memory\n");
        exit(1);
    }

    for (i = 0; i < captital_num; i++) {
        fscanf(fp, "%d%s%lf%lf", 
            &capitals[i].id, capitals[i].name, &capitals[i].latitude, &capitals[i].longitude);
        
        fprintf(stdout, "ID = %d, Capital = %s, Latitude = %.2lf, Longtitude = %.2lf\n"
            , capitals[i].id, capitals[i].name, capitals[i].latitude, capitals[i].longitude);
        fprintf(fpNew, "ID = %d, Capital = %s, Latitude = %.2lf, Longtitude = %.2lf\n"
            , capitals[i].id, capitals[i].name, capitals[i].latitude, capitals[i].longitude);
        
    }

    fclose(fpNew);
    free(p);
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