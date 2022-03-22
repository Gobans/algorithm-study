#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    char *arr;
    int result = 0;

    scanf("%d", &num);

    arr = (char *)malloc(sizeof(char) * num);
    scanf("%s", arr);

    for (int i = 0; i < num; i++)
    {
        result += arr[i] - '0';
    }

    printf("%d", result);
}