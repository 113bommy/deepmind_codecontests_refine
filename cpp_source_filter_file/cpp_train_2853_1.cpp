#include <bits/stdc++.h>
int a[4], n, b[100000], ans, v[1000001][2];
void work(int &x, int &y, int &z) {
  while (1) {
    if (b[x] > b[y]) std::swap(x, y);
    if (b[x] > b[z]) std::swap(x, z);
    if (b[y] > b[z]) std::swap(y, z);
    if (!b[x]) return;
    for (int i = b[y] / b[x]; i; i /= 2)
      if (i & 1) {
        b[y] -= b[x];
        b[x] <<= 1;
        v[++ans][0] = y;
        v[ans][1] = x;
      } else {
        b[z] -= b[x];
        b[x] <<= 1;
        v[++ans][0] = z;
        v[ans][1] = x;
      }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    if (b[i]) a[++a[0]] = i;
    if (a[0] == 3) {
      work(a[1], a[2], a[3]);
      a[1] = a[2];
      a[2] = a[3];
      a[0] = 2;
    }
  }
  if (a[0] != 2) return puts("-1");
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) printf("%d %d\n", v[i][0], v[i][1]);
}
