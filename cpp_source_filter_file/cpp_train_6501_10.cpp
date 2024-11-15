#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 320 + 10;
const int SQRT = 320;
int a[maxn], b[maxn][maxm];
deque<int> d[maxm];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    d[i / SQRT].push_back(a[i]);
    b[a[i]][i / SQRT]++;
  }
  int m, ans = 0;
  cin >> m;
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    l--, r--;
    l = (l + ans) % n;
    r = (r + ans) % n;
    if (r < l) swap(l, r);
    if (type == 1) {
      int st = (l / SQRT);
      int fi = (r / SQRT);
      int shift = d[r / SQRT][r % SQRT];
      d[r / SQRT].erase(d[r / SQRT].begin() + r % SQRT);
      d[l / SQRT].insert(d[l / SQRT].begin() + l % SQRT, shift);
      b[shift][r / SQRT]--;
      b[shift][l / SQRT]++;
      for (int i = st; i < fi; i++) {
        d[i + 1].push_front(d[i].back());
        b[d[i].back()][i + 1]++;
        b[d[i].back()][i]--;
        d[i].pop_back();
      }
    } else {
      int k;
      cin >> k;
      k = (k + ans) % n;
      int st = (l / SQRT) + 1;
      int fi = (r / SQRT) - 1;
      ans = 0;
      for (int i = st; i <= fi; i++) ans += b[k][i];
      if (l / SQRT == r / SQRT) {
        for (int i = l % SQRT; i <= r % SQRT; i++) ans += (d[l / SQRT][i] == k);
      } else {
        for (int i = l % SQRT; i < d[l / SQRT].size(); i++)
          ans += (d[l / SQRT][i] == k);
        for (int i = 0; i <= r % SQRT; i++) ans += (d[r / SQRT][i] == k);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
