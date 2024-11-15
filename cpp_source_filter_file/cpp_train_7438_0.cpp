#include <bits/stdc++.h>
using namespace std;
int n, r, p, s, k;
int x[210], y[210], z[210], ax[9], ay[9], tx[9], ty[9];
void go(int m, int p) {
  if (p == n) {
    int u = 0;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        u += (tx[i] - tx[j]) * (tx[i] - tx[j]) +
             (ty[i] - ty[j]) * (ty[i] + ty[j]);
    if (u > s) {
      s = u;
      for (int i = 0; i < n; i++) ax[i] = tx[i], ay[i] = ty[i];
    }
  } else
    for (int i = m; i < k; i++) {
      tx[p] = x[i], ty[p] = y[i];
      go(i, p + 1);
    }
}
int main() {
  int i, j, r1, r2, t;
  scanf("%d%d", &n, &r);
  r1 = (r - 1) * (r - 1);
  r2 = r * r;
  k = 0;
  for (i = -r; i <= r; i++)
    for (j = -r; j <= r; j++) {
      t = i * i + j * j;
      if (t <= r2 && t > r1) x[k] = i, y[k] = j, z[k++] = t;
    }
  for (i = 0; i < k - 1; i++)
    for (j = i + 1; j < k; j++)
      if (z[j] > z[i]) {
        swap(x[j], x[i]);
        swap(y[j], y[i]);
        swap(z[j], z[i]);
      }
  k = 30 - n * 2;
  go(0, 0);
  printf("%d\n", s);
  for (i = 0; i < n; i++) printf("%d %d\n", ax[i], ay[i]);
  return 0;
}
