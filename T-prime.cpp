#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1000000;
bitset<100000005> b;
vector<int> primes;
unordered_map<ll, bool > m;

void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for(ll i = 2; i <= N; i++)
    {
        if(b[i])
        {
             primes.pb(i);
             for(ll j = i*i; j <= N; j += i)
             {
                 b[j] = 0;
             }
        }
    }
    for(auto x : primes)
    {
        m[x * (ll)x] = true;
    }
}
int main() {
    sieve();
    int n;
    cin >> n;
    ll num;
    for(int i = 0; i < n; i++)
    {
         cin >> num;
         if(m[num])
         {
             cout << "YES" << endl;
         }
         else
         cout << "NO" << endl;
    }
     
    return 0;
}
