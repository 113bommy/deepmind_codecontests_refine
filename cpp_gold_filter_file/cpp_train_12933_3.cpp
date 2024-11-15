#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int n, p[maxn], c[maxn];
bool vis[maxn];
bool check(vector<int>& v, int i) {
  for (int j = 0; j < i; j++) {
    bool flag = true;
    int color = c[v[j]];
    for (int k = j + i; k < v.size(); k += i) {
      if (c[v[k]] != color) {
        flag = false;
        break;
      }
    }
    if (flag) return true;
  }
  return false;
}
int solve(vector<int>& v) {
  int m = v.size();
  int ret = m;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      if (check(v, i)) ret = min(ret, i);
      if (check(v, m / i)) ret = min(ret, m / i);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      vis[i] = false;
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        vector<int> v;
        int cur = i;
        while (true) {
          v.push_back(cur);
          vis[cur] = true;
          cur = p[cur];
          if (cur == i) break;
        }
        ans = min(ans, solve(v));
      }
    }
    cout << ans << '\n';
  }
}
