#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define P push
#define F first
#define S second
class Graph{
    private:
    unordered_map<int, list<int>> l;
    public:
    void addEdge(int x, int y)
    {
        l[x].pb(y);
        l[y].pb(x);
    }
    // Using bfs
    bool check_cycle_bfs(int src)
    {
          unordered_map<int, bool> visited;
          unordered_map<int, int> parent;
          queue<int> q;
          for(auto p : l)
          {
              int node = p.F;
              visited[node] = false;
              parent[node] = node;
          }
          visited[src] = true;
          
          q.P(src);
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              for(auto nbr : l[node])
              {
                  if(visited[nbr] && parent[node] != nbr)
                  {
                      return true;
                  }
                  else if(!visited[nbr])
                  {
                      q.push(nbr);
                      visited[nbr] = true;
                      parent[nbr] = node;
                  }
              }
          }
          return false;
    }
    bool dfs_helper(int src, unordered_map<int, bool>& visited, int parent)
    {
        visited[src] = true;
        for(auto nbr : l[src])
        {
            if(!visited[nbr])
            {
                bool cycle_mila = dfs_helper(nbr, visited, src);
                if(cycle_mila == true)
                {
                    return true;
                }
            }
            else if(parent != nbr)
            {
                return true;
            }
        }
        return false;
    }
    bool check_cycle_dfs()
    {
        unordered_map<int, bool> visited;
        for(auto p : l)
        {
            int node = p.F;
            visited[node] = false;
        }
        return dfs_helper(0, visited, -1);
    }
};
int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.addEdge(3, 0);
    cout << g.check_cycle_dfs();
    return 0;
}
