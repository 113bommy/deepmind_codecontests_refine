#include <bits/stdc++.h>
int n, m, cnt, a[1005], b[1005];
char s[1005];
double work(int n, int m, int *a) {
  long long res = 0, now;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) res += (i - j) * (m - (a[j] >= 0));
    for (int j = i; j < n; j++) res += (j - i) * (m - (a[j] >= 0));
    ans += res * (m - (a[i] >= 0)), res = 0;
  }
  for (int i = 0; i < n; i++)
    if (a[i] >= 0) {
      now = a[i];
      for (int j = i; j >= 0 && a[j] >= now; j--)
        now = a[j], res += m - 1 - now;
      now = a[i];
      for (int j = i + 1; j < m && a[j] > now; j++)
        now = a[j], res += m - 1 - now;
      ans += res * a[i] * 4, res = 0;
    }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m), cnt = n * m;
  for (int i = 0; i < n || i < m; i++) a[i] = b[i] = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++)
      if (s[j] == 'X') a[i] = j, b[j] = i, cnt--;
  }
  printf("%.9lf\n", (work(n, m, a) + work(m, n, b)) / cnt / cnt);
  return 0;
}
