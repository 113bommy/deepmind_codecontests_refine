#include <bits/stdc++.h>
using namespace std;
inline int next_samebit(int mask) {
  int lowbit = mask & -mask;
  int slack = lowbit + mask;
  return slack | (mask ^ slack) / lowbit / 4;
}
int n, a[16], at, row[4], col[4], val[4][4];
bool dfs(int r, int c, int mask) {
  if (r == 3 && c == 1 && val[0][3] + val[1][2] + val[2][1] + val[3][0] != at)
    return false;
  if (c == 4) {
    if (r == 3) return val[0][0] + val[1][1] + val[2][2] + val[3][3] == at;
    c = 0, ++r;
  }
  for (int s = mask; s; s &= s - 1) {
    int x = __builtin_ctz(s);
    if (c == 3 && row[r] + a[x] != at) continue;
    if (r == 3 && col[c] + a[x] != at) continue;
    row[r] += a[x];
    col[c] += a[x];
    val[r][c] = a[x];
    if (dfs(r + 1, c, s ^ 1 << x)) return true;
    row[r] -= a[x];
    col[c] -= a[x];
  }
  return false;
}
int main() {
  scanf("%d", &n);
  int m = n * n, all = 0, sum = 0;
  for (int i = 0; i < m; all += a[i++]) scanf("%d", a + i);
  if (n == 1) {
    sum = a[0];
  } else if (n == 2) {
    sort(a, a + m);
    do {
      sum = a[0] + a[1];
      if (sum == a[3] + a[4] && sum == a[0] + a[3] && sum == a[1] + a[4] &&
          sum == a[0] + a[4] && sum == a[1] + a[3])
        break;
    } while (next_permutation(a, a + m));
  } else if (n == 3) {
    sort(a, a + m);
    do {
      sum = a[0] + a[1] + a[2];
      if (sum == a[3] + a[4] + a[5] && sum == a[6] + a[7] + a[8] &&
          sum == a[0] + a[3] + a[6] && sum == a[1] + a[4] + a[7] &&
          sum == a[2] + a[5] + a[8] && sum == a[0] + a[4] + a[8] &&
          sum == a[2] + a[4] + a[6])
        break;
    } while (next_permutation(a, a + m));
  } else if (n == 4) {
    int mask = (1 << m) - 1;
    for (int s = 255; s <= mask; s = next_samebit(s)) {
      for (int i = sum = 0; i < m; i++)
        if (s & 1 << i) sum += a[i];
      if ((all * 2 + sum) % 10) continue;
      at = (all * 2 + sum) / 10;
      if (dfs(0, 0, mask)) break;
    }
  }
  printf("%d\n", sum);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) printf("%d ", a[i * n + j]);
    printf("%d\n", a[i * n + n - 1]);
  }
}
