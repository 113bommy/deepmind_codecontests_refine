#include <bits/stdc++.h>
using namespace std;
map<string, int> h;
map<int, string> v;
int c[10], f[10], g[10], w[6][6];
bool judge(int x) {
  int i, s = 0;
  for (i = 0; i < 4; i++) {
    if (i != x) {
      if (g[i] > g[x])
        s++;
      else if (g[i] == g[x]) {
        if (f[i] > f[x] || f[i] == f[x] && c[i] > c[x] ||
            f[i] == f[x] && c[i] == c[x] && v[i] < v[x])
          s++;
      }
    }
  }
  if (s < 2)
    return true;
  else
    return false;
}
int work(string s) {
  if (h.count(s)) return h[s];
  int x = h.size();
  v[x] = s;
  return h[s] = x;
}
int main() {
  string p, q;
  int i, j, x, y, l, r, s = 0, t = work("BERLAND"), ans1 = 1 << 30, ans2 = 0;
  for (i = 0; i < 5; i++) {
    cin >> p >> q;
    l = work(p);
    r = work(q);
    scanf("%d:%d", &x, &y);
    w[l][r] = w[r][l] = 1;
    c[l] += x;
    c[r] += y;
    f[l] += x - y;
    f[r] += y - x;
    if (x == y)
      g[l]++, g[r]++;
    else if (x > y)
      g[l] += 3;
    else
      g[r] += 3;
  }
  for (i = 0; i < 4; i++) {
    if (i != t) {
      if (!w[i][t]) s = i;
    }
  }
  for (i = 0; i < 60; i++) {
    for (j = 0; j < i; j++) {
      c[t] += i;
      c[s] += j;
      f[t] += i - j;
      f[s] += j - i;
      if (i == j)
        g[t]++, g[s]++;
      else if (i > j)
        g[t] += 3;
      else
        g[s] += 3;
      if (judge(t)) {
        if (i - j < ans1 - ans2 || i - j == ans1 - ans2 && j < ans2)
          ans1 = i, ans2 = j;
      }
      c[t] -= i;
      c[s] -= j;
      f[t] -= i - j;
      f[s] -= j - i;
      if (i == j)
        g[t]--, g[s]--;
      else if (i > j)
        g[t] -= 3;
      else
        g[s] -= 3;
    }
  }
  if (ans1 > 1 << 30)
    puts("IMPOSSIBLE");
  else
    printf("%d:%d\n", ans1, ans2);
  return 0;
}
