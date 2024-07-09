#include <bits/stdc++.h>
using namespace std;
long long a[110];
int main() {
  long long i, j, n, m, odd = 0, sum = 0, best = 0, t;
  scanf("%lld", &t);
  while (t--) {
    odd = 0, sum = 0, best = 0;
    scanf("%lld", &n);
    for (i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      if (a[i] % 2 == 0) best = max(best, a[i]);
      sum += a[i];
      odd += a[i] % 2;
    }
    if (odd % 2 == 1 || best > sum - best) {
      printf("T\n");
    } else {
      printf("HL\n");
    }
  }
  return 0;
}
