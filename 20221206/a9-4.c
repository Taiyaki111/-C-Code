#include <stdio.h>
#include <math.h>

/* a9-4data */
#define SHOP_NUM 9
#define NAME_NAX 20

struct point {
int x;
int y;
};

struct shop {
    char *name;
    int type;
    struct point place;
};

char *Shopnames[SHOP_NUM] = {
"Musashiya", "Hamatora", "Hidakaya", "Mybasket", "Tokyustore",
"Inageya", "Sundrug", "Yamasakiya", "Okuokastore"
};

int Types[SHOP_NUM] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
struct point Places[SHOP_NUM] = {
{5, 5}, {7, 11}, {1, 2}, {11, 3}, {0, 1}, {6, 9}, {2, 7}, {5, 4}, {8, 1}
};

double calc_distance(struct point a, struct point b);
void make_shop_data(struct shop *sp, char *name, int type, struct point p);

main()
{
    int i, target, min_shop_num;
    double min_distance = __DBL_MAX__, distance;
    struct shop shops[SHOP_NUM];
    struct point current_loc;

    // make data
    for (i = 0; i < SHOP_NUM; i++) {
        make_shop_data(&shops[i], Shopnames[i], Types[i], Places[i]);
    }

    // input
    printf("Current location: ");
    scanf("%d %d", &(current_loc.x), &(current_loc.y));
    printf("Type of shops: ");
    scanf("%d", &target);

    for (i = 0; i < SHOP_NUM; i++) {
        if (shops[i].type == target) {
            distance = calc_distance(shops[i].place, current_loc);
            if (min_distance > distance){
                min_distance = distance;
                min_shop_num = i;
            }
        }
    }

    printf("The nearest shop is %s\nDistance: %.3f\n", shops[min_shop_num].name, min_distance);


    return 0;
}

double calc_distance(struct point a, struct point b)
{
    double square1, square2;

    square1 = (double)(a.x - b.x) * (double)(a.x - b.x);
    square2 = (double)(a.y - b.y) * (double)(a.y - b.y);

    return sqrt(square1 + square2);
}

void make_shop_data(struct shop *sp, char *name, int type, struct point p)
{
    sp->name = name;
    sp->type = type;
    sp->place = p;
}
