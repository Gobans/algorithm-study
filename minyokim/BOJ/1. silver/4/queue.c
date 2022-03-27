#include <stdio.h>
#include <string.h>

#define SIZE 2000000

typedef struct s_queue
{

    int arr[SIZE];
    int start;
    int end;

} t_queue;

t_queue queue;

void push(int n)

{

    if (queue.start == -1)

    {

        queue.start = 0;

        queue.end = 0;

        queue.arr[0] = n;
    }

    else
    {

        queue.end = (queue.end + 1) % SIZE;

        queue.arr[queue.end] = n;
    }
}

void pop()

{

    if (queue.start == -1)

        return;

    else if (queue.start == queue.end)

    {

        queue.start = -1;

        queue.end = -1;
    }

    else

    {

        queue.start = (queue.start + 1) % SIZE;
    }
}

int size()

{

    if (queue.start == -1)

        return 0;

    else

        return (SIZE + queue.end - queue.start + 1) % SIZE;
}

int empty()

{

    if (queue.start == -1)

        return 1;

    else

        return 0;
}

int front()

{

    if (queue.start == -1)

        return -1;

    else

        return queue.arr[queue.start];
}

int back()

{

    if (queue.end == -1)

        return -1;

    else

        return queue.arr[queue.end];
}
