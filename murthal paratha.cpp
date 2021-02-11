#include <iostream>
#include<climits>
using namespace std;
bool is_possible(int *a, int l, int p, int max_time)
{
    int cook, cnt_paratha = 0;
    for(int i = 0; i < l; i++)
    {
        cook = a[i];
        int fact = 1;
        int r = a[i];
        while(cook <= max_time)
        {
            fact++;
            cook += (r * fact);
            cnt_paratha ++;
            if(cnt_paratha == p)
            return true;
        }
        
    }
    return false;
}
int main() {
   int p, l;
   cin >> p >> l;
   int max_rank = INT_MIN;
   int a[l];
   for(int i = 0; i < l; i++)
   {
       cin >> a[i];
       max_rank = max(max_rank, a[i]);
   }
   int e = ((p * (p + 1)) / 2) * max_rank;
   int s = 0;
   int ans;
   while(s <= e)
   {
       int mid = (s + e) / 2;
       if(is_possible(a, l, p, mid))
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