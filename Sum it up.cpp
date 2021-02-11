#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
set<vector<int>> s;
void subset_sum(int *a, int i, int n, vector<int>& out, int j, int target)
{
    if(target == 0)
    {
        vector<int> temp(j);
        for(int k = 0; k < j; k++)
        {
            temp[k] = out[k];
        }
        sort(temp.begin(), temp.end());
        s.insert(temp);
        return;
    }
    if(i == n)
       return;
    if(target - a[i] >= 0)
    {
        out[j] = a[i];
        subset_sum(a, i + 1, n, out, j + 1, target - a[i]);
        subset_sum(a, i + 1, n, out, j, target);
    }
    else
    subset_sum(a, i + 1, n, out, j, target);
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;

    vector<int> out(n);
    subset_sum(a, 0, n, out, 0, target);


    for(auto x : s)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
