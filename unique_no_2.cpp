#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
         cin >> a[i];
         ans ^= a[i];
    }
    int temp = ans;
    int pos = 0;
    while(temp)
    {
        pos++;
        temp >>= 1;
    }
    pos -= 1;
    int mask = 1 << pos;
    int x = ans;
    for(int i = 0; i < n; i++)
    {
        if(mask & a[i])
        {
            x ^= a[i];
        }
    }
    int y = ans ^ x;
    cout << min(x, y) << " " << max(x, y) << endl;
    return 0;

}
