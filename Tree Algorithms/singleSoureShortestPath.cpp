#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
vector<bool> vis(1001,false);
vector<int> dist(1001);
//single source shortest path (only applys for tree)
void dfs(int node, int distance)
{
    vis[node] = true;
    dist[node] = distance;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(!vis[adj[node][i]])
        {
            dfs(adj[node][i], dist[node] + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int e = n - 1;
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    int t, min_dis = INT_MAX, ans = -1;
    cin >> t;
    while(t--)
    {
        int girls;
        cin >> girls;
        if(dist[girls] < min_dis)
        {
            min_dis = dist[girls];
            ans = girls;
        }
        else if(dist[girls] == min_dis && girls < ans)
        {
            ans = girls;
        }
    }
    cout << ans << "\n";
}
