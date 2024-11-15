#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010, inf = 0x3f3f3f3f;
int a[maxn], b[maxn], gap[maxn];
int n, m;
void init() {
  scanf("%d", &n), gap[0] = gap[1] = 0;
  for (int i = 2; i <= n + 1; ++i) {
    scanf("%d", a + i);
    gap[i] = gap[i - 1] + (a[i] == -1);
  }
  a[1] = 0, a[n + 2] = inf, gap[n + 2] = gap[n + 1], n += 2;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", b + i);
  sort(b + 1, b + m + 1), m = unique(b + 1, b + m + 1) - b - 1;
}
int pre[maxn], f[maxn];
void dp() {
  static int low[maxn], last[maxn];
  memset(low, 63, sizeof(low));
  pre[1] = 0, f[1] = 1, low[1] = 0, last[1] = 1;
  for (int k = 2; k <= n; ++k)
    if (a[k] != -1) {
      int l = 1, r = n, mid;
      while (mid = (l + r) >> 1, l <= r)
        (low[mid] < a[k]) ? (l = mid + 1) : (r = mid - 1);
      pre[k] = last[l - 1], f[k] = l;
      low[l] = a[k], last[l] = k;
    } else {
      pre[k] = f[k] = -1;
      for (int i = m, j = n; i >= 1; --i) {
        while (low[j] >= b[i]) --j;
        last[j + 1] = -1, low[j + 1] = b[i];
      }
    }
}
void print() {
  for (int x = n, l, r, rest = m; x >= 1;)
    if (a[x] != -1) {
      if (pre[x] >= 0) {
        x = pre[x];
        continue;
      }
      r = lower_bound(b + 1, b + rest + 1, a[x]) - 1 - b;
      for (int y = x - 1; y >= 1; --y)
        if (a[y] != -1 && a[y] < a[x]) {
          l = upper_bound(b + 1, b + rest + 1, a[y]) - b;
          if (f[x] - f[y] - 1 == min(r - l + 1, gap[x] - gap[y])) {
            for (int i = y, j = l; i <= x && j <= r; ++i)
              if (a[i] == -1) a[i] = b[j], b[j++] = -1;
            x = y, rest = l - 1;
            break;
          }
        }
    }
  for (int i = 1, j = 1; i <= n; ++i)
    if (a[i] == -1) {
      while (b[j] == -1) ++j;
      a[i] = b[j++];
    }
  for (int i = 2; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}
int main() {
  init();
  dp();
  print();
  return 0;
}
