#include<bits/stdc++.h>
using namespace std;
//to be a tree it should have single connected graph, it should not have any cycle
// number nodes = n , then edges should be = n - 1 
vector<int> adj[10001];
vector<bool> vis(10001, false);

void dfs(int node)
{
    vis[node] =  true;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(!vis[adj[node][i]])
        {
            dfs(adj[node][i]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int edge = m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int connectedComponents = 0;
    for(int i = 1; i <=n; i++)
    {
        if(!vis[i])
        {
            connectedComponents++;
            dfs(i);
        }
    }

    if(connectedComponents == 1 && edge == n - 1)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
    return 0;
    
}
