#include <bits/stdc++.h>
using namespace std;
int f(long long n) {
  if (n < 4) return 0;
  if (n < 16) return 1;
  if (n < 82) return 2;
  if (n < 6724) return 0;
  if (n < 50626) return 3;
  if (n < 50626LL * 50626LL) return 1;
  return 2;
}
int main() {
  int n;
  long long x, now = 0;
  scanf("%d", &n);
  scanf("%I64d", &now);
  now = f(now);
  for (int i = 1; i < n; i++) {
    scanf("%I64d", &x);
    now ^= f(x);
  }
  if (now == 0)
    printf("Rublo\n");
  else
    printf("Furlo\n");
  return 0;
}
