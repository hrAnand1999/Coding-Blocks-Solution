#include <iostream>
using namespace std;
#define ll long long
bool is_possible(ll *a, ll n, ll m, ll max_page)
{
    int page_used = a[0];
    int student = 1;
    for(int i = 1; i < n; i++)
    {
        if(page_used + a[i] > max_page)
        {
            student++;
            page_used = a[i];
            if(student > m)
            return false;
        }
        else
        {
            page_used += a[i];
        }
    }
    return true;
}
int main() {
    ll n, m;
    cin >> n >> m;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll s = a[n - 1];
    ll e = sum;
    ll ans;
    while(s <= e)
    {
        ll mid = (s + e) / 2;
        if(is_possible(a, n, m, mid))
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
