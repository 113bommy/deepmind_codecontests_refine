#include <bits/stdc++.h>
using namespace std;
int n, a[2000], k;
vector<pair<int, pair<int, int> > > v[9000000];
vector<pair<int, int> > ans, vv;
map<long long, int> m;
bool b[2000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      if (m[sum] == 0) m[sum] = ++k;
      v[m[sum]].push_back({(j - i) + 1, {i, j}});
    }
  }
  for (int i = 1; i <= k; i++) {
    sort(v[i].begin(), v[i].end());
    for (int j = 0; j < v[i].size(); j++) {
      int l = v[i][j].second.first;
      int r = v[i][j].second.second;
      bool t = false;
      for (int z = l; z <= r; z++) {
        if (b[z] == 1) t = true;
      }
      if (t == false) {
        vv.push_back({l + 1, r + 1});
        for (int z = l; z <= r; z++) b[z] = 1;
      }
    }
    for (int j = 0; j < n; j++) b[j] = 0;
    if (ans.size() < vv.size()) ans = vv;
    vv.clear();
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
}
