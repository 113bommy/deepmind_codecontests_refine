#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, nn, m;
int a[N], b[N], c[N];
int f[N];
inline void add(int i, int v) {
  for (; i <= n; i += i & -i) f[i] += v;
}
inline int find(int v) {
  int i = 0;
  for (int k = 20; k >= 0; k--) {
    if (i + (1 << k) <= n && f[i + (1 << k)] < v) {
      i += 1 << k;
      v -= f[i];
    }
  }
  return i + 1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
    if (c[i] != -1) b[++nn] = c[i];
  }
  for (int i = 1; i <= nn; i++) add(i, 1);
  nn = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] != -1)
      nn++;
    else {
      int k;
      for (k = 1; k <= m && a[k] <= nn; k++) add(find(a[k] - k + 1), -1);
      nn -= k - 1;
    }
  }
  if (nn == 0) {
    printf("Poor stack!\n");
    return 0;
  }
  for (int i = 1; i <= nn; i++) printf("%d", b[find(i)]);
}
