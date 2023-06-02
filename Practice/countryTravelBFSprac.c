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
    int n, m, i;
    scanf("%d %d", &n, &m);

    int visited[n], graph[n][n];
    char name[n][20];
    memset(visited, 0, sizeof(visited));
    memset(graph, 0, sizeof(graph));

    printf("Enter country name:\n");
    for (i = 0; i < n; i++)
        scanf("%s", name[i]);

    printf("Enter route:\n");
    while (m--)
    {
        char v1[20], v2[20];
        scanf("%s", v1);
        scanf("%s", v2);
        int x = index(n, name, v1);
        int y = index(n, name, v2);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    printf("Enter starting:\n");
    char temp[20];
    scanf("%s", temp);
    int start = index(n, name, temp);

    struct queue q;
    q.f = q.r = -1;
    q.size = n;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, start);
    visited[start] = 1;
    while (q.f != q.r)
    {
        int current = dequeue(&q);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && graph[current][i] == 1)
            {
                enqueue(&q, i);
                visited[i] = 1;
                printf("%s\n", name[i]);
            }
        }
    }
}