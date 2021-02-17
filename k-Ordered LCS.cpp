#include <bits/stdc++.h>
#include<string>
using namespace std;
int dp[2002][2002][7];
int n, m;
int a[2002], b[2002];
int LCS(int i, int j, int k)
{
      if(i == n || j == m)
         return 0;
      if(dp[i][j][k] != -1)
      {
          return dp[i][j][k];
      }
      int ans = 0;
      if(a[i] == b[j])
      {
          ans = 1 + LCS(i + 1, j + 1, k);
      }
      else
      {
          int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN; 
          if(k > 0)
          {
               op1 = 1 + LCS(i + 1, j + 1, k - 1);
               
          }
              op2 = LCS(i + 1, j, k);
              op3 = LCS(i, j + 1, k);
         ans = max(op1, max(op2, op3));
        }
        return dp[i][j][k] = ans;
}
int main() {
    int k;
    cin >> n >> m >> k;
   
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    int res = LCS(0, 0, k);
    cout << res << endl;
    return 0;
}
