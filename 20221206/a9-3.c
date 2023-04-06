#include <stdio.h>
#include <math.h>

#define NUM_OF_POINTS 4

struct point{
    int x;
    int y;
};

double calc_distance(struct point a, struct point b);

main()
{
    struct point p[NUM_OF_POINTS];
    struct point base;
    int i, min_num;
    double min_distance = __DBL_MAX__, distance;

    for (i = 0; i < NUM_OF_POINTS; i++) {
        printf("point[%d]: ", i);
        scanf("%d %d", &(p[i].x), &(p[i].y));
    }

    printf("base point: ");
    scanf("%d %d", &(base.x), &(base.y));

    for (i = 0; i < NUM_OF_POINTS; i++) {
        distance = calc_distance(p[i], base);
        if (min_distance > distance){
            min_distance = distance;
            min_num = i;
        }
    }

    printf("Minimum: point[%d] (distance: %.3f)\n", min_num, min_distance);

    return 0;
}

double calc_distance(struct point a, struct point b)
{
    double square1, square2;

    square1 = (double)(a.x - b.x) * (double)(a.x - b.x);
    square2 = (double)(a.y - b.y) * (double)(a.y - b.y);

    return sqrt(square1 + square2);
}