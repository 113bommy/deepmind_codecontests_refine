#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &(n));
  if (n == 1) {
    printf("%d\n", (0));
    return 0;
  }
  long long a[(100000 + 10)];
  for (int i(0), _n(n); i < _n; ++i) scanf("%I64d", &a[i]);
  long long s = 0;
  for (int i(0), _n(n - 1); i < _n; ++i) {
    int t = 1;
    while (i + t * 2 < n) t <<= 1;
    s += a[i];
    a[i + t] += a[i];
    printf("%d\n", (s));
  }
  return 0;
}
