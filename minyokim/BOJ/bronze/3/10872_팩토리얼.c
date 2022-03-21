#include <stdio.h>

int factorial(int N)
{
    int result = N;

    if (N == 1 || N == 0)
        return 1;
    return (result * factorial(N - 1));
}
int main(void)
{
    int N;

    scanf("%d", &N);
    printf("%d", factorial(N));

    return 0;
}