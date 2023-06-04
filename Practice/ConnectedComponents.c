#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void dfs(int n, int visited[n + 1], int graph[n + 1][n + 1], int current)
{
    printf("%d ", current);
    visited[current] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && graph[current][i] == 1)
            dfs(n, visited, graph, i);
    }
}
int main()
{
    int n, m, x, y, i, count = 0;
    scanf("%d %d", &n, &m);
    int visited[n + 1], graph[n + 1][n + 1];
    memset(visited, 0, sizeof(visited));
    memset(graph, 0, sizeof(graph));

    while (m--)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }
    printf("Connected components:\n");
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(n, visited, graph, i);
            printf("\n");
        }
    }
    printf("Number of Connected components: %d", count);
}