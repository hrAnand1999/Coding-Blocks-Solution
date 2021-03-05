#include <bits/stdc++.h>
#include<queue>
using namespace std;
#define P pair<int, int>
#define pb push_back
class Graph{
    private:
    int v;
    vector<P> *l;
    public:
    Graph(int v)
    {
        this->v = v;
        l = new vector<P>[v];
    }
    void addEdges(int wt, int y, int x)
    {
        l[x].pb({y, wt});
        l[y].pb({x, wt});
    }
    int prims_mst()
    {
        bool *visited = new bool[v] {0};
        priority_queue<P, vector<P>, greater<P>> q;//we want min based on wt, so the first elem of pair will be wt
        
        q.push({0, 0}); // wt, elem
        int ans = 0;
        while(!q.empty())
        {
            auto best = q.top();
            q.pop();
            int wt = best.first;
            int edge = best.second;
            if(!visited[edge])
            {
                 ans += wt;
                 visited[edge] = true;
                 for(auto nbr : l[edge])
                 {
                     if(!visited[nbr.first])
                     {
                         q.push({nbr.second, nbr.first});
                     }
                 }
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
    // g.addEdges(6, 3, 4);
    cout << g.prims_mst();
    return 0;
}
