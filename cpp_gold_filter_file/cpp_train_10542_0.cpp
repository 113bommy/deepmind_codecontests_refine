#include <bits/stdc++.h>
using namespace std;
const int maxn = 520;
int n, m, S[maxn][maxn], ans;
struct point {
  int x, y;
} R[maxn], B[maxn];
inline bool cmp(const point &a, const point &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
inline long long cross(point &a, point &b, point &c) {
  return (long long)(b.x - a.x) * (c.y - a.y) -
         (long long)(c.x - a.x) * (b.y - a.y);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> R[i].x >> R[i].y;
  for (int i = 0; i < m; i++) cin >> B[i].x >> B[i].y;
  sort(R, R + n, cmp);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (R[i].x != R[j].x)
        for (int k = 0; k < m; k++)
          if (B[k].x > R[i].x && B[k].x <= R[j].x &&
              cross(R[i], R[j], B[k]) > 0)
            S[i][j]++;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if (S[i][k] == S[i][j] + S[j][k]) ans++;
  cout << ans << endl;
  return 0;
}
