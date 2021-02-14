#include <iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class Graph{
   private:
   map<T, list<T>> m;
   public:
   void addEdge(T x, T y)
   {
       m[x].push_back(y);
       m[y].push_back(x);
   }
   int bfs(T src, T dest)
   {
         queue<T> q;
         q.push(src);
         map<T, T> parent;
         map<T, int> dist;
         parent[src] = src;
         for(auto x : m)
         {
             dist[x.first] = INT_MAX;
         }
         dist[src] = 0;
         while(!q.empty())
         {
             T node = q.front();
             q.pop();
             for(auto nbrs : m[node])
             {
                 if(dist[nbrs] == INT_MAX)
                 {
                     q.push(nbrs);
                     dist[nbrs] = dist[node] + 1;
                     parent[nbrs] = node;
                 }
             }
         }
         T temp = dest;
         while(temp != src)
         {
             cout << temp << " <-- ";
             temp = parent[temp];
         }
         cout << src;
         cout << endl;
         return dist[dest];
   }
};
int main() {
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;

    // Adding all the edges
    for(int i = 0; i <= 36; i++)
    {
        for(int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if(j <= 36)
            g.addEdge(i, j);
        }
    }
    
    cout << g.bfs(0, 36);
    return 0;
}
