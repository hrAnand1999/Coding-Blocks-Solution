#include <iostream>
using namespace std;
int find_pivot(int *a, int s, int e)
{
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(a[s] <= a[mid])
        {
            if(a[mid] > a[mid + 1])
            return mid;
            else
            s = mid + 1;
        }
        else if(a[mid] <= a[e])
        {
            if(a[mid] < a[mid - 1])
            return mid - 1;
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
    int idx = find_pivot(a, 0, n - 1);
    cout << idx << endl;
    return 0;
}
