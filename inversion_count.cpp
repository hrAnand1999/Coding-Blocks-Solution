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

//for both distinct and repetitive element
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int inv_cnt = 0;
    for(int i = 0; i < n; i++)
    {
        inv_cnt += st.order_of_key(a[i]);
        st.insert(a[i]);
    }
    cout << inv_cnt << endl;
}
