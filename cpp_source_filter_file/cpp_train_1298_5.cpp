#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e14;
const int N = 100100;
int n, m, k;
long long a[N];
long long h[N];
long long p;
int b[N];
void read() {
  scanf("%d%d%d%I64d", &n, &m, &k, &p);
  for (int i = 0; i < n; i++) scanf("%I64d%I64d", &h[i], &a[i]);
  return;
}
bool check(long long val) {
  for (int i = 0; i < n; i++)
    if (a[i] > val) return false;
  int cnt = 0;
  for (int i = 0; i <= m; i++) b[i] = 0;
  for (int i = 0; i < n; i++) {
    long long w = val;
    long long t = 0;
    while (t < m) {
      long long k = w / a[i];
      t += k;
      if (t >= m) {
        t -= k;
        w -= a[i] * (m - t);
        break;
      }
      w %= a[i];
      while (w < a[i]) {
        b[t]++;
        cnt++;
        w += p;
        if (cnt > m * k) return false;
      }
    }
    while (w < h[i]) {
      b[m]++;
      cnt++;
      w += p;
      if (cnt > m * k) return false;
    }
  }
  int bal = 0;
  for (int i = 1; i <= m; i++) {
    bal += b[i];
    if (bal > i * k) return false;
  }
  return true;
}
long long solve() {
  long long L = 0LL;
  long long R = INF;
  while (R - L > 1) {
    long long mid = (L + R) / 2;
    if (check(mid))
      R = mid;
    else
      L = mid;
  }
  return R;
}
int main() {
  read();
  printf("%I64d\n", solve());
  return 0;
}
