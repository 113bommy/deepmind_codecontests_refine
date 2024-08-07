#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
unordered_map<int, vector<pair<int, int>>> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> s(n);
  s[0] = a[0];
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + a[i];
  }
  auto query = [&](const int lo, const int hi) {
    int ret = s[hi];
    if (lo > 0) {
      ret -= s[lo - 1];
    }
    return ret;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int s = query(i, j);
      mp[s].emplace_back(i, j);
    }
  }
  auto process = [&](vector<pair<int, int>>& a) {
    sort(a.begin(), a.end(),
         [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
           if (lhs.second != rhs.second) {
             return lhs.second < rhs.second;
           }
           return lhs.first < rhs.first;
         });
    vector<pair<int, int>> ret;
    for (size_t i = 0; i < a.size(); ++i) {
      size_t j = i;
      while (j < a.size() && a[i].second >= a[j].first) {
        ++j;
      }
      ret.emplace_back(move(a[i]));
      i = j - 1;
    }
    return ret;
  };
  vector<pair<int, int>> ret;
  for (auto& it : mp) {
    const auto& lret = process(it.second);
    if (ret.size() < lret.size()) {
      ret = move(lret);
    }
  }
  cout << ret.size() << endl;
  for (auto& it : ret) {
    cout << it.first + 1 << " " << it.second + 1 << endl;
  }
  return 0;
}
