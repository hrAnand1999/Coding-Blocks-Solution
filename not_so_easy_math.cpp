#include <iostream>
using namespace std;
#define ll long long
int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
ll cntbits(ll n)
{
    ll cnt = 0;
    while(n)
    {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}
ll multiply(ll n)
{
    ll denm = 1;
    for(ll i = 0; i < 8; i++){
        if(n & 1)
        {
            denm *= primes[i];
        }
        n >>= 1;
    }
    return denm;
}
void solve(ll n){
    int ans = 0;
    
    for(ll i = 1; i <= 1<<8 - 1; i++)
    {
         ll setbits = cntbits(i);
         ll denm = multiply(i);
         if(setbits & 1)
         {
             ans += (n/denm);
         }
         else
         {
             ans -= (n/denm);
         }
    }
    cout << ans << endl;
}
int  main() {
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}
