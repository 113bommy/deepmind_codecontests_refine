#include <bits/stdc++.h>
char s[200100], c;
int t;
int main() {
  while ((c = getchar()) != '\n') {
    while (t && s[t] < c) t--;
    s[++t] = c;
  }
  printf("%s", s + 1);
}
