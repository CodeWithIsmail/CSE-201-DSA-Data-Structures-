#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void dfs(int current, int country, int visited[country], int graph[country][country], char name[][20], int temp)
{
    int i;
    if (temp)
        printf("%s\n", name[current]);
    else
        temp = 1;
    visited[current] = 1;

    for (i = 0; i < country; i++)
    {
        if (visited[i] == 0 && graph[current][i] == 1)
        {
            dfs(i, country, visited, graph, name, temp);
        }
    }
}
int main()
{
    int country, flight, i, j, start, temp = 0;
    printf("Enter number of country and flight:\n");
    scanf("%d %d", &country, &flight);

    char name[country][20], home[20];
    printf("Enter country name:\n");
    for (i = 0; i < country; i++)
        scanf("%s", name[i]);

    int visited[country], graph[country][country];
    for (i = 0; i < country; i++)
        visited[i] = 0;
    for (i = 0; i < country; i++)
        for (j = 0; j < country; j++)
            graph[i][j] = 0;

    printf("Enter flights:\n");
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
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    printf("Enter current country:\n");
    scanf("%s", home);
    for (i = 0; i < country; i++)
    {
        if (strcmp(name[i], home) == 0)
        {
            start = i;
            break;
        }
    }

    printf("\nVisited country:\n");
    dfs(start, country, visited, graph, name, temp);
}