#include <iostream>
using namespace std;
#define ll long long
ll no_of_ways(ll n, ll *dp)
{
    if(n < 2)
    {
        return dp[n] = 1;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }
    ll ans = no_of_ways(n - 1, dp) + (n - 1) * no_of_ways(n - 2, dp);
    return dp[n] = ans;
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll dp[n + 1] = {0};
        cout << no_of_ways(n, dp) << endl;

    }
    return 0;
}
