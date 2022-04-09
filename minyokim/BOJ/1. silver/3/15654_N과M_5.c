#include <stdio.h>
#include <stdlib.h>

int check[9], arr[9], input[9], N, M;

int compare(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    return (n1 - n2);
}

void func(int index)
{
    if (index == M + 1)
    {
        for (int i = 1; i <= M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (check[i] == 1)
            continue;
        arr[index] = input[i];
        check[i] = 1;
        func(index + 1);
        check[i] = 0;
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &input[i]);
    }

    qsort(input, N + 1, sizeof(int), compare);

    func(1);
}