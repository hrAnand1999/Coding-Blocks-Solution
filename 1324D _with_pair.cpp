#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, greater<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
             PBDS;

int main() {
    PBDS st;
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++)
    cin >> a[i];
    for(int i = 0; i < n; i++)
    cin >> b[i];
    for(int i = 0; i < n; i++)
    c[i] = a[i] - b[i];
    int good_pair = 0;
    for(int j = 0; j < n; j++)
    {
         good_pair += st.order_of_key({-c[j], 1000000});
         st.insert({c[j],1000000});
    }
    cout << good_pair << endl;
    return 0;

}
