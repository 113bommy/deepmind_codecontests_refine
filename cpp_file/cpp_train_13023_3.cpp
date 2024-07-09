#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
vector<bool> used(4);
vector<vector<long long>> graph(4);
vector<vector<long long>> comp;
void DFS(long long v) {
  used[v] = true;
  comp[(long long)(comp).size() - 1].push_back(v);
  for (auto u : graph[v]) {
    if (!used[u]) DFS(u);
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<pair<long long, long long>, long long>> c(n);
  long long aaans = 0;
  for (long long qwe = 0; qwe < n; ++qwe) {
    long long c1, v, c2;
    cin >> c1 >> v >> c2;
    c1--;
    c2--;
    graph[c1].push_back(c2);
    graph[c2].push_back(c1);
    c[qwe] = {{c1, c2}, v};
  }
  for (long long i = 0; i < 4; ++i) {
    if (!used[i]) {
      comp.resize((long long)(comp).size() + 1);
      DFS(i);
    }
  }
  for (auto st : comp) {
    vector<long long> cnt(4);
    long long res = 0;
    for (long long qwe = 0; qwe < n; ++qwe) {
      long long c1, v, c2;
      c1 = c[qwe].first.first, c2 = c[qwe].first.second, v = c[qwe].second;
      if (count((st).begin(), (st).end(), c1) &&
          count((st).begin(), (st).end(), c2)) {
        res += v;
        cnt[c1]++;
        cnt[c2]++;
      }
    }
    long long ans = 0;
    if ((cnt[0] % 2 + cnt[1] % 2 + cnt[2] % 2 + cnt[3] % 2) <= 2) {
      ans = res;
    }
    for (long long j = 0; j < n; ++j) {
      if (count((st).begin(), (st).end(), c[j].first.first) &&
          count((st).begin(), (st).end(), c[j].first.second)) {
        cnt[c[j].first.first]--, cnt[c[j].first.second]--;
        res -= c[j].second;
        if ((cnt[0] % 2 + cnt[1] % 2 + cnt[2] % 2 + cnt[3] % 2) <= 2)
          ans = max(ans, res);
        cnt[c[j].first.first]++, cnt[c[j].first.second]++;
        res += c[j].second;
      }
    }
    aaans = max(aaans, ans);
  }
  cout << aaans << '\n';
}
