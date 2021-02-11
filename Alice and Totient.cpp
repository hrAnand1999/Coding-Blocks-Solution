#include <iostream>
using namespace std;
#define ll long long

const int n = 1000000;
int p[n + 1] = {0};
void prime_factors()
{
    for(int i = 2; i <= n; i++)
    {
        if(!p[i])
        {
            for(int j = i; j <= n; j+=i)
            {
                if(!p[j])
                {
                    p[j] = i;
                }
            }
        }
    }
}
int main() {
    prime_factors();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll ans = 1;
        int prev = 0;
        ll new_n = n;
        bool flag = false;
        while(n != 1)
        {
              int fact = p[n];
              if(fact != prev)
              {
                  if(!flag)
                  {
                       ans = ans * (new_n - (new_n/fact));
                       flag = true;
                  }
                  else
                  {
                      ans = new_n - (new_n/fact);
                  }
                  prev = fact;
                  new_n = ans;
              }
              n = n/fact;
        }
        cout << ans << endl;
    }
   
    return 0;
}
