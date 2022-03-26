#include <stdio.h>
#include <string.h>

#define SIZE 2000000

typedef struct s_queue {
	int arr[SIZE];
	int start;
	int end;
}t_queue;

t_queue queue;

void push(int n)
{
	if (queue.start == -1)
	{
		queue.start = 0;
		queue.end = 0;
		queue.arr[0] = n;
	}
	else {
		queue.end = (queue.end + 1) % SIZE;
		queue.arr[queue.end] = n;
	}
}

int pop()
{
	int value;
	if (queue.start == -1)
	{
		return -1;
	}
	else if (queue.start == queue.end)
	{
		value = queue.arr[queue.start];
		queue.start = -1;
		queue.end = -1;
	}
	else
	{
		value = queue.arr[queue.start];
		queue.start = (queue.start + 1) % SIZE;
	}
	return value;
}

int size()
{
	if (queue.start == -1)
		printf("0\n");
	else
		return (SIZE + queue.end - queue.start + 1) % SIZE;
}


void front()
{
	if (queue.start == -1)
		printf("-1\n");
	else
		printf("%d\n", queue.arr[queue.start]);
}


int main()
{
	queue.start = -1;
	queue.end = -1;

	char str[100];
	int n;
	int num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		push(i + 1);
	if (size() == 1)
	{
		printf("1");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		pop();
		num = pop();
		push(num);
		if (size() == 1)
		{
			front();
			return 0;
		}
	}
}