#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10, Max = 86500;
int to(string a) { return 10 * (a[0] - '0') + a[1] - '0'; }
int get() {
  string s;
  cin >> s;
  string A = s.substr(0, 2), B = s.substr(3, 2), C = s.substr(6, 2);
  return to(A) * 60 * 60 + to(B) * 60 + to(C);
}
int ss[Max], a[maxn], ans[maxn], C;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int n, m, t, sm = 0;
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    a[i] = get();
  }
  bool reach = 0;
  int pt = 0;
  for (int i = 0; i < Max; i++) {
    while (pt < n && a[pt] == i) {
      if (sm + ss[i] < m) {
        ++C;
        ss[i]++, ss[i + t]--;
      } else {
        ss[a[pt - 1] + t]++;
        ss[i + t]--;
      }
      ans[pt++] = C;
    }
    sm += ss[i];
    reach |= sm == m;
  }
  if (reach == 0) return cout << "No solution\n", 0;
  cout << C << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
