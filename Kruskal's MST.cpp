#include <bits/stdc++.h>
using namespace std;
class DSU{
    private:
    int *parent;
    int *rank;
    public:
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for(int i = 0; i < v; i++)
        {
            rank[i] = 1;
            parent[i] = -1;
        }
    }
    int find(int i)
    {
        if(parent[i] == -1)
            return i;
        int ans = find(parent[i]);
        parent[i] = ans;
        return ans;
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2)
        {
            if(rank[s1] > rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};
class Graph{
    private:
    vector<vector<int>> l;
    int v;
    public:
    Graph(int v)
    {
         this->v = v;
    }
    void addEdges(int wt, int x, int y)
    {
         l.push_back({wt, x, y});
    }
    int kruskals_mst()
    {
        DSU dsu(v);
        sort(l.begin(), l.end());
        int ans = 0;
        for(auto edge : l)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            int s1 = dsu.find(x);
            int s2 = dsu.find(y);
            if(s1 != s2)
            {
                dsu.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};
int main() {
   Graph g(5);
   g.addEdges(1, 0, 1);
   g.addEdges(2, 0, 2);
   g.addEdges(2, 1, 2);
   g.addEdges(2, 0, 3);
   g.addEdges(3, 1, 3);
   g.addEdges(3, 2, 3);
   g.addEdges(6, 3, 4);
   cout << g.kruskals_mst();
   return 0;
}
