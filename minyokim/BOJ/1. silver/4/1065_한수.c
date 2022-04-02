#include <stdio.h>

int arr[4];

int intlen(int n)
{
    int i = 0;
    int len = 0;

    while (n)
    {
        arr[i] = n % 10;
        n /= 10;
        i++;
        len++;
    }

    return len;
}

int main(void)
{
    int N;
    int len;
    int count = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        len = intlen(i + 1);
        if (len == 1)
            count++;
        else if (len == 2)
            count++;
        else if (len == 3)
        {
            if ((arr[0] - arr[1]) == (arr[1] - arr[2]))
                count++;
        }
    }

    printf("%d", count);
}