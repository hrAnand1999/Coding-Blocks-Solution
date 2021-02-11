#include <iostream>
using namespace std;
int opt_game(int *a, int n)
{
    int dp[1000][1000] = {0};
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            if(gap == 0)
            {
                dp[i][j] = a[i];
            }
            else if(gap == 1)
            {
                dp[i][j] = max(a[i], a[j]);
            }
            else{
                int op1 = a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int op2 = a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(op1, op2);
            }
        }
    }
    return dp[0][n - 1];
}
int main() {
    int n;
   cin >> n;
   int a[n];
   for(int i = 0; i < n; i++)
   {
       cin >> a[i];
   }
   
   cout << opt_game(a, n) << endl;
   return 0;
}
