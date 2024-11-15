#include <bits/stdc++.h>
using namespace std;
bitset<505> g[505][505], f[505][505];
char s[505][505];
int n, m, ans[505];
struct Ask {
  int id, x0, x1, y0, y1;
  void init(int _id) {
    id = _id;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    x0--, y0--, x1--, y1--;
  }
  void print() { printf("%d :(%d,%d) (%d,%d)\n", id, x0, y0, x1, y1); }
};
void solve(int L, int R, queue<Ask> que) {
  int mid = (L + R) / 2;
  queue<Ask> que0, queL, queR;
  while (!que.empty()) {
    if (que.front().x1 < mid)
      queL.push(que.front());
    else if (que.front().x0 > mid)
      queR.push(que.front());
    else
      que0.push(que.front());
    que.pop();
  }
  if (!queL.empty()) solve(L, mid - 1, queL);
  if (!queR.empty()) solve(mid + 1, R, queR);
  if (que0.empty()) return;
  for (int i = mid; i <= R; i++)
    for (int j = 0; j < m; j++) {
      f[i][j].reset();
      if (s[i][j] == '.') {
        if (i == mid) f[i][j][j] = 1;
        if (i > mid) f[i][j] |= f[i - 1][j];
        if (j) f[i][j] |= f[i][j - 1];
      }
    }
  for (int i = mid; i >= L; i--)
    for (int j = m - 1; j >= 0; j--) {
      g[i][j].reset();
      if (s[i][j] == '.') {
        if (i == mid) g[i][j][j] = 1;
        if (i < mid) g[i][j] |= g[i + 1][j];
        if (j != m - 1) g[i][j] |= g[i][j + 1];
      }
    }
  while (!que0.empty()) {
    Ask tmp = que0.front();
    que0.pop();
    ans[tmp.id] = (g[tmp.x0][tmp.y0] & f[tmp.x1][tmp.y1]).any();
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int q;
  scanf("%d", &q);
  Ask tmp;
  queue<Ask> que;
  for (int i = 0; i < q; i++) {
    tmp.init(i);
    que.push(tmp);
  }
  solve(0, m - 1, que);
  for (int i = 0; i < q; i++) printf(ans[i] ? "Yes\n" : "No\n");
  return 0;
}
