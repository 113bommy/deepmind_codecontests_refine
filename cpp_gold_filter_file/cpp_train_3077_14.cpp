#include <bits/stdc++.h>
char s[100003];
int a[100003];
int main() {
  int n;
  scanf("%d", &n);
  gets(s);
  gets(s);
  int len = strlen(s);
  for (int i = 0, j = 0; i < len; ++i)
    if (s[i] == '.' || s[i] == '!' || s[i] == '?')
      a[++a[0]] = j + 1, j = 0, ++i;
    else
      ++j;
  int ans = 0;
  for (int i = 1, s = -1; i <= a[0]; ++i) {
    if (s + 1 + a[i] <= n)
      s += 1 + a[i];
    else
      s = a[i], ++ans;
    if (s > n) {
      puts("Impossible");
      return 0;
    }
  }
  printf("%d\n", ++ans);
  return 0;
}
