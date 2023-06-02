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
int index(int n, char name[n][20], char find[20])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(find, name[i]) == 0)
            return i;
    }
    return -1;
}
int main()
{
    int n, m, i, x, y;
    scanf("%d %d", &n, &m);
    int indegree[n], graph[n][n];
    char name[n][20];

    memset(indegree, 0, sizeof(indegree));
    memset(graph, 0, sizeof(graph));

    for (i = 0; i < n; i++)
        scanf("%s", name[i]);
    while (m--)
    {
        char v1[20], v2[20];
        scanf("%s", v1);
        scanf("%s", v2);
        x = index(n, name, v1);
        y = index(n, name, v2);
        indegree[y]++;
        graph[x][y] = 1;
    }

    struct queue q;
    q.f = q.r = -1;
    q.size = n;
    q.arr = (int *)malloc(q.size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        if (!indegree[i])
            enqueue(&q, i);
    }
    while (q.f != q.r)
    {
        int current = dequeue(&q);
        printf("%s\n", name[current]);
        for (i = 0; i < n; i++)
        {
            if (graph[current][i])
            {
                indegree[i]--;
                if (!indegree[i])
                    enqueue(&q, i);
            }
        }
    }
}