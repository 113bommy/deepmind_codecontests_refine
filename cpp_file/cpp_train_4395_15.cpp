#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6, mod = 998244353;
long long A[maxn + 5], A_ni[maxn + 5];
long long sum1[maxn], sum2[maxn];
void pre() {
  A[0] = A_ni[0] = A[1] = A_ni[1] = 1;
  for (int i = 2; i <= maxn; i++) A[i] = A[i - 1] * i % mod;
  for (int i = 2; i <= maxn; i++)
    A_ni[i] = (mod - mod / i) * A_ni[mod % i] % mod;
  for (int i = 2; i <= maxn; i++) A_ni[i] = A_ni[i] * A_ni[i - 1] % mod;
}
long long C(int upp, int base) {
  return 1LL * A[upp] * A_ni[base] % mod * A_ni[upp - base] % mod;
}
int main() {
  pre();
  string str;
  cin >> str;
  long long ans = 0, n = str.size();
  int sum_q = 0, sum_r = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '?') sum_q++;
    if (str[i] == ')') sum_r++;
  }
  for (int i = n; i >= 0; i--) {
    sum1[i] = (sum1[i + 1] + C(sum_q, i)) % mod;
    sum2[i] = (sum2[i + 1] + C(sum_q - 1, i)) % mod;
  }
  for (int i = 0; i < n; i++) {
    if (str[i] == '?') ans = (ans + sum2[max(0, i + 1 - sum_r)]) % mod;
    if (str[i] == '(') ans = (ans + sum1[max(0, i + 1 - sum_r)]) % mod;
  }
  cout << ans << endl;
  return 0;
}
