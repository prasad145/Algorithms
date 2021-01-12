#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
vector<bool> visited(100, false);
void dfs(int node)
{
    visited[node] = (true);
    cout << node << " ";
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(visited[adj[node][i]] == false)
        {
            dfs(adj[node][i]);
        }
    }
    printf("\n");
}


int main()
{
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= nodes; i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
            connectedComponents++;
        }
    }

    cout << "Number of connected components are:" << connectedComponents <<endl;
    return 0;
}
