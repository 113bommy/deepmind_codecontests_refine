#include <bits/stdc++.h>
using namespace std;
long long n, k;
int p;
inline bool check(long long x) {
  if (n % 2) {
    if ((n + 1) / 2 < k)
      return x % 2 == 0 || x >= n - 2 * (k - (n + 1) / 2);
    else
      return (k >= 1 && x == n) || (x % 2 == 0 && x >= n - 2 * k + 3);
  } else {
    if (n / 2 < k)
      return x % 2 == 0 || x >= n - 2 * (k - n / 2) + 1;
    else
      return x % 2 == 0 && x >= n - 2 * (k - 1);
  }
}
int main() {
  cin >> n >> k >> p;
  for (int i = 0; i < p; i++) {
    long long x;
    cin >> x;
    if (check(x))
      cout << "X";
    else
      cout << ".";
  }
  puts("");
  return 0;
}
