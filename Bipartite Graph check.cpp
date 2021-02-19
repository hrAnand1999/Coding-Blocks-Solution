#include <bits/stdc++.h>
using namespace std;
bool dfs_helper(vector<int> graph[], int node, int *visited, int color, int parent)
{
    visited[node] = color;
    for(auto nbr : graph[node])
    {
        if(visited[nbr] == 0)
        {
            bool subProb = dfs_helper(graph, nbr, visited, 3 - color, node);  // 3 - color => if color == 1 , next call color = 3 - 1 = 2(next colour) simulatenously other case
            if(subProb == false)
            {
                return false;
            }
        }
        else if(parent != nbr && visited[nbr] == color)
        {
            return false;
        }
    }
    return true;
}
bool dfs(vector<int> graph[], int n)
{
    // we have to make two array one is visited and other is what's the colour of prev. 
    // Instead of making two arraya we'll construct a single array and define three states.
    int visited[n] = {0};  // 0 - Not visited   1 - visited colour is 1    2 - visited colour is 2
    int color = 1;
    int parent = -1 ;// parent of 0 assumed

    bool ans = dfs_helper(graph, 0, visited, color, parent);
    // To print the colour
    for(int i = 0; i < n; i++)
    {
        cout << i << " -color " << visited[i] << endl;
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(dfs(graph, n))
    {
        cout << "Yes! it's Bipartite" << '\n';
    }
    else
    {
        cout << "No! it's not a Bipartite" << '\n';
    }
    return 0;
}
