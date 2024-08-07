#include <bits/stdc++.h>
using namespace std;
struct note {
  int x1, y1, x2, y2, id;
} A;
vector<note> q;
int n, m, Q;
char s[505][505];
bool ans[505];
bitset<505> f[505][505], g[505][505];
void work(int l, int r, vector<note> q) {
  int Q = q.size(), mid = (l + r) / 2;
  if (!Q) return;
  for (int i = mid; i >= l; i--)
    for (int j = m - 1; j >= 0; j--) {
      f[i][j].reset();
      if (s[i][j] != '.') continue;
      if (i == mid) f[i][j][j] = true;
      if (i < mid) f[i][j] |= f[i + 1][j];
      if (j < m - 1) f[i][j] |= f[i][j + 1];
    }
  for (int i = mid; i < r; i++)
    for (int j = 0; j < m; j++) {
      g[i][j].reset();
      if (s[i][j] != '.') continue;
      if (i == mid) g[i][j][j] = true;
      if (i > mid) g[i][j] |= g[i - 1][j];
      if (j) g[i][j] |= g[i][j - 1];
    }
  vector<note> q1, q2;
  for (int i = 0; i < Q; i++)
    if (q[i].x2 < mid)
      q1.push_back(q[i]);
    else if (q[i].x1 > mid)
      q2.push_back(q[i]);
    else
      ans[q[i].id] = (f[q[i].x1][q[i].y1] & g[q[i].x2][q[i].y2]).any();
  q.clear();
  work(l, mid, q1);
  work(mid + 1, r, q2);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++)
    scanf("%d%d%d%d", &A.x1, &A.y1, &A.x2, &A.y2), A.x1--, A.y1--, A.x2--,
        A.y2--, A.id = i, q.push_back(A);
  work(0, n, q);
  for (int i = 0; i < Q; i++) printf(ans[i] ? "YES\n" : "NO\n");
  return 0;
}
