#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> dp(n, -1), dp2(n, -1);
  dp[0] = 1;
  dp2[0] = 1;
  for (int i = 1; i < n; i++) {
    long long q, z = -1;
    q = s[i] - 'a';
    for (int j = i - 1; j >= 0; j--) {
      long long k;
      k = s[j] - 'a';
      if (k > q) {
        z = j;
      }
    }
    if (z == -1) {
      dp[i] = dp[i - 1];
      dp2[i] = dp[i];
    } else {
      long long kol;
      kol = dp[z];
      for (int j = z; j < i; j++) {
        if (kol != dp[j]) {
          cout << "NO" << endl;
          return 0;
        }
      }
      if (kol == 1) {
        dp[i] = 0;
        dp2[i] = 0;
      } else {
        dp[i] = 1;
        dp2[i] = 1;
      }
      swap(dp[z], dp[i]);
      string s1 = "";
      for (int j = 0; j < z; j++) {
        s1 += s[j];
      }
      s1 += s[i];
      for (int j = z; j < n; j++) {
        if (j != i) {
          s1 += s[j];
        }
      }
      s = s1;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << dp2[i];
  }
  return 0;
}
