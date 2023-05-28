#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//done
/*
10 8
Greenland
China
India
Pakistan
Iran 
Bangladesh
Turkey
USA
Canada
Thailand
India
India China
Bangladesh Thailand
Pakistan India
USA Canada
Turkey Iran
Pakistan Iran
Pakistan Turkey
Bangladesh India
*/
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
int empty(struct queue *q)
{
    return q->f == q->r ? 1 : 0;
}
int main()
{
    int country, flight, i, j, start;

    printf("Enter number of country and flight:");
    scanf("%d %d", &country, &flight);

    char name[country][20], home[20];
    printf("Enter country name:\n");
    for (i = 0; i < country; i++)
        scanf("%s", name[i]);

    int graph[country][country], visited[country];
    for (i = 0; i < country; i++)
        for (j = 0; j < country; j++)
            graph[i][j] = 0;
    for (i = 0; i < country; i++)
        visited[i] = 0;

    printf("Enter all flight:\n");
    for (i = 0; i < flight; i++)
    {
        char a[20], b[20];
        int v1, v2;
        scanf("%s %s", a, b);
        for (j = 0; j < country; j++)
        {
            if (strcmp(name[j], a) == 0)
                v1 = j;
            if (strcmp(name[j], b) == 0)
                v2 = j;
        }
        graph[v1][v2] = graph[v2][v1] = 1;
    }

    printf("Enter current country:\n");
    scanf("%s", home);
    for (i = 0; i < country; i++)
    {
        if (strcmp(name[i], home) == 0)
            start = i;
    }

    struct queue q;
    q.size = country;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    visited[start] = 1;
    enqueue(&q, start);
    printf("\nVisited countries:\n");
    while (!empty(&q))
    {
        int current = dequeue(&q);
        for (i = 0; i < country; i++)
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