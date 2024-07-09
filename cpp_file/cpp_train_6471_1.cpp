#include <bits/stdc++.h>
using namespace std;
long long pow(long long di, long long c) {
  long long ans = 1;
  while (c--) ans *= di;
  return ans;
}
long long dig[3000000];
int main() {
  for (int i = 1; i < 16; i++) {
    dig[i] = i * 9 * (long long)pow(10, i - 1) + dig[i - 1];
  }
  long long k;
  cin >> k;
  for (int i = 0; i < 16; i++) {
    if (k > dig[i] && k <= dig[i + 1]) {
      int ws = i + 1;
      k -= dig[i];
      long long t2 = k % ws == 0 ? ws : k % ws;
      long long t1 = (k - 1) / ws + 1;
      long long start = pow(10, ws - 1);
      start += t1 - 1;
      printf("%lld\n", start / (long long)pow(10, ws - t2) % 10);
      break;
    }
  }
  return 0;
}
