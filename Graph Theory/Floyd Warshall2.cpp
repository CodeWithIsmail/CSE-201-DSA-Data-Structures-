#include<bits/stdc++.h>
using namespace std;

const int mx=200;
int graph[mx][mx];
int dist[mx][mx];
int P[mx][mx];
map<string,int>in;
vector<string>name;
int s;


void fw()
{
    int i,j,k;
    for(i=1; i<=s; i++)
    {
        for(j=1; j<=s; j++)
        {
            dist[i][j]=graph[i][j];
           // if(i==j) dist[i][j]=0;
           // else dist[i][j]=graph[i][j];
        }
    }

    for(k=1; k<=s; k++)
    {
        for(i=1; i<=s; i++)
        {
            for(j=1; j<=s; j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j] && dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
}

void p_init()
{
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=s; j++)
        {
            if(i==j || graph[i][j]==INT_MAX)
                P[i][j] = -1;
            else if(i!=j && graph[i][j]<INT_MAX)
                P[i][j] = i;
        }
    }
}
void PrintPath(int s,int t)

{
    if(P[s][t]==-1)
    {
        cout<<"no path ";
        return;
    }

    else if (P[s][t]==s)
    {
        cout<<name[s-1]<<" ";
    }

    else
    {
        PrintPath(s,P[s][t]);
        PrintPath(P[s][t], t);
    }
}
int main()
{
    int i,j,k;
    freopen("fw.txt","r",stdin);
    int edge;
    cin>>edge;
    for(i=1; i<=mx; i++)
    {
        for(j=1; j<=mx; j++)
        {
            graph[i][j]=INT_MAX;
        }
    }
    for(i=0; i<edge; i++)
    {
        string a,b;
        int w;
        cin>>a>>b>>w;
        //      cout<<in[a]<<" ";
        if(in[a]==0)
        {
            name.push_back(a);
            in[a]=name.size();
        }
        if(in[b]==0)
        {
            name.push_back(b);
            in[b]=name.size();
        }
        if(in[a]==in[b]) graph[in[a]][in[b]]=0;
        else graph[in[a]][in[b]]=w;


        //  cout<<a<<" "<<b<<" "<<w<<endl;


    }
    string start,en;
    cin>>start>>en;
    int u=in[start],v=in[en];
    cout<<u<<" "<<v<<endl;


    s=in.size();
    p_init();
     for(i=1; i<=s; i++)
      {
          cout<<name[i]<<" ";
      }
      cout<<endl;

    for(i=1; i<=s; i++)
    {
        for(j=1; j<=s; j++)
        {
              cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }

    fw();
    cout<<endl;
    for(i=1; i<=s; i++)
    {
        for(j=1; j<=s; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    PrintPath(u, v);
    cout<<name[v-1];
}
