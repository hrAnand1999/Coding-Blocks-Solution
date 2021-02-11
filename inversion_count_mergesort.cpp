#include <iostream>
using namespace std;
#define ll long long
ll merge(ll *a, ll s, ll e)
{
    ll temp[100005];
    ll k = s;
    ll mid = (s + e)/2;
    ll cnt = 0;
    ll i = s, j = mid + 1;
    while(i <= mid && j <= e)
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else {
           temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    for(; i <= mid; i++)
    {
        temp[k++] = a[i];
    }
    for(; j <= e; j++)
    {
        temp[k++] = a[j];
    }
    for(int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
    return cnt;
}
ll inversion_count(ll *a, ll s, ll e)
{
    if(s >= e)
    return 0;
    ll mid = (s + e)/2;
    ll x = inversion_count(a, s, mid);
    ll y = inversion_count(a, mid + 1, e);
    ll z = merge(a, s, e);
    return x + y + z;
}
int main() {
   ll t;
   cin >> t;
   while(t--)
   {
       ll n;
       cin >> n;
       ll a[n];
       for(int i = 0; i < n; i++)
       {
           cin >> a[i];
       }
       cout << inversion_count(a, 0, n - 1) << endl;
   }
   return 0;
}
