#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h,i;
    scanf ("%d%d%d",&a,&b,&e);  
    c=3*e-a-b;
    h=2*e-b;
    f=2*a-h;
    i=3*e-c-f;
    d=2*e-f;
    g=3*e-h-i;
    printf ("%d %d %d\n",a,b,c);
    printf ("%d %d %d\n",d,e,f);
    printf ("%d %d %d\n",g,h,i);  
    return 0;
}