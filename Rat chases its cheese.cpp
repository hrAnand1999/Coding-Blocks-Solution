#include <iostream>
using namespace std;

bool rat_chaes_its_cheese(char grid[15][15], int n, int m, int i, int j, int out[15][15])
{
    if(i == n - 1 && j == m - 1)
    {
        out[i][j] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << out[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if(grid[i][j] == 'X')
        return false;
    if(i >= n || j >= m || i < 0 || j < 0)
        return false;
    out[i][j] = 1;
    bool right_success, left_success , down_success, up_success ;
    if(out[i][j + 1] == 0)
    {
        right_success = rat_chaes_its_cheese(grid, n, m, i, j + 1, out);
        if(right_success == true)
            return true;
    }
    if(out[i][j - 1] == 0 && !right_success)
    {
        left_success = rat_chaes_its_cheese(grid, n, m, i, j - 1, out);
        if(left_success == true)
           return true;
    }
    if(out[i - 1][j] == 0 && !right_success && !left_success)
    {
        up_success = rat_chaes_its_cheese(grid, n, m, i - 1, j, out);
        if(up_success == true)
            return true;
    }
    if(out[i + 1][j] == 0 && !right_success && !left_success && !up_success)
    {
        down_success = rat_chaes_its_cheese(grid, n, m, i + 1, j, out);
        if(down_success == true)
             return true;
    }
    out[i][j] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    char grid[15][15];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int out[15][15] = {0};
    bool temp = rat_chaes_its_cheese(grid, n, m, 0, 0, out);
    if(!temp)
    {
        cout << "NO PATH FOUND" << endl;
    }
    return 0;
}
