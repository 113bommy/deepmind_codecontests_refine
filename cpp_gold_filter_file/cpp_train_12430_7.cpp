#include <bits/stdc++.h>
int main() {
  long long n;
  scanf("%I64d", &n);
  while (n % 3 == 0) n /= 3;
  printf("%I64d", (n / 3) + 1);
  return 0;
}
