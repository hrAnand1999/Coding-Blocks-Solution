#include<iostream>
#include<vector>
using namespace std;
#define pb push_back
#define ll long long

const int N = 100000;
vector<int> primes;
int p[N + 1] = {};

void sieve()
{
    for(ll i = 2; i <= N; i++)
    {
        if(!p[i])
        {
            primes.pb(i);
            for(ll j = i*i; j <= N; j+=i)
            {
                p[j] = 1;
            }
        }
    }
}
int main() {
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> m >> n;
        bool segment[n - m + 1];
        for(int i = 0; i < n - m + 1; i++)
        {
            segment[i] = 0;
        }
        //segment sieve logic
        for(auto x : primes)
        {
            if(x*x > n)
            break;

            int start = (m / x)*x;
            if(x >= m && x <= n)
            {
                start = 2*x;
            }
            for(int i = start; i <= n; i+=x)
            {
                
                segment[i - m] =1;
            }
        }
        for(int i = m; i <= n; i++)
        {
            if(segment[i - m] == 0 && i != 1)
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}
