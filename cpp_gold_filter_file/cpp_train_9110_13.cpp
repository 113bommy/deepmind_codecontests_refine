#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, d;
  vector<int> a, b;
  cin >> n >> m >> s >> d;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; cin >> a[i++])
    ;
  sort(a.begin(), a.end());
  a.push_back(m + s + 2);
  for (int i = n - 1; i >= 0; i--)
    if (a[i + 1] - a[i] - 2 >= s) b[i] = 1;
  int x = 0;
  if (a[0] <= s) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  x = a[0] - 1;
  for (int i = 0; i < n; i++)
    if ((b[i] == 1) && (a[i] + 1 - x <= d)) x = a[i + 1] - 1;
  if (x < m) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << "RUN " << a[0] - 1 << endl;
  x = a[0] - 1;
  for (int i = 0; i < n; i++) {
    if ((b[i] == 1) && (a[i] + 1 - x <= d)) {
      cout << "JUMP " << a[i] + 1 - x << endl;
      x = a[i] + 1;
      if (min(a[i + 1], m + 1) - a[i] - 2 != 0)
        cout << "RUN " << min(a[i + 1], m + 1) - a[i] - 2 << endl;
      x = a[i + 1] - 1;
    }
  }
  return 0;
}
