#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 10005;
vector<int> graph[N];
set<int> art; // bcz it could be possible that node 2 has three leaf node 3, 4, 5...so 2 will come two times but we want only single yime thats why we used set
vector<pair<int, int>> bridge;
int lowest[N] = {0}, disc[N] = {0};
int tme;
void dfs(int curr, int parent)
{
    int no_of_child = 0;
    lowest[curr] = disc[curr] = tme++;
    for(auto child : graph[curr])
    {
        if(disc[child] == 0)
        {
            no_of_child++; // we increment inside if condn bcz we want to count child not all the the nodes connected from that node
            dfs(child, curr);
            lowest[curr] = min(lowest[curr], lowest[child]);
            // articulation point
            // we have to make separate case for root so we will not include root here
            if(parent != 0 && lowest[child] >= disc[curr])
            {
                art.insert(curr);
            }
            // bridge check
            if(lowest[child] > disc[curr])
            {
                bridge.pb({curr, child});
            }
        }
        else if(child != parent)
        {
            // backedge found
            lowest[curr] = min(lowest[curr], disc[child]);
        }
    }
    // separate case for root
    // bcz root doesn't have any edge above it, so how will it check
    // for root to be a articular point it must have child >= 2 then only removal of root and its corresponding edge will make more than one comp.
    if(parent == 0 && no_of_child >= 2)
    {
        art.insert(curr);
    }
    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i  = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    tme = 1;
    dfs(1, 0);
    cout << "Articulation point" << endl;
    for(auto x : art)
    {
        cout << x << " " ;
    }
    cout << endl;
    cout << "Bridges" << endl;
    for(auto x : bridge)
    {
        cout << x.first << " " << x.second << endl;
    }
}
int main() {
   solve();
}
