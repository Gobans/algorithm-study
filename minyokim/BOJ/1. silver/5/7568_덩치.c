#include <stdio.h>

int compare(int x1, int x2, int y1, int y2)
{
    if (x1 > y1 && x2 > y2)
        return 1;
    return 0;
}

int main(void)
{
    int N;
    int arr[50][2];
    int order[50] = {0};

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (compare(arr[j][0], arr[j][1], arr[i][0], arr[i][1]) == 1)
                order[i]++;
        }
        printf("%d ", order[i] + 1);
    }
}