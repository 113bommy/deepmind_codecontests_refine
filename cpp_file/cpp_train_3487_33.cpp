#include <bits/stdc++.h>
using namespace std;
int const INF = (int)1e9 + 1e3;
long long const INFL = (long long)1e18 + 1e6;
mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> ll_distr;
long long rnd(long long a, long long b) {
  return ll_distr(tw) % (b - a + 1) + a;
}
namespace hungary {
const int N = 210;
int a[N][N];
int ans[N];
int calc(int n, int m) {
  ++n, ++m;
  vector<int> u(n), v(m), p(m), prev(m);
  for (int i = 1; i < n; ++i) {
    p[0] = i;
    int x = 0;
    vector<int> mn(m, INF);
    vector<int> was(m, 0);
    while (p[x]) {
      was[x] = 1;
      int ii = p[x], dd = INF, y = 0;
      for (int j = 1; j < m; ++j)
        if (!was[j]) {
          int cur = a[ii][j] - u[ii] - v[j];
          if (cur < mn[j]) mn[j] = cur, prev[j] = x;
          if (mn[j] < dd) dd = mn[j], y = j;
        }
      for (int j = 0; j < m; ++j) {
        if (was[j])
          u[p[j]] += dd, v[j] -= dd;
        else
          mn[j] -= dd;
      }
      x = y;
    }
    while (x) {
      int y = prev[x];
      p[x] = p[y];
      x = y;
    }
  }
  for (int j = 1; j < m; ++j) {
    ans[p[j]] = j;
  }
  return -v[0];
}
}  // namespace hungary
void solve() {
  int n;
  cin >> n;
  vector<vector<vector<int>>> cost(2, vector<vector<int>>(n, vector<int>(n)));
  for (int q = 0; q < 2; ++q) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> cost[q][i][j];
      }
    }
  }
  vector<vector<int>> matr(n, vector<int>(n));
  vector<int> order;
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (__builtin_popcount(mask) == n / 2) {
      order.push_back(mask);
    }
  }
  shuffle(order.begin(), order.end(), tw);
  int ans = 0;
  for (int mask : order) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          hungary::a[i + 1][j + 1] = -cost[0][i][j];
        } else {
          hungary::a[i + 1][j + 1] = -cost[1][i][j];
        }
      }
    }
    ans = max(ans, -hungary::calc(n, n));
    if (clock() > 1.9 * CLOCKS_PER_SEC) {
      break;
    }
  }
  cout << ans << "\n";
}
int main() {
  cout << setprecision(15) << fixed;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_count = 1;
  for (int test = 1; test <= test_count; ++test) {
    solve();
  }
}
