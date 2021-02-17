#include <iostream>
#include<climits>
#include<queue>
using namespace std;
int low_idx = 0;
int solve(int *a, int n, int k)
{
    if(n == 1)
    {
        if(k == 1)
           return 1;
        return ((a[0] == 0) ? 0 : 1);
    }
    int l = 0, r = 0;
    int zero_cnt = 0;
    
    int max_len = INT_MIN;
    while(r < n)
    {
        if(a[r] == 1)
        {
            if(r -l + 1 > max_len)
            {
               low_idx = l;
              
                
                max_len = r -l + 1;
            }
            r++;
        }
        else
        {
            zero_cnt++;
            while(zero_cnt > k)
             {
                 if(a[l] == 0)
                  {
                       zero_cnt--;
                       
                  }
                 l++;
             }
            if(r -l + 1 > max_len)
            {
                low_idx = l;
                
                
                max_len = r -l + 1;
            }
            r++;
        }
    }
    return max_len; 
            
            
            
       
}
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int ans = solve(a, n, k) ;
    cout << ans << endl;
    
    for(int i = low_idx; i < low_idx + ans; i++)
    {
        a[i] = 1;
    }
    for(auto x : a)
    {
        cout << x << " ";
    }
    
    return 0;
}
