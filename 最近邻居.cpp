#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
struct xy
{
    double x;
    double y;
};

/* 计算两点距离的函数 */
static inline double get_dist(const struct xy *p1, const struct xy *p2)
{
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

void get_closest(const struct xy points[], unsigned int n, unsigned int result[2])
{
    /* 在这里补充代码, 注意，要求result[0] < result[1] */
    
    result[0] = 0;
    result[1] = 1;
}

int main(void) 
{ 
    unsigned int result[2]; 
    struct xy *points; 
    unsigned int n; 
    unsigned int i; 

    scanf("%u\n", &n); 
    points = (struct xy *)malloc(n * sizeof (struct xy)); 

    for (i = 0; i < n; i++) 
        scanf("%lf %lf\n", &points[i].x, &points[i].y); 

    get_closest(points, n, result); 

    printf("Closest points: %u, %u\n", result[0], result[1]);
    system("pause");
    return 0; 
}
