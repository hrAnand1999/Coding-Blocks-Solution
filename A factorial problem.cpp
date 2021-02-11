#include<iostream>
#include<climits>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = INT_MAX;
        for(int i = 2; i*i <= k; i++)
        {
            if(k % i == 0)
            {
                int occ = 0;
                while(k % i == 0)
                {
                    occ++;
                    k /= i;
                }
                int cnt = 0;
                ll p = i;
                while(p <= n)
                {
                    cnt += (n / p);
                    p = p*i;
                }
                ans = min(ans, cnt/occ);
            }
        }
        if(k > 1)
        {
            ll p = k;
            int cnt = 0;
            while(p <= n)
            {
                cnt += (n/p);
                p = p*k;
            }
            ans = min(ans, cnt);
        }
        if(ans == INT_MAX)
        {
            ans = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
