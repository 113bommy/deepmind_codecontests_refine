#include <bits/stdc++.h>
using namespace std;
bool visit[60][60][2][2];
int f[60][60][2][2];
int a[60], n;
long long k;
long long calc(int l, int r, int f1, int f2) {
  if (l > r) return 1;
  if (visit[l][r][f1][f2]) return f[l][r][f1][f2];
  visit[l][r][f1][f2] = 1;
  f[l][r][f1][f2] = 0;
  for (int i = 0; i <= 1; i++)
    if (a[l] == -1 || a[l] == i)
      for (int j = 0; j <= 1; j++)
        if (a[r] == -1 || a[r] == j) {
          int _f1 = f1, _f2 = f2;
          if (i < j) _f1 = 1;
          if (i < 1 - j) _f2 = 1;
          if ((l < r || i == j) && (f1 || i <= j) && (f2 || i <= 1 - j))
            f[l][r][f1][f2] += calc(l + 1, r - 1, _f1, _f2);
        }
  return f[l][r][f1][f2];
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) a[i] = -1;
  k++;
  if (calc(1, n, 0, 0) < k) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = 0;
    memset(visit, 0, sizeof(visit));
    long long p = calc(1, n, 0, 0);
    if (p < k) a[i] = 1, k -= p;
  }
  for (int i = 1; i <= n; i++) printf("%d", a[i]);
}
