#inlude<bits/stdc++.h>
using namespace std;
int a[100050],n,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1])
			ans++;
	if(ans%2==1) ans++;
	cout<<n-ans<<endl;
	return 0;
}
