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
     void topological_sort_bfs()
     {
        int * indegree = new int[v] {0};
        
        // make the indegree
        for(int i = 0; i < v; i++)
        {
            for(auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        // push all those which have 0 indegree, means they are not
        // dependent on any node
        for(int i = 0; i < v; i++)
        {
            if(indegree[i] == 0)
            {
                   q.push(i);
            }
        }
       while(!q.empty())
       {
           int node = q.front();
           q.pop();
           cout << node << " ";
           for(auto nbr : l[node])
           {
               indegree[nbr]--;
               if(indegree[nbr] == 0)
               {
                   q.push(nbr);
               }
           }
       }
        
     }
};
int main() {
    Graph g(6);
    /*g.addEdge(3, 0);
    g.addEdge(3, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 4);
    g.addEdge(2, 5);*/
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.topological_sort_bfs();
    return 0;
}
