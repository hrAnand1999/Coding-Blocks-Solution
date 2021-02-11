#include <iostream>
using namespace std;
#define ll long long int
ll min_cost(ll n, ll x, ll y, ll z)
{
    ll dp[n + 1] = {0};
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            dp[i] = min(dp[i/2] + x, dp[i - 1] + y);
        }
        else
        {
            dp[i] = min(dp[i - 1] + y, dp[(i + 1)/2] + x + z);
        }
    }
    return dp[n];
}
int main() {
    ll n;
    cin >> n;
    ll x, y, z;
    cin >> x >> y >> z;
    cout << min_cost(n, x, y, z) << endl;
    return 0;
}
