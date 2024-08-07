#include <bits/stdc++.h>
using namespace std;
const int N = 5, R = 1e4;
int n, l[N], r[N];
long long cnt[R + 1];
double all;
bool used[N];
long long f(int cur, int c, int mn, int x = N) {
  if (cur == n) {
    if (mn > 0) {
      return 0;
    }
    long long cnt = 1;
    for (int i = 0; i < n; i++) {
      if (!used[i] && i != x) {
        cnt *= max(0, min(c, r[i] + 1) - l[i]);
      }
    }
    return cnt;
  }
  long long cnt = f(cur + 1, c, mn, x);
  if (cur != x && l[cur] <= c && c <= r[cur]) {
    used[cur] = true;
    cnt += f(cur + 1, c, mn - 1, x);
    used[cur] = false;
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", l + i, r + i);
  }
  for (int cur = 0; cur <= R; cur++) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += f(0, cur, 1, i) * max(0, r[i] - max(cur, l[i] - 1));
    }
    sum += f(0, cur, 2);
    all += sum;
    cnt[cur] = sum;
  }
  double ans = 0;
  for (int i = 0; i <= R; i++) {
    ans += i * cnt[i] / all;
  }
  printf("%.10f", ans);
}
