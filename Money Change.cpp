#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007;
#define ll long long int



int no_of_ways(int n, int m, int *coins)
{
    ll dp[m + 1][n + 1];
    for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            dp[i][j]=0;
        }
    for(int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }
    /*for(int j = 1; j <= n; j++)
    {
        dp[0][j] = 0;
    }*/
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            // ll inc = 0, exc = 0;
            if(j >= coins[i - 1])
            {
                // inc = dp[i][j - coins[i - 1]];
                dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i - 1]]) % mod;
            }
            // exc = dp[i - 1][j];
            // dp[i][j] = (inc + exc) % mod;
            else
            dp[i][j] = dp[i - 1][j] % mod;
        }
    }
    /*for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    return dp[m][n];
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
          int n, m;
          cin >> m;
          int coins[m];
          for(int i = 0; i < m; i++)
          {
              cin >> coins[i];
          }
          cin >> n;
        //    sort(coins, coins + m);
          cout << no_of_ways(n, m, coins) << endl;
    }
    return 0;
}
