#include <iostream>
using namespace std;
int find_ele(int *a, int s, int e, int key)
{
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(a[mid] == key)
        return mid;
        if(a[s] <= a[mid])
        {
            if(key > a[s] && key < a[mid])
            e = mid - 1;
            else
            s = mid + 1;
        }
        else if(a[mid] <= a[e])
        {
            if(key > a[mid] && key < a[e])
            s = mid + 1;
            else
            e = mid - 1;
        }
    }
    return -1;
}
int main() {
   int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >>key;
    int idx = find_ele(a, 0, n - 1, key);
    cout << idx << endl;
    return 0;
}
