#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f, r, size, *arr;
};
// 1. Empty check
int empty(struct queue *q)
{
    return q->f == q->r;
}
// 2. Full Check
int full(struct queue *q)
{
    return q->r == q->size - 1;
}
// 3. Enqueue
void enqueue(struct queue *q, int value)
{
    if (full(q))
        printf("Queue is full\n");
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}
// 4. Dequeue
int dequeue(struct queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}
// 5. Display
void display(struct queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}
int main()
{
    struct queue q;
    q.f = q.r = -1;
    q.size = 5;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("%d\n", full(&q));
    enqueue(&q, 10);
    enqueue(&q, 16);
    enqueue(&q, 18);
    enqueue(&q, 87);
    enqueue(&q, 90);
    printf("%d\n", empty(&q));
    printf("%d\n", full(&q));
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
}