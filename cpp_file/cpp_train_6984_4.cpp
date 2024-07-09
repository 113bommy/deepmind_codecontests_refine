#include <bits/stdc++.h>
using namespace std;
char grid[200][200];
int n, m;
bool ok(int x, int y, int l) {
  if (x + l <= n && x - l >= 1 && y + l <= m && y - l >= 1)
    if (grid[x + l][y] != '.' && grid[x - l][y] != '.' &&
        grid[x][y + l] != '.' && grid[x][y - l] != '.' && grid[x][y] != '.')
      return true;
  return false;
}
int check(int x, int y, int l) {
  if (ok(x, y, l)) {
    grid[x + l][y] = '#';
    grid[x - l][y] = '#';
    grid[x][y + l] = '#';
    grid[x][y - l] = '#';
    grid[x][y] = '#';
    return check(x, y, l + 1);
  } else
    return l - 1;
}
int main() {
  vector<tuple<int, int, int>> ans;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%s", grid[i + 1] + 1);
  for (int i = 2; i <= n - 1; i++)
    for (int j = 2; j <= m - 1; j++) {
      int temp = check(i, j, 1);
      if (temp) ans.push_back(make_tuple(i, j, temp));
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (grid[i][j] == '*') {
        cout << "-1" << endl;
        return 0;
      }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i])
         << endl;
}
