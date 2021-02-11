#include <iostream>
using namespace std;
#define mod 1000000007
int sol(int n, int m, int *dp)
{
    if(n < m)
    {
        return dp[n] = 1;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }
    int ans = ( sol(n - m, m, dp) % mod + sol(n -1, m, dp) % mod) % mod;
    return dp[n] = ans;
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int dp[n + 1] = {0};
        cout << sol(n, m, dp) << endl;
    }
    return 0;
}
