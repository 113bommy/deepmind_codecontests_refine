#include <bits/stdc++.h>
using namespace std;
const int MaxN = 25 + 10;
char in[MaxN][MaxN];
bool check(int r1, int r2, int c1, int c2) {
  for (int i = r1; i <= r2; ++i)
    for (int j = c1; j <= c2; ++j)
      if (in[i][j] == '1') return false;
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> in[i][j];
  int ans = 0;
  for (int r1 = 0; r1 < n; ++r1)
    for (int c1 = 0; c1 < m; ++c1)
      for (int r2 = r1; r2 < n; ++r2)
        for (int c2 = c1; c2 < m; ++c2)
          if (check(r1, r2, c1, c2))
            ans = max(ans, 2 * (r2 - r1 + 1 + c2 - c1 + 1));
  cout << ans;
}
