#include<stdio.h>
typedef long long int ll;
char a[11];
ll as(int b, ll c. ll d){
	if(a[b]=='\0') return c+d;
	else return as(b+1, c*10+a[n]-'0')+as(b+1,a[b]-'0',d+c);
}
int main(){
	scanf("%s",a);
	printf("%lld\n",as(1,a[0]-'0',0));
	return 0;
}