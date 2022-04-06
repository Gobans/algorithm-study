#include <stdio.h>

void func(int index, int arr[10])
{
    if (index == 3)
    {
        for (int i = 0; i < 3; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    int i;
    for (i = 1; i < 10; i++)
    {
        arr[index] = i;
        func(index + 1, arr);
    }
}

int main()
{
    int arr[10];

    func(0, arr);
}