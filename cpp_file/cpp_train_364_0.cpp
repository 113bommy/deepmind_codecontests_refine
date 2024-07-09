#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
bool inp(int i, int j) {
  (i < n && j == n) && inp(i + 1, 0);
  (i < n && j < n) && (cin >> a[i][j]);
  (i < n && j < n) && (inp(i, j + 1));
  return 0;
}
bool floyd(int k, int i, int j) {
  (k < n && i < n && j == n) && floyd(k, i + 1, 0);
  (k < n && i == n) && floyd(k + 1, 0, 0);
  (k < n && i < n && j < n) && floyd(k, i, j + 1);
  (k < n && i < n && j < n) && (a[i][j] = min(a[i][j], a[i][k] + a[k][j]));
  return 0;
}
void go(int &ans, int i) {
  ans = max(ans, *max_element(begin(a[i]), end(a[i])));
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(0);
  cin >> n;
  a.assign(20, vector<int>(20));
  inp(0, 0);
  floyd(0, 0, 0);
  int ans = 0;
  go(ans, 0);
  go(ans, 1);
  go(ans, 2);
  go(ans, 3);
  go(ans, 4);
  go(ans, 5);
  go(ans, 6);
  go(ans, 7);
  go(ans, 8);
  go(ans, 9);
  cout << ans << "\n";
  return 0;
}
