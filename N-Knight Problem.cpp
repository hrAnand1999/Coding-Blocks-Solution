#include <iostream>
using namespace std;

const int N = 100;
int cnt = 0;

int RowD[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int colD[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void print_board(int board[N][N], int n)
{
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            
            if(board[i][j]){
                cout<<"{"<<i<<"-"<<j<<"}"<<" ";
            }
        }
    }
    cout<<" ";
}

bool canPlace(int board[N][N], int n, int r, int c)
{
       for(int i = 0; i < 8; i++)
       {
           if(r + RowD[i] >= n || r + RowD[i] < 0 || c + colD[i] >= n || c + colD[i] < 0)
                continue;
           if(board[r + RowD[i]][c + colD[i]] == 1)
                 return false;
       }
       return true;
}

bool N_knight(int board[N][N], int knight_placed,int n, int i, int j)
{
    if(knight_placed == n)
    {
        cnt++;
        print_board(board, n);
        return false;
    }
    if(i == n)
    {
        return false;
    }
    if(j == n)
    {
        return N_knight(board, knight_placed, n, i+1, 0);
    }
    if(canPlace(board, n, i, j))
    {
        board[i][j] = 1;
        bool next_Knight = N_knight(board, knight_placed + 1, n, i, j + 1);
        if(next_Knight == true)
            return true;
        board[i][j] = 0;
    }
     return N_knight(board, knight_placed, n, i, j + 1);
     return false;
    
}
int main() {
    int board[N][N] = {0};
    int n;
    cin >> n;
    int knight_placed = 0;
    N_knight(board, knight_placed, n, 0, 0);
    cout << endl << cnt ;
    return 0;
}
