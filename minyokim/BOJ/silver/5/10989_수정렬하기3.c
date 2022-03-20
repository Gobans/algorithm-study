#include <stdio.h>
#include <stdlib.h>

int main_(void)
{
    int N;
    int *arr;
    int count[10000] = {0};

    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++)
        count[arr[i] - 1]++;
    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d\n", i + 1);

    return 0;
}

int main(void)
{
    int N;
    int num;
    int count[10000] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        count[num - 1]++;
    }
    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d\n", i + 1);

    return 0;
}