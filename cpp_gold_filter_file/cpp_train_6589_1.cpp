#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s1 = 0, s2 = 0;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] != '4' && a[i] != '7') {
      cout << "NO";
      return 0;
    }
  }
  for (int i = 0; i < n / 2; i++) {
    s1 += a[i] - 48;
  }
  for (int i = n / 2; i < n; i++) {
    s2 += a[i] - 48;
  }
  if (s1 != s2) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
