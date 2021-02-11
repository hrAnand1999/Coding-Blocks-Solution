#include <iostream>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long
#define pb push_back

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for(ll i = 2; i <= n; i++)
    {
        if(b[i])
        {
            primes.pb(i);
            for(ll j = i*i; j <= n; j+=i)
            {
                b[j] = 0;
            }
        }
    }
}
int main() {
    sieve();
    int no;
    cin >> no;
    int cnt = 0;
    int ans;
    for(int i = 0; i <= n; i++)
    {
        if(b[i] == 1)
        {
            cnt++;
            if(cnt == no)
            {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
}
