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

void pop()
{
	if (queue.start == -1)
		printf("-1\n");
	else if (queue.start == queue.end)
		{
			printf("%d\n", queue.arr[queue.start]);
			queue.start = -1;
			queue.end = -1;
		}
	else
	{
		printf("%d\n", queue.arr[queue.start]);
		queue.start = (queue.start + 1) % SIZE;
	}
}

void size()
{
	if (queue.start == -1)
		printf("0\n");
	else
		printf("%d\n", (SIZE + queue.end - queue.start + 1) % SIZE);
}

void empty()
{
	if (queue.start == -1)
		printf("1\n");
	else
		printf("0\n");
}

void front()
{
	if (queue.start == -1)
		printf("-1\n");
	else
		printf("%d\n", queue.arr[queue.start]);
}

void back()
{
	if (queue.end == -1)
		printf("-1\n");
	else
		printf("%d\n", queue.arr[queue.end]);
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
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(str, "pop") == 0)
			pop();
		else if (strcmp(str, "size") == 0)
			size();
		else if (strcmp(str, "empty") == 0)
			empty();
		else if (strcmp(str, "front") == 0)
			front();
		else if (strcmp(str, "back") == 0)
			back();
	}
}