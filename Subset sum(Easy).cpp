#include<iostream>
using namespace std;
int cnt=0;
void issubsetsum0(int *a,int i,int n,int sum)
{
	//base case
	if(i==n)
	{
		if(sum==0)
		{
			cnt++;
			return;
		}
		return;
	}
	issubsetsum0(a,i+1,n,sum+a[i]);
	
	issubsetsum0(a,i+1,n,sum);
	
}
int main() {
	int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		issubsetsum0(a,0,n,0);
		if(cnt>1)
		{
			cout<<"Yes"<<endl;
		}
		else
		cout<<"No"<<endl;
		cnt=0;
	}
	return 0;
}