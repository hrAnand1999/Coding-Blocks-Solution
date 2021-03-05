#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
    unordered_map<T, list<pair<T, int>>> l;
    unordered_map<T, list<T>> parent;
    public:
    void addEdge(T u, T v, int wt, bool bidrxn = true)
    {
        l[u].push_back({v, wt});
        if(bidrxn)
        {
            l[v].push_back({u, wt});
        }
    }
    void printAdj()
    {
        for(auto j : l)
        {
            cout << j.first << " -> " ;
            for(auto l : j.second)
            {
                cout << l.first << " " << l.second << " , ";
            }
            cout << endl;
        }
    }
    void dijsktra(T src)
    {
        unordered_map<T, int> dist;
        for(auto x : l)
        {
            dist[x.first] = INT_MAX;
        }
        dist[src] = 0;
        set<pair<int, T>> s; // first wt, second node...as set sort on basis of first ele
        s.insert({0, src});
        parent[src].push_back(src);
        while(!s.empty())
        {
            auto p = *(s.begin());
            s.erase(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            for(auto child : l[node])
            {
                if(nodeDist + child.second < dist[child.first])
                {
                    // update the parent
                    parent[child.first].clear();
                    for(auto path : parent[node])
                    {
                        parent[child.first].push_back(path);
                    }
                    parent[child.first].push_back(child.first);

                    T dest = child.first;
                    auto f = s.find({dist[dest], dest});
                    if(f != s.end())
                    {
                        s.erase(f);
                    }
                    // Insert the new pair
                    dist[dest] = nodeDist + child.second;
                    s.insert({dist[dest], dest});
                }
                
            }
        }
        // print dist to all nodes from src
        for(auto d : dist)
        {
            cout << d.first << " is located at " << d.second << endl;
        }
        cout << endl;
        // printing the parent
        for(auto p : parent)
        {
            cout << p.first << " -> ";
            for(auto x : p.second)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
int main() {
   Graph<int> g;
   g.addEdge(0, 1, 4);
   g.addEdge(0, 7, 8);
   g.addEdge(1, 7, 11);
   g.addEdge(2, 1, 8);
   g.addEdge(2, 8, 2);
   g.addEdge(8, 6, 6);
   g.addEdge(7, 6, 1);
   g.addEdge(7, 8, 7);
   g.addEdge(2, 3, 7);
   g.addEdge(3, 5, 14);
   g.addEdge(5, 6, 2);
   g.addEdge(2, 5, 4);
   g.addEdge(3, 4, 9);
   g.addEdge(5, 4, 10);
    // g.printAdj();
 g.dijsktra(0);
   return 0;
}
