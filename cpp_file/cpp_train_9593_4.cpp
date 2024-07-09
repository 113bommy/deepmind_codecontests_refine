#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9, M = 1e7 + 9;
vector<int> dv[M];
int n, k, p = 2, a[N];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 2; j * j <= a[i]; ++j)
      if (a[i] % j == 0) {
        for (dv[j].push_back(i); a[i] % j == 0;) a[i] /= j;
        if (dv[p].size() < dv[j].size()) p = j;
      }
  }
  if (dv[p].size() >= k)
    for (int i = 0; i < k; ++i) cout << dv[p][i] + 1 << " ";
  else {
    unordered_set<int> d;
    for (int i = 0; i < n; ++i) d.insert(i);
    for (int i = 0; i < dv[p].size(); ++i) d.erase(dv[p][i]);
    vector<pair<int, int>> ans;
    for (auto x : d) ans.emplace_back(a[x], x);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; ++i) cout << ans[i].second + 1 << " ";
  }
}
