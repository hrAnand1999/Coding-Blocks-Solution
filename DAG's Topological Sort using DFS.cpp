#include <bits/stdc++.h>
using namespace std;
class Graph{
     private:
     int v;
     list<int> *l;
     public:
     Graph(int v)
     {
         this->v = v;
         l = new list<int>[v];
     }
     void addEdge(int x, int y)
     {
         l[x].push_back(y);
     }
     void dfs_helper(int *visited, list<int> & q, int src)
     {
         visited[src] = 1;
         for(auto nbr : l[src])
         {
             if(!visited[nbr])
             {
                 dfs_helper(visited, q, nbr);
             }
         }
         q.push_front(src);
     }
     void topological_sort_dfs()
     {
         int* visited = new int[v] {0};
         list<int> q;
         for(int i = 0; i < v; i++)
         {
             if(!visited[i])
             {
                 dfs_helper(visited, q, i);
             }
         }
        //  printing the items in topological sorted order
        for(auto node : q)
        {
            cout << node << " ";
        }
     }
};
int main() {
    Graph g(6);
    g.addEdge(3, 0);
    g.addEdge(3, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.topological_sort_dfs();
    return 0;
}
