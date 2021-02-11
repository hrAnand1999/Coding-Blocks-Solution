#include <iostream>
#include<cmath>
using namespace std;
bool canWePlace(int sudoku[][9], int i, int j, int n, int number)
{
    for(int x = 0; x < n; x++)
    {
        if(sudoku[i][x] == number || sudoku[x][j] == number)
        {
            return false;
        }
    }
    //grid check
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    for(int i = sx; i < sx + 3; i++)
    {
        for(int j = sy; j < sy + 3; j++)
        {
            if(sudoku[i][j] == number)
            return false;
        }
    }
    return true;
}
bool sudoku_solver(int sudoku[][9], int i, int j, int n)
{
     if(i == n)
     {
         for(int i = 0; i < n; i++)
         {
             for(int j = 0; j < n; j++)
             {
                 cout << sudoku[i][j] << " ";
             }
             cout << endl;
         }
         cout << endl;
         return true;
     }
     //other cases
     if(j == n)
     {
         return sudoku_solver(sudoku, i + 1, 0, n);
     }
     if(sudoku[i][j] != 0)
     {
         return sudoku_solver(sudoku, i, j + 1, n);
     }
     //rec case
     for(int number = 1; number <= n; number++)
     {
         if(canWePlace(sudoku, i, j, n, number))
         {
             sudoku[i][j] = number;
             bool sol = sudoku_solver(sudoku, i, j + 1, n);
             if(sol == true)
             {
                 return true;
             }
         }
     }
     //backtracking
     sudoku[i][j] = 0;
     return false;
}
int main() {
    int n;
    cin >> n;
    int sudoku[9][9];
    for(int i  = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    sudoku_solver(sudoku, 0, 0, n);
}

