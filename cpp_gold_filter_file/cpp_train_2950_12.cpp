#include <bits/stdc++.h>
using namespace std;
int n, k, h, id[100009], m[100009], v[100009], ans[100009];
bool sortt(int i, int j) { return m[i] != m[j] ? m[i] < m[j] : v[i] < v[j]; }
bool check(long double t) {
  int cnt = k;
  for (int i = n - 1; i >= 0; i--) {
    long double v2 = v[id[i]];
    if (1.0 * cnt * h / v2 < t) {
      ans[cnt] = id[i] + 1;
      cnt--;
    }
    if (cnt == 0) return 1;
  }
  return 0;
}
int main() {
  cin >> n >> k >> h;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    id[i] = i;
  }
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(id, id + n, sortt);
  long double low = 0, high = 1e10, m, mm;
  for (int k = 0; k < 150; k++) {
    m = (low + high) / 2;
    if (check(m))
      high = m, mm = m;
    else
      low = m;
  }
  check(mm);
  for (int i = 1; i <= k; i++) cout << ans[i] << " ";
  return 0;
}
