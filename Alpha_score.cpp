#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll merge(ll *a, ll s, ll e)
{
    ll mid = (s + e) /2;
    ll i = s, j = mid + 1, k = s;
    ll cnt = 0;
    ll temp[100005];
    while(i <= mid && j <= e)
    {
          if(a[i] < a[j])
          {
              temp[k++] = a[i];
              cnt = (cnt + ((e - j + 1) * a[i]) % mod) % mod;
              i++;
          }
          else
          {
              temp[k++] = a[j++];
          }
    }
    for(; i <= mid;)
    {
        temp[k++] = a[i++];
    }
    for(; j <= e; )
    {
        temp[k++] = a[j++];
    }
    for(int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
    return cnt;
}
ll alpha_score(ll *a, ll s, ll e)
{
    if(s >= e)
    return 0;
    ll mid = (s + e) /2;
    ll x = alpha_score(a, s, mid);
    ll y = alpha_score(a, mid + 1, e);
    ll z = merge(a, s, e);
    return (x + y + z) % mod;
}
int main() {
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << alpha_score(a, 0, n - 1) << endl;
    return 0;

}
