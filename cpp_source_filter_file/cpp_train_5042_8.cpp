#include <bits/stdc++.h>
using namespace std;
long long M = 100000007;
long long n, p[100004], dp[10000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i + 1];
  for (int i = 2; i <= n + 1; i++)
    dp[i] = (2 * dp[i - 1] + 2 - dp[p[i - 1]] + M) % M;
  cout << (dp[n + 1] + M) % M << endl;
  return 0;
}
