#include <bits/stdc++.h>
using namespace std;
void func() {
  long long n;
  cin >> n;
  long long x = 0, y = 0, t = n;
  while (n >= 0) {
    if (n % 7 == 0) {
      y = n / 7;
      break;
    }
    ++x;
    n = n - (x * 4);
  }
  if ((4 * x + 7 * y) != t) {
    cout << -1 << "\n";
    return;
  }
  for (long long i = 0; i < x; ++i) cout << 4;
  for (long long i = 0; i < y; ++i) cout << 7;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    func();
  }
}
