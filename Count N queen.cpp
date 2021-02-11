#include <iostream>
using namespace std;
//int cnt = 0;
bool can_we_place(int board[12][12], int r, int c, int n)
{
    //row and col check
    
    for(int j = 0; j < r; j++)
    {
        if(board[j][c] == 1)
            return false;
    }
    //left diagonal
    int i = r, j = c;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
           return false;
        i--;
        j--;
    }
    i = r, j = c;
    while(i >= 0 && j < n)
    {
        if(board[i][j] == 1)
           return false;
        i--;
        j++;
    }
    return true;
}

int count_n_queen(int board[12][12], int i, int n)
{
       if(i == n)
       {

           //cnt++;
          /* for(int k = 0; k < n; k++)
           {
               for(int j = 0; j < n; j++)
               {
                   cout << board[k][j] << " ";
               }
               cout << endl;
           }
           cout << endl;*/
           return 1;
      }
      int ans = 0;
      for(int j = 0; j < n; j++)
      {
          if(can_we_place(board, i, j, n))
          {
              board[i][j] = 1;
              
              ans += count_n_queen(board, i + 1, n);
              
              board[i][j] = 0;
          }
      }
      return ans;

}

int main() {
    int n;
    cin >> n;
    int board[12][12] = {0};
    cout << count_n_queen(board, 0, n) << endl;
    return 0;
}
