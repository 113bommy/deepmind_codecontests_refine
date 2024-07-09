#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long double eps = 1e-9;
const long double pi = acos(-1.0);
int mod = 1e+9;
set<int> dif;
int sm[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
                {1, 0},  {1, 1},   {0, 1},  {-1, 1}};
int sm2[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
vector<vector<int> > a;
vector<vector<int> > b;
bool c2(int x, int y) {
  if (x >= 0 && y >= 0 && x < n && y < m)
    return true;
  else
    return false;
}
bool kepka(int x, int y) {
  if (b[x - 1][y] == 1 && b[x - 1][y - 1] == 1 && b[x - 1][y + 1] == 1 &&
      b[x][y - 1] == 1 & b[x][y + 1] == 1)
    return true;
  if (b[x + 1][y] == 1 && b[x + 1][y - 1] == 1 && b[x + 1][y + 1] == 1 &&
      b[x][y - 1] == 1 & b[x][y + 1] == 1)
    return true;
  if (b[x][y - 1] == 1 && b[x - 1][y - 1] == 1 && b[x + 1][y - 1] == 1 &&
      b[x - 1][y] == 1 & b[x + 1][y] == 1)
    return true;
  if (b[x][y + 1] == 1 && b[x + 1][y + 1] == 1 && b[x - 1][y + 1] == 1 &&
      b[x - 1][y] == 1 & b[x + 1][y] == 1)
    return true;
  if (b[x + 1][y - 1] == 1 && b[x][y - 1] == 1 && b[x - 1][y - 1] == 1 &&
      b[x - 1][y] == 1 & b[x - 1][y + 1] == 1)
    return true;
  if (b[x + 1][y - 1] == 1 && b[x][y - 1] == 1 && b[x - 1][y - 1] == 1 &&
      b[x + 1][y] == 1 & b[x + 1][y + 1] == 1)
    return true;
  if (b[x - 1][y + 1] == 1 && b[x][y + 1] == 1 && b[x + 1][y - 1] == 1 &&
      b[x + 1][y] == 1 & b[x + 1][y + 1] == 1)
    return true;
  if (b[x - 1][y + 1] == 1 && b[x][y + 1] == 1 && b[x + 1][y + 1] == 1 &&
      b[x - 1][y] == 1 & b[x - 1][y - 1] == 1)
    return true;
  return false;
}
bool check(int x, int y) {
  int nx = x + 1, ny = y + 1;
  int nx2 = x - 1, ny2 = y - 1;
  if (c2(nx, ny) && c2(nx2, ny2) && b[nx][ny] == 1 && b[nx2][ny2] == 1)
    return true;
  int nx3 = x + 1, ny3 = y - 1;
  int nx4 = x - 1, ny4 = y + 1;
  if (c2(nx3, ny3) && c2(nx4, ny4) && b[nx3][ny3] == 1 && b[nx4][ny4] == 1)
    return true;
  int nx5 = x + 1, ny5 = y;
  int nx6 = x - 1, ny6 = y;
  if (c2(nx5, ny5) && c2(nx6, ny6) && b[nx5][ny5] == 1 && b[nx6][ny6] == 1)
    return true;
  int nx7 = x, ny7 = y + 1;
  int nx8 = x, ny8 = y - 1;
  if (c2(nx7, ny7) && c2(nx8, ny8) && b[nx7][ny7] == 1 && b[nx8][ny8] == 1)
    return true;
  return false;
}
int main() {
  int cnt = 0;
  cin >> n >> m;
  a.resize(n, vector<int>(m));
  b.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      cin >> a[i][k];
    }
  }
  b = a;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      if (a[i][k] == 1) {
        bool fl = 0;
        for (int j = 0; j < 8; j++) {
          int nx = i + sm[j][0];
          int ny = k + sm[j][1];
          if (nx >= 0 && ny >= 0 && nx < n && ny <= m && a[nx][ny] == 0) {
            fl = 1;
            break;
          }
        }
        if (fl == 0) b[i][k] = 2;
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool st = 0;
    for (int k = 0; k < m; k++) {
      if (b[i][k] == 2) {
        int l = 0;
        while (k < m && b[i][k] == 2 && b[i - 1][k] == 2 && b[i + 1][k] == 2)
          l++, k++;
        if (l > 10) {
          int mid = k - 1;
          queue<pair<int, int> > q;
          q.push(make_pair(i, mid));
          b[i][mid] = 3;
          cnt++;
          int lcount = 0;
          while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (check(x, y)) {
              if (kepka(x, y))
                b[x][y] = 7;
              else {
                b[x][y] = 5;
                lcount++;
              }
            } else {
              for (int j = 0; j < 4; j++) {
                int nx = x + sm2[j][0];
                int ny = y + sm2[j][1];
                if (b[nx][ny] == 2) {
                  b[nx][ny] = 3;
                  q.push(make_pair(nx, ny));
                }
              }
            }
          }
          ans.push_back(lcount);
        }
      }
    }
  }
  cout << cnt << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
