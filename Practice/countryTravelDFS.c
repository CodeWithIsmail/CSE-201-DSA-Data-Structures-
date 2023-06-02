#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int index(int n, char name[n][20], char find[20])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(find, name[i]) == 0)
            return i;
    }
    return -1;
}
void dfs(int n, int visited[n], int graph[n][n], int current)
{
    visited[current] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && graph[current][i] == 1)
            dfs(n, visited, graph, i);
    }
}
int main()
{
    int n, m, i, x, y;
    printf("Enter number of country and route:\n");
    scanf("%d %d", &n, &m);

    int visited[n], graph[n][n];
    char name[n][20];
    memset(visited, 0, sizeof(visited));
    memset(graph, 0, sizeof(graph));

    printf("Enter country name:\n");
    for (i = 0; i < n; i++)
        scanf("%s", name[i]);

    printf("Enter the route:\n");
    while (m--)
    {
        char v1[20], v2[20];
        scanf("%s", v1);
        scanf("%s", v2);
        x = index(n, name, v1);
        y = index(n, name, v2);
        graph[x][y] = graph[y][x] = 1;
    }

    printf("Enter starting:\n");
    char temp[20];
    scanf("%s", temp);
    int start = index(n, name, temp);
    dfs(n, visited, graph, start);

    printf("Visited country:\n");
    for (i = 0; i < n; i++)
    {
        if (i != start && visited[i] == 1)
            printf("%s\n", name[i]);
    }
}