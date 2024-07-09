#include <bits/stdc++.h>
using namespace std;
long long pow(long long b, long long e) {
  long long res = 1;
  if (e > 0) {
    if (e % 2 == 0) {
      long long x = pow(b, e / 2);
      res = (x * x) % 1000000007;
    } else {
      res = (b * pow(b, e - 1)) % 1000000007;
    }
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  long long res = pow(3, 3 * n) - pow(7, n) + 1000000007;
  cout << res % 1000000007;
  return 0;
}
