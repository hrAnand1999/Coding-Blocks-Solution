#include <bits/stdc++.h>
using namespace std;
int m, n;
int minPath = INT_MAX;
bool isSafe(int r, int c, vector<vector<int>>& path)
{
    if(r < 0 || r >= m || c < 0 || c >= n || path[r][c] == 0)
    return false;
    return true;
}
void fun(int row, int col, vector<vector<int>>& path, int ans)
{
    //   base case
    if(col == n - 1)
    {
        minPath = min(minPath, ans);
        return;
    }
    if(ans > minPath)
    return;
    if(row < 0 || row >= m || col < 0 || col >= n || path[row][col] == 0)
    return;
    path[row][col] = 0;
    if(isSafe(row - 1, col, path))
    {
        fun(row - 1, col, path, ans + 1);
    }
    if(isSafe(row + 1, col, path))
    {
        fun(row + 1, col, path, ans + 1);
    }
    if(isSafe(row, col - 1, path))
    {
        fun(row, col - 1, path, ans + 1);
    }
    if(isSafe(row, col + 1, path))
    {
        fun(row, col + 1, path, ans + 1);
    }
    path[row][col] = 1;
}
int findShortest(vector<vector<int>>& path)
{
    // mark all position near to 0 as unsafe
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(path[i][j] == 0)
            {
                if(j - 1 >= 0)
                path[i][j - 1] = -1;
                if(j + 1 < n)
                path[i][j + 1] = -1;
                if(i - 1 >= 0)
                path[i - 1][j] = -1;
                if(i + 1 < m)
                path[i + 1][j] = -1;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(path[i][j] == -1)
            path[i][j] = 0;
        }
        
    }
    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << setw(3) << path[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int row = 0; row < m; row++)
    {
        int ans = 0;
        if(path[row][0] != 0)
        {
            fun(row, 0, path, ans);
        }

    }
    return minPath == INT_MAX ? -1 : minPath;
}
int main() {
   cin >> m >> n;
   vector<vector<int>> path(m, vector<int>(n));
   for(int i = 0; i < m; i++)
   {
       for(int j = 0; j < n; j++)
       {
           cin >> path[i][j];
       }
   }
   cout << findShortest(path);
   return 0;

}
