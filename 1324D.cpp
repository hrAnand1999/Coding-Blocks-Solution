#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, greater<int>, rb_tree_tag,
             tree_order_statistics_node_update>
             PBDS;

int main() {
    PBDS st;
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
    cin >> a[i];
    for(int i = 0; i < n; i++)
    cin >> b[i];

    int good_pair = 0;
    for(int i = 0; i < n; i++)
    {
         good_pair += st.order_of_key(b[i] - a[i]);
         st.insert(a[i] - b[i]);
    }
    cout << good_pair << endl;
    return 0;

}
