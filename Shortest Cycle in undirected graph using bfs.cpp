#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> graph[N];
void bfs(int src, int n, int &ans)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto nbr : graph[node])
        {
            if(dist[nbr] == INT_MAX)
            {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
            else if(dist[nbr] >= dist[node])
            {
                ans = min(ans, dist[nbr] + dist[node] + 1);
            }
        }
    }
}
void solve()
{
    int n, m, i, j, ans;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    ans = n + 1;
    for(i = 1; i <= n; i++)
    {
        bfs(i, n, ans);
    }
    if(ans == n + 1)
    {
        cout<< "No cycle" << endl;
    }
    else
    cout << "short length - " << ans << endl;
}
int main() {
    solve();
    return 0;
}
