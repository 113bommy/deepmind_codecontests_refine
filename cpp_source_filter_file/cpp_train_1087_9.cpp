#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  int kn = 0, kp = 0;
  for (int i = 0; i < n; i++)
    if (a[i] < 0)
      kn++;
    else if (a[i] > 0)
      kp++;
  if (kn == 1 && kp == 0) {
    int cur = a[0];
    for (int i = 0; i < n; i++) cur = max(cur, a[i]);
    cout << cur << endl;
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    sort(a.begin(), a.end());
    if (a[i] > 0)
      cout << a[i] << ' ';
    else if (a[i] < 0) {
      cnt++;
      if (kn % 2 == 0 || cnt < kn) cout << a[i] << ' ';
    }
  }
  cout << endl;
  return 0;
}
