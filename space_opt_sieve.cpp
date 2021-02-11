#include <iostream>
#include<bitset>
using namespace std;
#define ll long long

const int n = 1000005;
bitset<1000005> b;
void prime_sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for(ll i = 2; i <= n; i++)
    {
        if(b[i])
        {
            for(ll j = i*i; j <= n; j += i)
            {
                b[j] = 0;
            }
        }
    }
}
int main() {
    prime_sieve();
    int q;
    cin >> q;
    while(q--)
    {
        int a, c;
        cin >> a >> c;
        int ans = 0;
        for(int i = a; i <= c; i++)
        {
            if(b[i] == 1)
            ans++;
        }
        cout << ans << endl;
    }
    
   
    return 0;
}
