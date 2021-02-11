#include <iostream>
#include<iomanip>//to look good
using namespace std;
const int D = 10;
int RowD[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int colD[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void print_board(int board[D][D], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool canPlace(int board[D][D], int n, int r, int c)
{
    return (r < n && r >= 0 && c < n && c >= 0 && board[r][c] == 0);
}
bool solveKnightProblem(int board[D][D], int move_taken, int n, int currRow, int currCol)
{
    if(move_taken == n*n)
        return true;//bcz it's proven that knight can travel n*n board in n*n min moves
    for(int drxn = 0; drxn < 8; drxn++)
    {
        int nextRow = currRow + RowD[drxn];
        int nextCol = currCol + colD[drxn];
        if(canPlace(board, n, nextRow, nextCol))
        {
            board[nextRow][nextCol] = move_taken + 1;
            bool is_success = solveKnightProblem(board, move_taken + 1, n, nextRow, nextCol);
            if(is_success)
                return true;
            board[nextRow][nextCol] = 0;
        }
    }
    return false;
}
int main() {
    int board[D][D] = {0};
    int n;
    cin >> n;
    board[0][0] = 1;
    int move_taken = 1;
    if(solveKnightProblem(board, move_taken, n, 0, 0))
    {
        print_board(board, n);
    }
    else
    cout << "Nahi ho paya" << endl;
    return 0;
}
