#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;
vector<int> ans;
void reverse(vector<int> &a, int p) {
  reverse(a.begin(), a.begin() + p);
  if (p) ans.push_back(p * 2);
  for (int i = 0; (i) < p; ++(i))
    if (a[i] >= 2) a[i] ^= 1;
}
vector<int> get(string &a) {
  int n = (int)a.size() / 2;
  vector<int> a1(n);
  for (int i = 0; (i) < n; ++(i)) {
    auto s = a.substr(i * 2, 2);
    if (s == "00") {
      a1[i] = 0;
    } else if (s == "11") {
      a1[i] = 1;
    } else if (s == "01") {
      a1[i] = 3;
    } else {
      a1[i] = 2;
    }
  }
  return a1;
}
int check(vector<int> a, vector<int> &b) {
  int n = a.size();
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == b[i]) continue;
    if (b[i] == 0 || b[i] == 1) {
      for (int j = 0; (j) < i; ++(j))
        if (a[j] == b[i]) {
          reverse(a, j + 1);
          break;
        }
      reverse(a, i + 1);
    } else {
      for (int j = 0; (j) < i; ++(j))
        if (a[j] == b[i]) {
          reverse(a, j + 1);
          break;
        }
      if ((a[0] ^ 1) != b[i]) {
        for (int j = 0; (j) < i + 1; ++(j))
          if ((a[j] ^ 1) == b[i]) {
            reverse(a, j + 1);
            break;
          }
        reverse(a, 1);
      }
      reverse(a, i + 1);
    }
    if (a[i] != b[i]) {
      return -1;
    }
  }
  return ans.size();
}
int check(int mid, vector<int> a, vector<int> &b) {
  ans.clear();
  reverse(a, mid);
  return check(a, b);
}
void solve() {
  string a1, b1;
  cin >> a1 >> b1;
  int n = (int)a1.size() / 2;
  auto a = get(a1), b = get(b1);
  int lmd = n;
  int k = rand() % (n + 1);
  int cur = check(k, a, b);
  while (lmd) {
    int l = max(0, k - lmd);
    int r = min(n, k + lmd);
    lmd /= 2;
    int cl = check(l, a, b);
    int cr = check(r, a, b);
    int mx = min(cl, max(cr, cur));
    if (cl == mx) {
      k = l;
      cur = cl;
    }
    if (cr == mx) {
      k = r;
      cur = cr;
    }
  }
  if (cur == -1 || cur > n * 2 + 1) {
    cout << "-1\n";
    return;
  }
  check(k, a, b);
  cout << ans.size() << "\n";
  for (auto &x : ans) cout << x << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests = 1;
  cin >> tests;
  for (int _ = 0; (_) < tests; ++(_)) {
    solve();
  }
  return 0;
}
