#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
int a, b, c, d, e, f;
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int D = e + d + c;
  int ans = D * D - a * a - e * e - c * c;
  printf("%d\n", ans);
  return 0;
}
