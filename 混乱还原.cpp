#include <stdlib.h>

void shuffle(int a[], size_t n, unsigned int seed)
{
    srand(seed);
    for (; n > 1; n--)
    {
        unsigned int r = rand() % n;
        int tmp = a[n - 1];
        a[n - 1] = a[r];
        a[r] = tmp;
    }
}

void restore(int a[], size_t n, unsigned int seed)
{
    /* 在这里补充代码 */
    
}

/* 测试程序 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    unsigned int seed;
    unsigned int n;
    unsigned int i;
    int *a, *b;

    scanf("%u", &seed);
    scanf("%u", &n);

    a = (int *)malloc(sizeof *a * n);
    b = (int *)malloc(sizeof *b * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    shuffle(a, n, seed);
    restore(a, n, seed);

    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            break;
    }

    if (i == n)
        printf("Success!\n");
    else
        printf("Failed!\n");

    free(a);
    free(b);
    return 0;
}
