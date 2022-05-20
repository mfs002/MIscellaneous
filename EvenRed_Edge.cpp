#include <bits/stdc++.h>
using namespace std;

// 0 -> red, 1 -> blue
// NoteBook Question  ->>  EVENRED EDGE

signed main()
{
	int n, m; cin>>n>>m;
    vector<int> G[2*n+1];
    for (int i=0; i<m; i++)
    {
        int x, y, c; cin>>x>>y>>c;
        if (c==1)
        {
            G[x].push_back(y);
            G[y].push_back(x);
            G[x+n].push_back(n+y);
            G[y+n].push_back(x+n);
        }
        else
        {
            G[x].push_back(y+n);
            G[y+n].push_back(x);
            G[x+n].push_back(y);
            G[y].push_back(x+n);
        }
    }
    int src, dest; cin>>src>>dest;

    for (int i=1; i<=2*n; i++) sort(G[i].begin(), G[i].end());

    // just do normal BFS
    int dist[2*n+1]; memset(dist, -1, sizeof dist);
    queue<int> qu; qu.push(src);
    dist[src] = 0;
    
    while(not qu.empty())
    {
        int c_n = qu.front();
        qu.pop();

        if (c_n == dest)
        {
            cout << "Can Reach\n";
            return 0;
        }

        for (auto nb : G[c_n])
        {
            if (dist[nb] == -1)
            {
                dist[nb] = dist[c_n] + 1;
                qu.push(nb);
            }
        }
    }
    cout << "Can't reach\n";
}