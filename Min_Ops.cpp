#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n, a, b; cin >> a >> b >> n; int A[n];
	for (int i=0; i<n; i++) cin >> A[i];

	queue<int> q; vector<bool> vis(1000001, 0); vector<int> dist(1000001, 0);
	q.push(a); vis[a] = 1;

	while(not q.empty())
	{
		int curr_node = q.front();
		q.pop();

		if (b == curr_node)
		{
			cout << dist[curr_node] << '\n';
			return 0;
		}

		// neighbors of curr_node
		for (int i=0; i<n; i++)
		{
			int val = curr_node * A[i];

			// we will also not push the values greater than end
			if (vis[val] or val > b) continue;

			q.push(val); vis[val] = 1;
			dist[val] = dist[curr_node] + 1;
		}
	}
	cout << -1 << '\n';
}