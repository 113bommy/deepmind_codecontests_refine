#include <stdio.h>

int main()
{
char a,b;
scanf("%c%c", &a, &b);
if (a == '9' || b == '9') printf("Yes");
else printf("No");
}