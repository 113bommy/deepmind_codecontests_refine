#include <bits/stdc++.h>
using namespace std;
template <class T, class T1>
int chkmin(T &x, const T1 &y) {
  return x > y ? x = y, 1 : 0;
}
template <class T, class T1>
int chkmax(T &x, const T1 &y) {
  return x < y ? x = y, 1 : 0;
}
const int MAXN = (1 << 10);
vector<vector<pair<int, int>>> fig = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 1}, {1, 1}, {0, 0}},
    {{1, 1}, {1, 0}, {0, 1}},
    {{1, 0}, {1, 1}, {0, 0}},
};
int n, m;
string a[MAXN];
void read() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
void add(vector<vector<pair<int, int>>> &ans, int x, int y, int model) {
  vector<pair<int, int>> to_add = fig[model];
  for (auto &it : to_add) {
    it.first += x;
    it.second += y;
    if (a[it.first][it.second] == '1')
      a[it.first][it.second] = '0';
    else
      a[it.first][it.second] = '1';
  }
  ans.push_back(to_add);
}
void solve() {
  vector<vector<pair<int, int>>> answer;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - (m % 2); j += 2) {
      if (a[i][j] == '0' && a[i][j + 1] == '0') {
        continue;
      } else if (a[i][j] == '1' && a[i][j + 1] == '1') {
        add(answer, i, j, 0);
        continue;
      } else if (a[i][j] == '1') {
        add(answer, i, j, 3);
        continue;
      } else if (a[i][j + 1] == '1') {
        add(answer, i, j, 2);
        continue;
      }
    }
    if (m % 2 == 1 && a[i][m - 1] == '1') {
      add(answer, i, m - 2, 2);
    }
  }
  for (int i = 0; i < m - (m % 2); i += 2) {
    if (a[n - 1][i] == '0' && a[n - 1][i + 1] == '0') {
      continue;
    } else if (a[n - 1][i] == '1' && a[n - 1][i + 1] == '1') {
      add(answer, n - 2, i, 0);
      add(answer, n - 2, i, 1);
      continue;
    } else if (a[n - 1][i] == '1') {
      add(answer, n - 2, i, 0);
      add(answer, n - 2, i, 2);
      add(answer, n - 2, i, 3);
    } else {
      add(answer, n - 2, i, 1);
      add(answer, n - 2, i, 2);
      add(answer, n - 2, i, 3);
    }
  }
  if (m % 2 == 1 && a[n - 1][m - 1] == '1') {
    add(answer, n - 2, m - 2, 1);
    add(answer, n - 2, m - 2, 2);
    add(answer, n - 2, m - 2, 3);
  }
  cout << ((int)answer.size()) << '\n';
  for (auto it : answer) {
    for (int j = 0; j < 3; j++) {
      cout << it[j].first + 1 << " " << it[j].second + 1 << " ";
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    read();
    solve();
  }
  return 0;
}
