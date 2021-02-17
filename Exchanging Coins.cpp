#include <iostream>
#include<unordered_map>
using namespace std;
#define ll long long
unordered_map<ll, ll> m;
ll solve(ll n)
{
    if(n == 1)
        return 1;
    if(n == 0)
       return 0;
    if(m[n] != 0)
       return m[n];
    ll op1 = solve(n / 2) + solve(n / 3) + solve(n / 4);
    ll op2 = n;
    return m[n] = max(op1, op2);
}
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
