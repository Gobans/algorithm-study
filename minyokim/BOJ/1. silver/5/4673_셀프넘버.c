#include <stdio.h>

int self_num(int *count, int n)
{
    int sum = n;
    int store;

    while (sum < 10000)
    {
        store = sum;
        while (store)
        {
            sum += store % 10;
            store = store / 10;
        }
        count[sum]++;
    }
}

int main(void)
{

    int count[50000] = {0};
    for (int i = 1; i <= 9972; i++)
    {
        self_num(count, i);
    }

    for (int i = 1; i < 10000; i++)
    {
        if (count[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}
