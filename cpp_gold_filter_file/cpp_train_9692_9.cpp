#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma warning(disable : 4996)
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  char s[n][m];
  int start = -1;
  int x, y, a, b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'B' && start == -1) {
        start = 0;
        x = i;
        y = j;
      }
      if ((j == m - 1) && s[i][j] == 'B' && start != -1) {
        a = i;
        b = j;
        break;
      }
      if (s[i][j] == 'W' && s[i][j - 1] == 'B' && start != -1) {
        a = i;
        b = j;
        break;
      }
    }
  }
  cout << x + (abs(x - a)) / 2 + 1 << " " << y + (abs(x - a)) / 2 + 1;
}
