#include <bits/stdc++.h>
using namespace std;
class Graph{
    private:
    int v;
    list<int> * l;
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
    bool cycle_helper(int src, bool *visited, bool *stack)
    {
        visited[src] = true;
        stack[src] = true;
        for(auto nbr : l[src])
        {
            if(!visited[nbr])
            {
                bool cycle_mila = cycle_helper(nbr, visited, stack);
                if(cycle_mila == true)
                {
                    return true;
                }
            }
            else if(stack[nbr] == true)
            {
                return true;
            }
        }
        stack[src] = false;
        return false;
    }
    bool is_cycle()
    {
         bool *visited = new bool[v] {0};
         bool *stack = new bool[v] {0};
         return cycle_helper(0, visited, stack);
    }
};
int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    if(g.is_cycle())
    {
        cout << "Yes" << endl;
    }
    else
    cout << "No" << endl;
    return 0;
}
