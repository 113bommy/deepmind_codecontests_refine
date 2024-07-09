#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
const long long UP = 2.2e9;
long long num[maxn], sum[maxn];
int cnt, wei[15];
inline void init() {
  long long up = 0, pre = 0, x = 0, cut = 0;
  cnt = 0;
  int flag = 0;
  for (int k = 1; k <= 9; ++k) {
    cut = x;
    x = x * 10 + 9;
    long long xx = x - cut;
    for (int i = 1; i <= xx; ++i) {
      up += pre + i * k;
      num[++cnt] = pre + i * k;
      if (up >= UP) {
        flag = 1;
        break;
      }
    }
    if (flag) break;
    pre += (x - x / 10) * k;
  }
  sum[0] = 0;
  sum[1] = num[1];
  for (int i = 1; i <= cnt; ++i) sum[i] = sum[i - 1] + num[i];
}
int main() {
  init();
  int t, n, k, flag;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (k = 1; k <= cnt; ++k)
      if (n <= sum[k]) break;
    n -= sum[k - 1];
    flag = 0;
    for (int i = 1; i <= k; ++i) {
      int t = i, j = 0;
      while (t) {
        wei[++j] = t % 10;
        t /= 10;
      }
      for (int l = j; l >= 1; --l) {
        --n;
        if (n == 0) {
          flag = 1;
          printf("%d\n", wei[l]);
          break;
        }
      }
      if (flag) break;
    }
  }
  return 0;
}
