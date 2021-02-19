#include <bits/stdc++.h>
#include<list>
using namespace std;
class Graph{
    private:
    int v;
    list<pair<int, int>> *l;
    public:
    Graph(int V)
    {
        v = V + 1;
        l = new list<pair<int, int>>[v];
    }
    void addEdge(int x, int y, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }
    int dfs_helper(int node, bool *visited, int *count, int & ans)
    {
        //    mark the current node as visited
        visited[node] = true;
        count[node] = 1;
        for(auto nbr_pair : l[node])
        {
               int nbr = nbr_pair.first;
               int wt = nbr_pair.second;
               if(!visited[nbr])
               {
                   count[node] += dfs_helper(nbr, visited, count, ans);
                   int nx = count[nbr];
                   int ny = v - 1 - nx;
                   ans += 2 * min(nx, ny) * wt;
               }
        }
        // Just before you return the count of node
        return count[node];
    }
    int dfs()
    {
        bool *visited = new bool[v + 1] ;
        int *count = new int[v + 1] ;
        for(int i =0; i <= v; i++)
        {
            visited[i] = false;
            count[i] = 0;
        }
        int ans = 0;
        dfs_helper(1, visited, count, ans);
        return ans;
    }
    
};
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int v;
        cin >> v;
        Graph g(v);
        for(int e = 0; e < v - 1; e++)
        {
            int x, y, wt;
            cin >> x >> y >> wt;
            g.addEdge(x, y, wt);
        }
       int ans = g.dfs();
       cout << "Case #" << i <<": " << ans << endl;
    }
    /*Graph g(4);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(4, 3, 2);
    cout << g.dfs() ;*/
    return 0;
}
