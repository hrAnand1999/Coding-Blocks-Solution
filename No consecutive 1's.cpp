#include <iostream>
using namespace std;
#define ll long long
ll count_outcomes(ll n, ll *dp)
{
    if(n < 0)
       return 0;
    if(n < 2)
    {
        return dp[n] = n + 1;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }
    ll ans = count_outcomes(n - 1, dp) + count_outcomes(n - 2, dp);
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
       cout << count_outcomes(n, dp) << endl;

   }
   return 0;
}
