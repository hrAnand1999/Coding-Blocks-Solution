#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool is_subset(ll n, ll target, ll *a)
{
    bool dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for(int j = 1; j <= target; j++)
    {
        dp[0][j] = false;
    }
    dp[0][0] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= target; j++)
        {
            if(a[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i]]);
            }
        }
    }
    return dp[n][target];
}
int main() {
   ll n;
   ll sum;
   cin >> n >> sum;
   ll a[n + 1];
   for(int i = 1; i <= n; i++)
   {
       cin >> a[i];
   }
   if(is_subset(n, sum, a))
   {
       cout << "Yes" << endl;
   }
   else
   {
       cout << "No" << endl;
   }
   return 0;
}
