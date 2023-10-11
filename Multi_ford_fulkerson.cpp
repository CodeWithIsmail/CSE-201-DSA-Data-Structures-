#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 510;
ll graph[mx][mx], pre[mx];
bool visited[mx];
ll v, e, source, sink;
ll max_flow = 0;

bool bfs()
{
    queue<ll> q;
    memset(visited, false, sizeof(visited));
    q.push(source);
    visited[source] = true;
    pre[source] = -1;

    while (!q.empty())
    {
        ll current = q.front();
        q.pop();
        for (ll i = 0; i <= v + 1; i++)
        {
            if (!visited[i] && graph[current][i])
            {
                q.push(i);
                visited[i] = true;
                pre[i] = current;
            }
        }
    }

    return visited[sink];
}
void ford_ful()
{
    while (bfs())
    {
        ll min_cap = INT_MAX;
        ll temp = sink;
        while (pre[temp] != -1)
        {
            min_cap = min(min_cap, graph[pre[temp]][temp]);
            temp = pre[temp];
        }
        max_flow += min_cap;
        temp = sink;
        while (pre[temp] != -1)
        {
            graph[pre[temp]][temp] -= min_cap;
            graph[temp][pre[temp]] += min_cap;
            temp = pre[temp];
        }
    }
}
int main()
{
    //  freopen("ford.txt","r",stdin);
    ll i, j;
    cin >> v >> e;
    ll sSource = v, sSink = v + 1;
    source = sSource, sink = sSink;
    // source=1,sink=v;
    // source = 0, sink = v-1;
    // cin >> source >> sink;
    for (i = 0; i < e; i++)
    {
        ll u, v, cap;
        cin >> u >> v >> cap;
        graph[u][v] = cap;
    }

    ll num_source, num_sink;
    cin >> num_source >> num_sink;
    for (i = 0; i < num_source; i++)
    {
        ll x;
        cin >> x;
        graph[sSource][x] = INT_MAX;
    }
    for (i = 0; i < num_sink; i++)
    {
        ll x;
        cin >> x;
        graph[x][sSink] = INT_MAX;
    }

    // for(i=0; i<v; i++)
    // {
    //     for(j=0; j<v; j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ford_ful();
    cout << max_flow;
}
