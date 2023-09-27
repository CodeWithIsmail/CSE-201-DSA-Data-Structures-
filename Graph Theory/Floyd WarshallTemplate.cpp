#include <bits/stdc++.h>
typedef long long ll;
const ll inf = INT_MAX;
const ll N = 500;
ll shortestDistance[N][N];
using namespace std;

int main()
{
    ll n, m, i, j, k;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            i == j ? shortestDistance[i][j] = 0 : shortestDistance[i][j] = inf;
        }
    }

    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        shortestDistance[u][v] = w;
    }

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                shortestDistance[i][j] = min(shortestDistance[i][j], shortestDistance[i][k] + shortestDistance[k][j]);
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            shortestDistance[i][j] == inf ? cout << "I " : cout << shortestDistance[i][j] << " ";
        }
        cout << endl;
    }
}
