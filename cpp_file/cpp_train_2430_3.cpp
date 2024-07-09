#include <bits/stdc++.h>
using namespace std;
char buf[1000010];
string B, N;
int main(void) {
  int i, j;
  long long MOD;
  scanf("%s", buf);
  B = buf;
  scanf("%s", buf);
  N = buf;
  cin >> MOD;
  long long x = 0;
  for ((i) = 0; (i) < (int)(B.length()); (i)++)
    x = (x * 10 + (B[i] - '0')) % MOD;
  for (i = N.length() - 1;; i--)
    if (N[i] != '0') break;
  N[i]--;
  for (j = i + 1; j < N.length(); j++) N[j] = '9';
  long long power = 1;
  for ((i) = 0; (i) < (int)(N.length()); (i)++) {
    long long tmp = 1;
    for ((j) = 0; (j) < (int)(10); (j)++) tmp = tmp * power % MOD;
    power = tmp;
    for ((j) = 0; (j) < (int)(N[i] - '0'); (j)++) power = power * x % MOD;
  }
  long long ans = power * (x + MOD - 1) % MOD;
  if (ans == 0) ans = MOD;
  cout << ans << endl;
  return 0;
}
