#include <iostream>
#include<algorithm>
using namespace std;
bool is_possible(int *a, int n, int c, int min_gap)
{
       int curr_stall = a[0];
       int cow = 1;
       for(int i = 1; i < n; i++)
       {
           if(a[i] - curr_stall >= min_gap)
           {
               cow++;
               curr_stall = a[i];
               if(cow == c)
               return true;
           }
          
           
       }
       return false;
}
int main() {
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int s = 0;
    int e = a[n - 1] - a[0];
    int ans;
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(is_possible(a, n, c, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
