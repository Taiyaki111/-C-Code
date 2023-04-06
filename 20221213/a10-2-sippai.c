#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LINE_MAX 30

void output(FILE *);

struct capital {
    int id;
    char *name;
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
    char line[LINE_MAX+1];
    struct capital cap;

    fpNew = fopen("a10data_withid.txt", "w");

    while ((c = fgetc(fp)) != EOF) {
        for (i = 0; i < 8; i++) {
            fgets(line, LINE_MAX, fp);
            cap.id = i;
            cap.name = strtok(line, " ");
            printf("%s", strtok(NULL, " "));
            printf("%s", strtok(NULL, " "));
            //cap.latitude = (double)strtok(NULL, " ");
            //cap.longitude = (double)strtok(NULL, " ");

            fprintf(stdout, "ID = %d, Capital = %s, Latitude = %.2lf, Longtitude = %.2lf\n"
                , cap.id, cap.name, cap.latitude, cap.longitude);
            // fprintf(fpNew, "ID = %d, Capital = %s, Latitude = %.2lf, Longtitude = %.2lf\n",
            //     cap.id, cap.name, cap.latitude, cap.longitude);
        }
    }

    fputc('\n', stdout);
    fputc('\n', fpNew);
    
    fclose(fpNew);
}