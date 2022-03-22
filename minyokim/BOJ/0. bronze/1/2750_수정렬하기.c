#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int N;
    int *arr;

    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for (int i = N - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return 0;
}