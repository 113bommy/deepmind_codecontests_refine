#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int cnt[1005];
long double C(int a, int b) {
  if (a < b) return 0;
  long double res = 1;
  long double tmp = 0;
  for (int i = (a - b + 1), i_end_ = (a); i <= i_end_; i++)
    res *= i, res /= (++tmp);
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  int tot = 0;
  for (int i = (1), i_end_ = (m); i <= i_end_; i++)
    scanf("%d", &cnt[i]), tot += cnt[i];
  if (tot < n) {
    puts("-1");
    return 0;
  }
  n--;
  tot -= cnt[h];
  cnt[h]--;
  long double ans = 0;
  long double tmp = C(tot + cnt[h], n);
  for (int i = (1), i_end_ = (min(n, cnt[h])); i <= i_end_; i++) {
    ans += C(cnt[h], i) / tmp * C(tot, n - i);
  }
  printf("%.8Lf\n", ans);
  return 0;
}
