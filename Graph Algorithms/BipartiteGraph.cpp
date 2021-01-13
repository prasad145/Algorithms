#include<bits/stdc++.h>
using namespace std;
vector<int> adj[2001];
vector<bool> vis(2001);
int color[2001];

//two coloring method
//bipartite
bool dfs(int node, int c)
{
    vis[node] = true;
    color[node] = c;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(!vis[adj[node][i]])
        {
            bool ok = dfs(adj[node][i], c ^ 1);
            if(!ok)
                return false;
        }
        else
        {
            if(color[node] == color[adj[node][i]] ) //node on the same set have same colour then it voilates second rule of Biparitiegraph
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        int n, m;
        cin >> n >> m;
        
        for(int i = 1; i <= n; i++)
             adj[i].clear(), vis[i] = false;
        
        for(int i = 0; i < m ;i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool ok = false;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                bool res = dfs(i, 0);
                if(res == false)
                {
                    ok = true;
                   // break;
                }
            }
        }
       /* for(int x : color)
        {
            cout << x << " ";
        }
        printf("\n");*/
        cout << "Scenario #"<< tc <<":"<<"\n";
        if(ok){
            cout <<"Suspicious bugs found!"<<"\n";
        }
        else{
            cout <<"No suspicious bugs found!"<<"\n";
        }
    }
}
