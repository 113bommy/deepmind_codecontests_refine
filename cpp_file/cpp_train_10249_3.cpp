#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int l[100], v[100][100], t[100][100], q[200];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    for (int j = 0; j < l[i]; j++) {
      scanf("%d%d", &v[i][j], &t[i][j]);
      if (j > 0) t[i][j] += t[i][j - 1];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int k = 0;
      q[k++] = 0;
      for (int p = 0; p < l[i]; p++) q[k++] = t[i][p];
      for (int p = 0; p < l[j]; p++) q[k++] = t[j][p];
      sort(q, q + k);
      int a = 0, b = 0, ls = 0, x = 0, y = 0;
      for (int p = 1; p < k; p++) {
        int d = q[p] - q[p - 1];
        while (a + 1 < l[i] && t[i][a] < q[p]) a++;
        while (b + 1 < l[j] && t[j][b] < q[p]) b++;
        x += v[i][a] * d;
        y += v[j][b] * d;
        int cs = int(x > y) - int(x < y);
        if (ls == 0)
          ls = cs;
        else if (cs != 0 && ls != cs) {
          ls = cs;
          ans++;
        }
        if (x == m || y == m) break;
      }
    }
  printf("%d\n", ans);
  return 0;
}
