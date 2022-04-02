#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int C;
    int N;
    int avg;
    float percent;
    int **arr;

    scanf("%d", &C);
    arr = (int **)malloc(sizeof(int *) * C);

    for (int i = 0; i < C; i++)
    {
        avg = 0;
        percent = 0;
        scanf("%d", &N);
        arr[i] = (int *)malloc(sizeof(int) * N);

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
            avg += arr[i][j];
        }
        avg /= N;

        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] > avg)
                percent += 1;
        }
        percent = (percent / N) * 100;
        printf("%.3f%%\n", percent);
    }

    return 0;
}