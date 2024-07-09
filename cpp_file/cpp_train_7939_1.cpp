#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long b[n];
  long long c[n];
  int x = n - 1;
  int z;
  for (int i = 0; i < n; i += 2) {
    b[i] = a[x];
    c[i] = a[x];
    x--;
    z = x;
  }
  int y = z;
  int ff = 0;
  for (int i = 1; i < n; i += 2) {
    b[i] = a[y];
    c[i] = a[ff];
    ff++;
    y--;
  }
  long long ans1 = 0, ans2 = 0;
  for (int i = 1; i < n - 1; i++) {
    if (b[i] < b[i - 1] && b[i] < b[i + 1]) {
      ans1++;
    }
    if (c[i] < c[i - 1] && c[i] < c[i + 1]) {
      ans2++;
    }
  }
  if (ans1 >= ans2) {
    cout << ans1 << endl;
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  } else {
    cout << ans2 << endl;
    for (int i = 0; i < n; i++) {
      cout << c[i] << " ";
    }
    cout << endl;
  }
}
