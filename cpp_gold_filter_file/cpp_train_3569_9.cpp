#include <bits/stdc++.h>
using namespace std;
long long n, a[2000005], i, s, ss = 0, j;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    s = 0;
    for (j = i + 2; j <= n; j++) {
      s += a[j - 1];
      if (s >= 2 * a[i]) break;
      if ((a[i] ^ a[j]) == s && a[i] >= a[j]) ss++;
    }
    s = 0;
    for (j = i - 2; j >= 1; j--) {
      s += a[j + 1];
      if (s >= 2 * a[i]) break;
      if ((a[i] ^ a[j]) == s && a[i] >= a[j]) ss++;
    }
  }
  cout << ss;
  return 0;
}
