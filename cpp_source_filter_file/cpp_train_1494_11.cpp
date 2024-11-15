#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 9;
int a[MAX], l, r = MAX, n, m, k;
vector<int> b[MAX];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i], b[a[i]].push_back(i);
  while (l < r - 1) {
    int mid = l + r >> 1;
    bool flg = false;
    for (int i = 0; i < m; i++)
      if (b[i].size() >= mid)
        for (int j = mid - 1; j < b[i].size(); j++)
          if (b[i][j] - b[i][j - mid + 1] - mid + 1 <= k) flg = true;
    if (flg)
      l = mid;
    else
      r = mid;
  }
  cout << l;
  return 0;
}
