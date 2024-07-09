#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const long long LINF = 1000000000000000000;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int cur = 1;
  for (auto x : mp) {
    mp[x.first] = cur;
    cur++;
  }
  vector<int> dp(n + 10);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int idx = mp[a[i]];
    dp[idx] = dp[idx - 1] + 1;
    chmax(ans, dp[idx]);
  }
  cout << n - ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) solve();
}
