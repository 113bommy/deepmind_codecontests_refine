#include <bits/stdc++.h>
using namespace std;
const int N = (int)1005, mod = (int)0;
int n, m, d[2][N][N];
pair<int, int> p[2][N][N];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
pair<int, int> q[N * N];
void bfs(int sx, int sy, int d[N][N], pair<int, int> par[N][N]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) d[i][j] = 1e9;
  int h = 0, t = 0;
  d[sx][sy] = 0;
  par[sx][sy] = make_pair(-1, -1);
  q[t++] = make_pair(sx, sy);
  while (h < t) {
    auto cur = q[h++];
    for (int dir = 0; dir < 8; ++dir) {
      int first = cur.first + dx[dir], second = cur.second + dy[dir];
      if (first >= 0 && first < n && second >= 0 && second < m) {
        if (d[first][second] > d[cur.first][cur.second] + 1) {
          d[first][second] = d[cur.first][cur.second] + 1;
          par[first][second] = cur;
          q[t++] = make_pair(first, second);
        }
      }
    }
  }
}
int wx, wy, bx, by;
void go(int &sx, int &sy, int col, int bow) {
  int nx = p[col][sx][sy].first;
  int ny = p[col][sx][sy].second;
  cout << nx + 1 << ' ' << ny + 1 << endl;
  sx = nx;
  sy = ny;
  if (bx == wx && by == wy) exit(0);
  if (bow == 1 && sx == n / 2 && sy == m / 2 - 1) exit(0);
  if (bow == 0 && sx == n / 2 - 1 && sy == m / 2 - 1) exit(0);
}
void inp(int &sx, int &sy) {
  int first, second;
  cin >> first >> second;
  sx = first - 1;
  sy = second - 1;
}
int main() {
  cin >> n >> m;
  bfs(n / 2 - 1, m / 2 - 1, d[0], p[0]);
  bfs(n / 2, m / 2 - 1, d[1], p[1]);
  cin >> wx >> wy >> bx >> by;
  --wx, --wy, --bx, --by;
  if ((wx + wy) % 2 == (bx + by) % 2) {
    if (d[1][bx][by] < d[0][wx][wy]) {
      cout << "BLACK" << endl;
      while (true) {
        inp(wx, wy);
        go(bx, by, 1, 1);
      }
    } else if (d[0][bx][by] <= d[0][wx][wy]) {
      cout << "BLACK" << endl;
      while (make_pair(bx, by) != make_pair(n / 2 - 1, m / 2 - 1)) {
        inp(wx, wy);
        go(bx, by, 0, 1);
      }
      while (true) {
        inp(wx, wy);
        go(bx, by, 1, 1);
      }
    } else {
      cout << "WHITE" << endl;
      while (true) {
        go(wx, wy, 0, 0);
        inp(bx, by);
      }
    }
  } else {
    if (d[0][wx][wy] <= d[1][bx][by]) {
      cout << "WHITE" << endl;
      while (true) {
        go(wx, wy, 0, 0);
        inp(bx, by);
      }
    } else if (d[1][wx][wy] + 1 <= d[1][bx][by]) {
      cout << "WHITE" << endl;
      while (make_pair(wx, wy) != make_pair(n / 2, m / 2 - 1)) {
        go(wx, wy, 1, 0);
        inp(bx, by);
      }
      while (true) {
        go(wx, wy, 0, 0);
        inp(bx, by);
      }
    } else {
      cout << "BLACK" << endl;
      while (true) {
        inp(wx, wy);
        go(bx, by, 1, 1);
      }
    }
  }
}
