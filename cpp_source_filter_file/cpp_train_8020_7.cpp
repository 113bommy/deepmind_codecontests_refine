#include<stdio.h>

int a;
int b;

int main(){
scanf("%d %d", &a, &b);
if(a < b){
printf("a < b\n");
}elseif(a > b){
printf("a > b\n");
}else{
printf("a == b\n");
}
return 0;
}