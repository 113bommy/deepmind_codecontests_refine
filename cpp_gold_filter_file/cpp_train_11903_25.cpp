#include <bits/stdc++.h>
using namespace std;
long long k, ans, t, dp[1111111];
string s;
int main() {
  dp[0] = 1;
  cin >> k >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') t++;
    if (t >= k) ans += dp[t - k];
    dp[t]++;
  }
  cout << ans;
}
