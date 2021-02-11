#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
#define ll long long
ll find_idx(ll *a, ll n, ll key)
{
    ll s = 0;
    ll e = n - 1;
    while(s <= e)
    {
        ll mid = (s + e) / 2;
        if(a[mid] == key)
        return mid;
        else if(a[mid] < key)
        {
            s = mid + 1;
        }
        else
        e = mid - 1;
    }
    return -1;
}
void compute(ll *a, ll n, ll m)
{
      ll min_diff = INT_MAX;
      ll rose_1, rose_2;
      for(ll i = 0; i < n; i++)
      {
          ll x = a[i];
          ll y = m - a[i];
          int j = find_idx(a, n, y);
          if((i != j) && (j >=0 && j<n)  &&  (abs(x - y) < min_diff))
          {
              rose_1 = x;
              rose_2 = y;
              min_diff = abs(x - y);
          } 
         
      }
      ll x = rose_1, y = rose_2;
      rose_1 = min(x, y);
      rose_2 = max(x, y);
      cout << "Deepak should buy roses whose prices are " << rose_1 << " and " << rose_2 <<"."<< endl;
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
        ll m;
        cin >> m;
        string str;
        getline(cin, str);
        sort(a, a + n);
        compute(a, n, m);
    }
    return 0;
}
