#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, b, a, c;
  cin >> n >> a >> b >> c;
  unsigned long long r = 0;
  unsigned long long x = b - c;
  if (a > x) {
    if (n >= b) {
      r += ((n - b) / x) + 1;
      n -= r * x;
    }
  }
  r += n / a;
  cout << r;
  return 0;
}
