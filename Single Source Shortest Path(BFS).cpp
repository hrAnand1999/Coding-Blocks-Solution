#include <bits/stdc++.h>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class Graph{
    private:
    int v;
    map<T, list<int>> l;
    public:
    Graph(int v)
    {
        this -> v = v;
        
    }
    void addEdges(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src)
    {
        map<T, int> dist;
        queue<T> q;
        for(auto x : l)
        {
            T node = x.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;
        q.push(src);
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto nbrs : l[node])
            {
                if(dist[nbrs] == INT_MAX)
                {
                    dist[nbrs] = dist[node] + 1;
                    q.push(nbrs);
                }
            }
        }
        for(auto x : l)
        {
            T node = x.first;
            int d = dist[node];
            cout << "Node : " << node << " dist : " << d << '\n';
        }
    }
};
int main() {
    Graph<int> g(6);
    g.addEdges(0,1);
    g.addEdges(0, 3);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(4, 3);
    g.addEdges(4,5);
    g.bfs(0);
    return 0;
}
