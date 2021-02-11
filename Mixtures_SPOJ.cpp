#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long int
#define mod 100
ll dp[1000][1000];
ll a[1000];
ll csum[1000];
/*void prefix_sum(int n)
{
   csum[0] = a[0];
   for(int i = 1; i < n; i++)
   {
       csum[i] = (csum[i - 1] + a[i]) % mod;
   }
}*/
/*ll solveMixtures(int n)
{
    // For len 1
    for(int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    // for higher len
    for(int len = 2; len < n; len++)
    {
        for(int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++)
            {
                int l_sum = ((i == 0) ? csum[k] : (csum[k] - csum[i - 1]));
                int r_sum = ((k + 1 == 0) ? csum[j] : (csum[j] - csum[k]));
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + l_sum*r_sum);
            }
        }
    }
    return dp[1][n - 1];
}*/
ll sum(int s, int e)
{
    ll ans = 0;
    for(int i = s; i <= e; i++)
    {
          ans = (ans + a[i]) % mod;
    }
    return ans;
}
ll solveMixtures(int i, int j)
{
    if(i >=j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    ll ans = LONG_MAX;
    for(int k = i; k < j; k++)
    {
        //    int l_sum = ((i == 0) ? csum[k] : (csum[k] - csum[i - 1]));
        //    int r_sum = ((k + 1 == 0) ? csum[j] : (csum[j] - csum[k]));
           ans = min(ans, solveMixtures(i, k) + solveMixtures(k + 1, j) + sum(i, k)*sum(k + 1, j));
    }
    return dp[i][j] = ans;
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
               cin >> a[i];
        }
        memset(csum, 0, sizeof(csum));
        memset(dp, -1, sizeof(dp));
        // prefix_sum(n);
        cout << solveMixtures(0, n - 1) << endl;
    }
    return 0;
}
