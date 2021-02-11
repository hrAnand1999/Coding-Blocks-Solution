#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000003;

ll dp[105][105][2];
ll solve(ll i, ll n, ll k, int prev)
{
    if(i == n)
    {
        return (k == 0) ? 1 : 0;
    }
    if(dp[i][k][prev] != -1)
    {
        return dp[i][k][prev];
    }
    ll ans = 0;
    if(prev == 1)
    {
        ans = (ans + solve(i + 1, n, k - 1, 1)) % mod;
    }
    else
    {
        ans = (ans + solve(i + 1, n, k, 1)) % mod;
    }
    ans = (ans + solve(i + 1, n, k, 0)) % mod;
    return dp[i][k][prev] = ans;
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        ll ans = (solve(1, n, k, 1) + solve(1, n, k, 0)) % mod;
        cout << ans << endl;
    }
    return 0;
}
