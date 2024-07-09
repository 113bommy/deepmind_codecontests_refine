#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch())
                .count());
const long long int N = 1000005;
const long long int LG = 22;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  vector<pair<pair<long long int, long long int>, long long int>> v(m);
  long long int mx = 0;
  for (long long int i = 0; i < m; i++) {
    cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    mx = max(mx, v[i].second);
  }
  long long int lo = 1, hi = mx, ans = -1;
  while (lo <= hi) {
    long long int mid = (lo + hi) >> 1;
    vector<long long int> x(n + 1), y(n + 1);
    for (long long int i = 0; i < m; i++) {
      if (v[i].second <= mid) x[v[i].first.first]++, y[v[i].first.second]++;
    }
    bool ok = true;
    for (long long int i = 1; i <= n; i++) {
      if (x[i] == 0 or y[i] == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
