#include <bits/stdc++.h>
using namespace std;
int n, m = 0, ans = 0;
int a[30], A[1 << 20], B[1 << 20];
void deal(const int z, const int x, const int y) {
  if (z > n) return;
  int w = x ^ y;
  deal(z + 1, x, w);
  for (int i = 1; i <= a[z]; ++i) A[++ans] = x, B[ans] = y;
  deal(z + 1, w, y);
}
void Gans(const int z) {
  if (z == n) {
    for (int i = 1; i < a[z]; ++i) A[++ans] = 1, B[ans] = 2;
    A[++ans] = 1, B[ans] = 3;
    for (int i = 1; i < a[z]; ++i) A[++ans] = 2, B[ans] = 3;
    return;
  }
  if (a[z] < 2) {
    deal(z, 1, 3);
    return;
  }
  deal(z + 1, 1, 3);
  for (int i = 1; i <= a[z]; ++i) A[++ans] = 1, B[ans] = 2;
  deal(z + 1, 3, 1);
  for (int i = 1; i <= a[z]; ++i) A[++ans] = 2, B[ans] = 3;
  Gans(z + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, j = -1, x; i <= n; ++i) {
    scanf("%d", &x);
    if (x != j) j = x, a[++m] = 0;
    ++a[m];
  }
  Gans(1);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) printf("%d %d\n", A[i], B[i]);
  return 0;
}
