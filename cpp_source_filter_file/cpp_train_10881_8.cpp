#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  long long ans = n;
  ans -= (n / 2) + (n / 3) + (n / 5) + (n / 7);
  ans += n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35;
  ans -= n / 30 + n / 70 + n / 105;
  ans += n / 210;
  printf("%lld\n", ans);
  return 0;
}
