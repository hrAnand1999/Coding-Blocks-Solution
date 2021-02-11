#include <iostream>
#include<climits>
using namespace std;
#define ll long long
bool is_possible(ll *a, ll n, ll k, ll max_time)
{
    ll carpentar = 1;
    ll board_paint = a[0];
    if(board_paint > max_time)
    return false;
    for(ll i = 1; i < n; i++)
    {
        if(board_paint + a[i] > max_time)
        {
            carpentar++;
            board_paint = a[i];
            if(carpentar > k)
            return false;
        }
        else
        {
            board_paint += a[i];
        }
    }
    return true;
}
int main() {
   ll k, n;
   cin >> k >> n;
   ll a[n];
   ll max_time = INT_MIN;
   ll sum  = 0;
   for(ll i = 0; i < n; i++)
   {
       cin >> a[i];
       sum += a[i];
       max_time = max(max_time, a[i]);
   }
   ll s = max_time;
   ll e = sum;
   ll ans;
   while(s <= e)
   {
       ll mid = (s + e)/2;
       if(is_possible(a, n, k, mid))
       {
           ans = mid;
           e = mid - 1;
       }
       else 
       {
           s = mid + 1;
       }
   }
   cout << ans << endl;
   return 0;
}
