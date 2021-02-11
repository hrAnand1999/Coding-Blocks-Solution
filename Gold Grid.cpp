#include <iostream>
#include<climits>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int grid[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }
    int x, y;
    for(int i = 0; i < m; i++)
    {
          cin >> x >> y;
          grid[x - 1][y - 1] = 1;
    }
    //col wise addition
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            grid[i][j] += grid[i][j - 1];
        }
    }
    //row wise addition
    for(int i = 1; i < n; i++)
    {
            for(int j = 0; j < n; j++)
            {
                grid[i][j] += grid[i - 1][j];
            }
    }
    /*for(int i = 0; i < n; i++)
    {
        for(int j  = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }*/
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
               int op1, op2, op3, op4;
               op1 = grid[i][j];
               op2 = grid[i][n-1] - op1;
               op3 = grid[n-1][j] - op1;
               op4 = grid[n-1][n-1] - (op1 + op2 + op3);
               ans = max(ans, min(op1, min(op2, min(op3, op4))));
        }
    }
    cout << ans << endl;
    return 0;
}
