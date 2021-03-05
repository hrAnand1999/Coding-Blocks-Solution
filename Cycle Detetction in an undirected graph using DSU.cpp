#include <bits/stdc++.h>
using namespace std;
class Graph{
    private:
    int v;
    list<pair<int, int>> l;   //edge list
    public:
    Graph(int v)
    {
        this->v = v;
    }
    void addEdge(int x, int y)
    {
        l.push_back(make_pair(x, y));     // edge x -> y   & y -> x
    }
    int find_set(int i, int *parent)
    {
        // doing path compression optimisation
        if(parent[i] == -1)
        {
            return i;
        }
        int ans =  find_set(parent[i], parent);
        parent[i] = ans;
        return ans;
    }
    void Union_set(int x, int y, int *parent, int *rank)
    {
        // union by rank optimisation
        int s1 = find_set(x, parent);
        int s2 = find_set(y, parent);
        if(s1 != s2)
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    bool is_cycle()
    {
         int *parent = new int[v];
         int *rank = new int[v];
         for(int i = 0; i < v; i++)
         {
             parent[i] = -1;
             rank[i] = 1;
         }
         for(auto p : l)
         {
             int x = p.first;
             int y = p.second;
             int s1 = find_set(x, parent);
             int s2 = find_set(y, parent);
             
             if(s1 != s2)
             {
                 
                 Union_set(x, y, parent, rank);
             }
             else
             return true;
         }
         delete []parent;
         delete []rank;
         return false;
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.addEdge(3, 0);
    if(g.is_cycle())
    {
        cout << "Yes";
    }
    else
    cout << "No" ;
    return 0;
}
