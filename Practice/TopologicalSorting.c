#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue
{
    int size, f, r, *arr;
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
    int n, m, i, x, y;
    scanf("%d %d", &n, &m);

    int indegree[n + 1], graph[n + 1][n + 1];
    memset(indegree, 0, sizeof(indegree));
    memset(graph, 0, sizeof(graph));

    while (m--)
    {
        scanf("%d %d", &x, &y);
        indegree[y]++;
        graph[x][y] = 1;
    }

    struct queue q;
    q.f = q.r = -1;
    q.size = n;
    q.arr = (int *)malloc(q.size * sizeof(int));
    
    for (i = 1; i <= n; i++)
    {
        if (!indegree[i])
            enqueue(&q, i);
    }
    while (q.f != q.r)
    {
        int current = dequeue(&q);
        printf("%d ", current);
        for (i = 1; i <= n; i++)
        {
            if (graph[current][i])
            {
                indegree[i]--;
                if (!indegree[i])
                {
                    enqueue(&q, i);
                }
            }
        }
    }
}