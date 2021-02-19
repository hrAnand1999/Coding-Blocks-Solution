#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll knapsack(ll n, int c, ll *size, ll *value)
{
    ll dp[n + 1][c + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 1; j <=c; j++)
    {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            ll inc = 0, exc = 0;
            if(j >= size[i - 1])
            {
                inc = value[i - 1] + dp[i - 1][j - size[i - 1]];
            }
            exc = dp[i - 1][j];
            dp[i][j] = max(inc, exc);
        }
    }
    return dp[n][c];
}
int main() {
    ll n, c;
    cin >> n >> c;
    ll size[n], value[n];
    for(int i = 0; i < n; i++)
    {
        cin >> size[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout <<knapsack(n, c, size, value) << endl;
    return 0;
}
