#include <iostream>
using namespace std;
char maze[1005][1005];
int soln[1005][1005] = {0};
bool rat_in_a_maze(int i, int j, int n, int m)
{
    if(i == n && j == m)
    {
        soln[i][j] = 1;
        for(int k = 1; k <= n; k++)
        {
            for(int l = 1; l <= m; l++)
            {
                cout << soln[k][l] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if(maze[i][j] == 'X')
         return false;
    if(i > n || j > m)
         return false;
    soln[i][j] = 1;
    bool rightsuccess = false, downsuccess = false;
    rightsuccess = rat_in_a_maze(i, j + 1, n, m);
    if(!rightsuccess)
    {
        downsuccess = rat_in_a_maze(i + 1, j, n, m);
    }
    soln[i][j] = 0;
    if(rightsuccess || downsuccess)
    return true;
    return false;
}
int main() {
   int n, m;
   cin >> n >> m;
   for(int i = 1; i <= n; i++)
   {
       for(int j = 1; j <= m; j++)
       {
           cin >> maze[i][j];
       }
   }
   bool ans = rat_in_a_maze(1, 1, n, m);
   if(!ans)
   {
       cout << -1 << endl;
   }
   return 0;
}
