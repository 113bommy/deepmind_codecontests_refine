#include"bits/stdc++.h"
using namespace std;
int n,x[111111],y[111111],t[111111];

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d%d%d",&t[i],&x[i],&y[i]);
	for(int i=1; i<=n; i++)
		if(x[i]+y[i]>t[i]||(t[i]-x[i]-y[i])%2!=0) { 
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}