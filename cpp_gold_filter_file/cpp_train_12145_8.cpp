#include <bits/stdc++.h>
using namespace std;
const int N = 500001;
const long long MOD = 1e9 + 7;
const double eps = 1e-9;
int n, k, p, a[N], s[N], dp[N], seg[4 * 101], dp1[N][101], dp2[101];
void update(int p, int s, int e, int i, int v) {
  if (s == e) {
    seg[p] = v;
    return;
  }
  if (i <= (s + e) / 2)
    update(2 * p, s, (s + e) / 2, i, v);
  else
    update(2 * p + 1, (s + e) / 2 + 1, e, i, v);
  seg[p] = max(seg[2 * p], seg[2 * p + 1]);
}
int get(int p, int s, int e, int a, int b) {
  if (s >= a && e <= b) return seg[p];
  if (s > b || e < a) return 0;
  return max(get(2 * p, s, (s + e) / 2, a, b),
             get(2 * p + 1, (s + e) / 2 + 1, e, a, b));
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    s[i] = a[i] % p;
    if (i) s[i] = (s[i] + s[i - 1]) % p;
  }
  if (p * k >= n) {
    for (int i = 0; i < p; i++) dp2[i] = 1e9;
    for (int i = 0; i < n; i++) dp1[i][1] = s[i];
    for (int j = 2; j <= k; j++) {
      for (int i = 0; i < p; i++) dp2[i] = 1e9;
      for (int i = 0; i < n; i++) {
        dp1[i][j] = 1e9;
        for (int l = 0; l < p; l++)
          dp1[i][j] = min(dp1[i][j], dp2[l] + (s[i] - l + p) % p);
        dp2[s[i]] = min(dp2[s[i]], dp1[i][j - 1]);
      }
    }
    printf("%d\n", dp1[n - 1][k]);
  } else {
    dp[0] = 1;
    update(1, 0, p - 1, 0, 1);
    for (int i = 1; i < n; i++) {
      dp[i] = get(1, 0, p - 1, 0, s[i]) + 1;
      update(1, 0, p - 1, s[i], dp[i]);
    }
    if (dp[n - 1] >= k)
      printf("%d\n", s[n - 1]);
    else
      printf("%d\n", s[n - 1] + p);
  }
  return 0;
}
