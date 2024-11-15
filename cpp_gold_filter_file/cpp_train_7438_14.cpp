#include <bits/stdc++.h>
using namespace std;
int n, r, w, s[3005][3005], anss, ans[9], l[9], sto;
pair<int, int> v[3005];
double dist(int a, int b) {
  double aa = a, bb = b;
  return aa * aa + bb * bb;
}
pair<int, int> MP(int a, int b) {
  pair<int, int> z;
  z.first = a;
  z.second = b;
  return z;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  return dist(a.first, a.second) > dist(b.first, b.second);
}
void dfs(int x, int ww, int sum) {
  sto++;
  if (!(sto & ((1 << 24) - 1))) {
    sto = -1;
    return;
  }
  if (x == n + 1) {
    if (sum > anss) {
      anss = sum;
      for (int i = 1; i <= n; i++) ans[i] = l[i];
    }
    return;
  }
  int ss = 0;
  for (int i = ww; i <= w; i++) {
    ss = 0;
    for (int j = 1; j < x; j++) ss += s[i][l[j]];
    l[x] = i;
    dfs(x + 1, i, sum + ss);
    if (sto == -1) return;
  }
}
int main() {
  scanf("%d%d", &n, &r);
  for (int i = -r; i <= r; i++)
    for (int j = -r; j <= r; j++)
      if (dist(i, j) <= r * r) v[++w] = MP(i, j);
  sort(&v[1], &v[w + 1], cmp);
  for (int i = 1; i <= w; i++)
    for (int j = 1; j <= w; j++)
      s[i][j] = dist(v[i].first - v[j].first, v[i].second - v[j].second);
  w = min(w, int(double(r) * 2 * 3.15));
  dfs(1, 1, 0);
  printf("%d\n", anss);
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", v[ans[i]].first, v[ans[i]].second);
  return 0;
}
