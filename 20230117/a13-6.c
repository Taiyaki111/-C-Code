#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct point {
    double x;
    double y;
    double z;
};


double calc_distance(struct point *p)
{
    return sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}

int main(int argc, char *argv[])
{
    struct point *points;
    int i, num, memorySize;
    double dist;

    if (argc != 2) {
        fprintf(stderr, "Usage: a.out num2\n");
        exit(1);
    }
    
    num = atoi(argv[1]);
    if (num <= 0) {
        fprintf(stderr, "Error: %d is not positive\n", num);
        exit(1);
    }
    
    memorySize = sizeof(struct point) * num;
    if ((points = (struct point*) malloc(memorySize)) == NULL) {
        fprintf(stderr, "Error: Cannnot allocate memory %d bytes.\n", memorySize);
        exit(1);
    }

    for (i = 0; i < num; i++) {
        fprintf(stdout, "x y z:");
        fscanf(stdin, "%lf%lf%lf", &points[i].x, &points[i].y, &points[i].z);
    }

    for (i = 0; i < num; i++) {
        dist = calc_distance(&points[i]);
        fprintf(stdout, "(%.3lf, %.3lf, %.3lf): distance = %.3lf\n",
                points[i].x, points[i].y, points[i].z, dist);
    }

    free(points);
    return 0;

}