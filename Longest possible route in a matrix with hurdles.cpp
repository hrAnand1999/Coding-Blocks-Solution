#include <bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
bool isSafe(int i, int j, vector<vector<int>>& board, int m, int n)
{
    if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 0 || board[i][j] == -1)
    return false;
    return true;
}
void fun(int i, int j, int x, int y, vector<vector<int>>& board, int m, int n, int path)
{
     if(i == x && j == y)
     {
         ans = max(ans, path);
         return;
     }
     if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 0 || board[i][j] == -1)
     return;
     board[i][j] = -1;
     if(isSafe(i + 1, j, board, m, n))
     {
         fun(i + 1, j, x, y, board, m, n, path + 1);
     }
     if(isSafe(i - 1, j, board, m, n))
     {
         fun(i - 1, j, x, y, board, m, n, path + 1);
     }
     if(isSafe(i, j + 1, board, m, n))
     {
         fun(i, j + 1, x, y, board, m, n, path + 1);
     }
    if(isSafe(i, j - 1, board, m, n))
    {
        fun(i, j - 1, x, y, board, m, n, path + 1);
    }
    board[i][j] = 1;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    fun(0, 0, x, y, board, m, n, 0);
    if(ans == INT_MIN)
    cout << "solution dosen't exist" << endl;
    else
    cout << ans << endl;
    
    return 0;
}
