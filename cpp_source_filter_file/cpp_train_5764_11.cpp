#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a = 1, p = 3;
  while (n) {
    if (n & 1) a = 1LL * p * a % m;
    n >>= 1;
    p = 3LL * p % m;
  }
  a = (a + m - 1) % m;
  printf("%d\n", a);
  return 0;
}
