#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) solve();
  return 0;
}
bool used[1621][1621];
int m[1621][1621];
int c[1621][1621];
bool d[1621][1621];
int color = 1;
int w, h;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int s = 0;
struct same {
  bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
    return abs(x.first - y.first) + abs(x.second - y.second) < 4;
  }
};
void bfs(int x, int y) {
  queue<pair<int, int> > q;
  q.push(pair<int, int>(x, y));
  while (!q.empty()) {
    int a = q.front().first;
    int b = q.front().second;
    if (abs(a - x) + abs(b - y) > 2) break;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      if (m[a + dx[i]][b + dy[i]] && !c[a + dx[i]][b + dy[i]]) {
        c[a + dx[i]][b + dy[i]] = color;
        q.push(pair<int, int>(a + dx[i], b + dy[i]));
      }
    }
  }
}
void corner(int x, int y) {
  int cnt = 0;
  for (int i = x - 1; i <= x + 1; ++i)
    for (int j = y - 1; j <= y + 1; ++j) {
      cnt += m[i][j];
    }
  int cnt2 = 0;
  for (int i = x - 2; i <= x + 2; ++i)
    for (int j = y - 2; j <= y + 2; ++j) {
      cnt2 += m[i][j];
    }
  if (cnt <= 4 && cnt2 <= 9) {
    if (!c[x][y]) {
      d[x][y] = true;
      c[x][y] = color;
      bfs(x, y);
      ++s;
    }
  }
}
void dfs(int x, int y) {
  if (x < 5 || y < 5 || x > 6 + h || y > 6 + w) return;
  if (!m[x][y]) return;
  if (used[x][y]) return;
  used[x][y] = true;
  corner(x, y);
  for (int i = 0; i < 4; ++i) dfs(x + dx[i], y + dy[i]);
}
void solve() {
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> m[i + 5][j + 5];
    }
  }
  vector<int> groups;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!used[5 + i][5 + j] && m[i + 5][j + 5]) {
        ++color;
        dfs(5 + i, 5 + j);
        groups.push_back(s);
        s = 0;
      }
    }
  }
  cout << groups.size() << endl;
  sort(groups.begin(), groups.end());
  for (int i = 0; i < groups.size(); ++i) cout << groups[i] << ' ';
}
