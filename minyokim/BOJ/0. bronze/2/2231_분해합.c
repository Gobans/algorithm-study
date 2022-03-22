#include <stdio.h>

int bucket[1000000];

int ft_bucket(int n)
{
    int sum = n;
    int temp = n;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    if (sum <= 1000000 && bucket[sum - 1] == 0)
        bucket[sum - 1] = temp;
}

int main(void)
{
    int N;

    scanf("%d", &N);
    for (int i = 1; i < 1000000; i++)
        ft_bucket(i);

    printf("%d", bucket[N - 1]);
}