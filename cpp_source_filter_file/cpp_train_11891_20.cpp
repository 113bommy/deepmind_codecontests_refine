#include <bits/stdc++.h>
using namespace std;
long long a[1003][2000];
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  a[1][1] = 1;
  a[1][0] = 1;
  for (int i = 2; i <= max(n, m); i++) {
    a[i][0] = 1;
    for (int j = 1; j <= i; j++)
      a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % 1000000007;
  }
  long long ans = (a[n - 1][k + k] * a[m - 1][k + k]) % 1000000007;
  cout << ans << endl;
  return 0;
}
