#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long a, b, x, y;
  scanf("%lld %lld", &a, &b);
  x = (a - b) / 2;
  y = x + b;
  x > y || x + y != a || (x ^ y) != b ? printf("-1\n")
                                      : printf("%lld %lld\n", x, y);
  return 0;
}
