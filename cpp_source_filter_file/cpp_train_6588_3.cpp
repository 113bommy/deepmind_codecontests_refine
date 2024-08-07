#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    bool flag = true;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int i = 0, j = n - 1;
    while (i <= j) {
      if (a[i] + b[j] > x) {
        flag = false;
        break;
      }
      i++, j--;
    }
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
