#include <bits/stdc++.h>
using namespace std;
int a[10010], b[10010], n;
long long calc(long long x) {
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    s += x * a[i] / b[i];
  }
  return s;
}
long long lower(long long targer) {
  long long left = 1, right = (targer + 1) * 1000000000;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (calc(mid) < targer) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}
long long upper(long long targer) {
  long long left = 1, right = (targer + 1) * 1000000000;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (calc(mid) <= targer) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}
int main() {
  int c;
  while (cin >> n >> c) {
    long long suma = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      suma += a[i];
    }
    if (c < n) {
      cout << 0 << endl;
      continue;
    }
    if (suma == 0) {
      if (c == n) {
        cout << -1 << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    long long ans = upper(c - n) - lower(c - n);
    cout << ans << endl;
  }
  return 0;
}
