#include <bits/stdc++.h>
using namespace std;
int ans[10000];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int j = 0; j < n; j++) {
    string s;
    cin >> s;
    for (int i = 0; i < m; i++)
      if (s[i] == 'U' && j % 2 == 0)
        ans[i]++;
      else if (s[i] == 'R' && i + j < m)
        ans[i + j]++;
      else if (s[i] == 'L' && i - j >= 0)
        ans[i - j]++;
  }
  for (int i = 0; i < m; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
