#include <bits/stdc++.h>
int main() {
  int n, s = 0;
  scanf("%i", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%i", &x);
    s += x * (i + 1);
  }
  printf("%i\n", s);
}
