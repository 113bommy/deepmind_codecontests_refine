#include <cstdio>
int main()
{
 long M,m,sum,d;
 int n;
 sum=0;
 scanf("%d",&n);
 M=-1000000;
 m=1000000;
 for(i=0;i<n;i++){
  scanf("%ld",&d);
  M=(M<d)?d:M;
  m=(m<d)?m:d;
  sum += d;
 }
 printf("%d %d %d\n",m,M,sum);
 return 0;
};