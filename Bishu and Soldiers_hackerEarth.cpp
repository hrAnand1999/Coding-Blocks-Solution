#include <bits/stdc++.h>
using namespace std;
void soldier(int *power, int n, int &idx, int m)
{
    int s = 0, e= n - 1;
    int mid;
    while(s <= e)
    {
        mid = (s + e)/2;
        if(power[mid] <= m)
        {
            idx = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int power[n];
    for(int i = 0; i < n; i++)
    {
        cin >> power[i];
    }
    sort(power, power + n);
    int csum[n + 1];
    csum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        csum[i] = csum[i - 1] + power[i - 1];
    }
    int q;
    cin >> q;
    int m;
    while(q--)
    {
       cin >> m;
       int idx = -1;
       soldier(power, n, idx, m);
       if(idx == -1)
       {
           cout << 0 << " " << 0 << endl;
       }
       else
       {
           cout << idx + 1 << " " << csum[idx + 1] << endl;
       }

    }
    return 0;
}
