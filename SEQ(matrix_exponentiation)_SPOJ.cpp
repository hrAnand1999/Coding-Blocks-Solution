#include <iostream>
#include<vector>
using namespace std;
#define ll long long
#define MOD 1000000000
ll k;
vector<ll> a, b, c;


vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    //logic to multiply matrices
    vector<vector<ll>> C(k + 1, vector<ll>(k + 1));
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            for(int x = 1; x <= k; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}


vector<vector<ll>> pow(vector<vector<ll>> A, ll p)
{
    //calculating power using fast exponentiation

    //base case
    if(p == 1)
    return A;

    // if p is odd
    if(p & 1)
    return multiply(A, pow(A, p - 1));
    vector<vector<ll>> X = pow(A, p / 2);
    return multiply(X, X);
}


ll compute(ll n)
{
    if( n == 0 )
    return 0;
    if( n <= k )
    return b[n - 1];
    //otherwise
    // use matrix exponentiation
    // 1 based indexing thats why we have taken k+1

    //step 1
    vector<ll> F1(k + 1);
    for(int i = 1; i <= k; i++)
    {
        F1[i] = b[i - 1];
    }

    //step 2
    //create Transformation matrix
    vector<vector<ll>> T(k + 1, vector<ll>(k + 1));
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(i < k)
            {
                //fills 0's and 1's
                if(j == i + 1)
                T[i][j] = 1;
                else
                T[i][j] = 0;
            }
            else
            {
                T[i][j] = c[k - j];
            }
        }
    }

    //step 3
    T = pow(T, n - 1);

    //step 4
    ll res = 0;
    for(int i = 1; i <= k; i++)
    {
        res = (res + (T[1][i] * F1[i]) % MOD) % MOD;
    }
    return res;
}
int main() {
    ll t, n, num;
    cin >> t;
    while(t--)
    {
         cin >> k;
         for(int i = 0; i < k; i++)
         {
             cin >> num;
             b.push_back(num);
         }
         for(int i = 0; i < k; i++)
         {
             cin >> num;
             c.push_back(num);
         }
         cin >> n;
         cout << compute(n) << endl;
         c.clear();
         b.clear();
    }
}
