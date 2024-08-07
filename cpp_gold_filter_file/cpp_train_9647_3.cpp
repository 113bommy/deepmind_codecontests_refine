#include <bits/stdc++.h>
using namespace std;
const int maxn = 1200005, maxm = 25;
int u[maxn], v[maxn], f[maxm];
int n, tot, ans;
void work(int x, int a, int b) {
  int i, c;
  c = 6 - a - b;
  if (x < tot) work(x + 1, a, c);
  for (i = 0; i < f[x]; ++i) ++ans, u[ans] = a, v[ans] = b;
  if (x < tot) work(x + 1, c, b);
}
int main() {
  int i, j, x, last;
  scanf("%d", &n);
  last = 0;
  while (n--) {
    scanf("%d", &x);
    if (x != last) {
      f[++tot] = 1;
      last = x;
    } else
      ++f[tot];
  }
  for (i = 1; i < tot; ++i)
    if (f[i] > 1) {
      work(i + 1, 1, 3);
      for (j = 0; j < f[i]; ++j) ++ans, u[ans] = 1, v[ans] = 2;
      work(i + 1, 3, 1);
      for (j = 0; j < f[i]; ++j) ++ans, u[ans] = 2, v[ans] = 3;
    } else {
      work(i, 1, 3);
      break;
    }
  if (i == tot) {
    for (j = 1; j < f[tot]; ++j) ++ans, u[ans] = 1, v[ans] = 2;
    ++ans;
    u[ans] = 1;
    v[ans] = 3;
    for (j = 1; j < f[tot]; ++j) ++ans, u[ans] = 2, v[ans] = 3;
  }
  printf("%d\n", ans);
  for (i = 1; i <= ans; ++i) printf("%d %d\n", u[i], v[i]);
  return 0;
}
