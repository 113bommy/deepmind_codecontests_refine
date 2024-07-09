#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
T absval(T x) {
  return x > 0 ? x : -x;
}
const long long INFI = (long long)2E18;
const int maxn = 100010;
long long xa[1001111];
long long cl[1001111], cr[1001111];
int len;
void search(long long x) {
  xa[++len] = x;
  if (x < (long long)1E17) search(x * 10 + 4), search(x * 10 + 7);
}
long long le[maxn], ri[maxn];
long long k, min_delta;
int n;
long long mult(long long a, long long b) {
  if (b > 0 && a > INFI / b)
    return INFI;
  else
    return a * b;
}
long long add(long long a, long long b) {
  if (a > INFI - b)
    return INFI;
  else
    return a + b;
}
bool chk(int i, int j) {
  return xa[j] - xa[i] <= min_delta && add(cl[i], cr[j]) <= k;
}
void solve() {
  scanf("%d%I64d", &n, &k);
  min_delta = (long long)1E18;
  for (int i = (int)(1); i <= (int)(n); ++i) {
    scanf("%I64d%I64d", &le[i], &ri[i]);
    min_delta = min(min_delta, ri[i] - le[i]);
  }
  sort(le + 1, le + n + 1);
  sort(ri + 1, ri + n + 1);
  len = 0;
  search(4);
  search(7);
  sort(xa + 1, xa + len + 1);
  long long sum = 0, cnt = 0;
  int k = 1;
  for (int i = (int)(1); i <= (int)(len); ++i) {
    if (i > 1) sum = add(sum, mult(cnt, xa[i] - xa[i - 1]));
    while (k <= n && ri[k] <= xa[i]) {
      sum = add(sum, xa[i] - ri[k]);
      ++cnt;
      ++k;
    }
    cr[i] = sum;
  }
  sum = 0, cnt = 0, k = n;
  for (int i = (int)(len); i >= (int)(1); --i) {
    if (i < len) sum = add(sum, mult(cnt, xa[i + 1] - xa[i]));
    while (k >= 1 && xa[i] <= le[k]) {
      sum = add(sum, le[k] - xa[i]);
      ++cnt;
      --k;
    }
    cl[i] = sum;
  }
  int ans = 0, j = 1;
  for (int i = (int)(1); i <= (int)(len); ++i) {
    j = max(j, i);
    while (j <= len && chk(i, j)) ++j;
    ans = max(ans, j - i);
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
