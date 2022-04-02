typedef struct s_queue //큐 구조체
{
    int que[1000];
    int front;
    int rear;
    int num;
} Queue;

Queue q;

void InitQue(Queue *q)
{
    q->front = q->rear = q->num = 0;
}

int EnQue(Queue *q, int x)
{
    if (q->num == 1000)
        return -1;
    else
    {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == 1000)
            q->rear = 0;
    }

    return 0;
}

int DeQue(Queue *q, int *x)
{
}