#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue
{
    int f, r, size, *arr;
};
void enqueue(struct queue *q, int value)
{
    q->r++;
    q->arr[q->r] = value;
}
int dequeue(struct queue *q)
{
    q->f++;
    return q->arr[q->f];
}
int main()
{
    int n, m, x, y, i, start;
    scanf("%d %d", &n, &m);
    int graph[n + 1][n + 1], visited[n + 1];
    memset(visited, 0, sizeof(visited));
    memset(graph, 0, sizeof(graph));

    while (m--)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    struct queue q;
    q.f = q.r = -1;
    q.size = n;
    q.arr = (int *)malloc(q.size * sizeof(int));

    scanf("%d", &start);
    enqueue(&q, start);
    visited[start] = 1;
    while (q.f != q.r)
    {
        int current = dequeue(&q);
        for (i = 1; i <= n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                enqueue(&q, i);
                printf("%d ", i);
                visited[i] = 1;
            }
        }
    }
}