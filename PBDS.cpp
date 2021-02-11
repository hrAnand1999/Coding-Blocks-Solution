#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
             PBDS;

//if we use less, then it'll be sorted in ascending order 
//if we use greater, then it'll be sorted in descending order
//to insert duplicate element we can use pair 

int main() {
    PBDS st;

    st.insert({2,0});
    st.insert({5,1});
    st.insert({1,2});
    st.insert({10,3});
    st.insert({15,4});
    st.insert({12,5});
    st.insert({2,6});
    /*for(int i = 0; i < st.size(); i++)
    {
        cout << i << " " << *st.find_by_order(i) << endl;
    }
    */
    for(int i = 0; i < st.size(); i++)
    {
        cout << i << " " << st.find_by_order(i)->first << " " << st.find_by_order(i)->second << endl;
    }

    //cout << st.order_of_key(16)<<endl;

}
