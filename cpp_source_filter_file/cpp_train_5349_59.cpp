#include <bits/stdc++.h>
int main() {
  int i, l;
  char s[1000];
  scanf("%s", s);
  for (i = 0; i < l; i++) {
    if (s[0] >= 97 && s[0] <= 122) s[0] = 65 + s[0] - 97;
  }
  printf("%s\n", s);
  return 0;
}
