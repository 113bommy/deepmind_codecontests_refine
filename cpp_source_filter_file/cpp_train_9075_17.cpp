#include <bits/stdc++.h>
char s[100];
int a[10];
int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; i++) a[s[i] - '0']++;
  if (!a[4] && !a[7]) puts("-1");
  if (a[7] > a[4])
    puts("7");
  else
    puts("4");
  return 0;
}
