#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int s = 0, e = n - 1;
	int mid, ans;
	while(s <= e)
	{
		mid = (s + e)/2;
        if(mid + 1 < n && a[mid] >= a[mid + 1])
		{
			ans = mid;
			break;
		}
		else if(a[s] <= a[mid])
		{
              s = mid + 1;
		}
		else 
		{
			e = mid - 1;
		}
	}
	cout << ans;
	return 0;
}