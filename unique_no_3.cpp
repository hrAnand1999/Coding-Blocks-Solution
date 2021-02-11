#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int no;
    vector<int> v(64);
    
    for(int i = 0; i < n; i++)
    {
        cin >> no;
        int j = 0;
        while(no)
        {
            int last_bit = (no & 1);
            no >>= 1;
            v[j] += last_bit;
            j++;
        }

    }
    int p = 1;
    int ans = 0;
    for(int i = 0; i < 64; i++)
    {
        v[i] = v[i] % 3;
        ans = ans + (p * v[i]);
        p *= 2;
    }
    cout << ans << endl;
    
}
