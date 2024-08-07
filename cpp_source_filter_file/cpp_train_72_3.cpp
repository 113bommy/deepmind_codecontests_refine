#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long INF64 = 1e18;
const int N = 1000 * 1000 + 13;
int n, m, k;
bool pos[N];
int lst[N], s[N], a[N];
int get(int l) {
  int r = 0, i = -1, res = 0;
  while (r < n) {
    if (lst[r] <= i) return INF;
    i = lst[r];
    r = lst[r] + l;
    ++res;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) scanf("%d", &s[i]);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) pos[i] = true;
  for (int i = 0; i < m; i++) pos[s[i]] = false;
  for (int i = 0; i < n; i++) {
    if (pos[i])
      lst[i] = i;
    else if (i)
      lst[i] = lst[i - 1];
    else
      lst[i] = -1;
  }
  long long ans = INF64;
  for (int i = 0; i < k; i++) {
    long long t = get(i + 1);
    if (t != INF) ans = min(ans, a[i] * t);
  }
  if (ans == INF64) ans = -1;
  printf("%d\n", ans);
  return 0;
}
