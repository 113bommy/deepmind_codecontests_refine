#include <bits/stdc++.h>
using namespace std;
set<pair<long long int, long long int>> adj[200001];
void solve() {
  long long int i, j, k, l, m, n, o, p;
  cin >> n >> m;
  vector<pair<long long int, pair<long long int, long long int>>> vp;
  for (i = 0; i < m; i++) {
    cin >> j >> k >> l;
    vp.push_back({l, {j, k}});
  }
  set<long long int> people, roads;
  sort(vp.begin(), vp.end());
  for (i = 0; i < m; i++) {
    people.insert(vp[i].second.first);
    roads.insert(vp[i].second.second);
    if (people.size() == n && roads.size() == n) {
      cout << vp[i].first << " ";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  long long int t = 1, i = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (t--) {
    solve();
    i++;
  }
  return 0;
}
