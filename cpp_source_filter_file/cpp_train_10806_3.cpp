#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long ans=0
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[i]-=x;
		if(a[i]>0)
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}