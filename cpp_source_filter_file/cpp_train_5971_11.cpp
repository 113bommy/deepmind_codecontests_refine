#include <bits/stdc++.h>
using namespace std;
long long solve(int n, long long m, long long k) {
  long long rest = m * k;
  --n;
  long long povrh = 1;
  for (int i = 1; i <= k; ++i) {
    long long add = rest / i;
    povrh *= (k - i + 1);
    povrh /= i;
    add = min(add, povrh);
    rest -= add * i;
    n -= add;
    if (rest <= 0 || n <= 0) break;
  }
  return n <= 0;
}
int main(void) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, m;
    scanf("%d%d", &n, &m);
    int lo, hi;
    lo = 0;
    hi = n;
    while (lo < hi) {
      int mi = (lo + hi) >> 1;
      if (solve(n, m, mi) == 0)
        lo = mi + 1;
      else
        hi = mi;
    }
    printf("%d\n", lo);
  }
  return 0;
}
