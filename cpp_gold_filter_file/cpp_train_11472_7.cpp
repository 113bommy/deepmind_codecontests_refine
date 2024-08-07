#include <bits/stdc++.h>
using namespace std;
long long t[524289], l[100001], r[100001], sl[524289], sr[524289];
int main() {
  int n, m = 0, ans = 0;
  long long k, len = (long long)2e18;
  for (int i = 0; t[i] < 9e16; i++) {
    t[++m] = t[i] * 10 + 4;
    t[++m] = t[i] * 10 + 7;
  }
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &l[i], &r[i]);
    len = min(len, r[i] - l[i]);
  }
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  int j = 0;
  for (int i = 1; i <= m; i++) {
    if (1.0 * j * (t[i] - t[i - 1]) > 2e18)
      sl[i] = k + 1;
    else
      sl[i] = min(sl[i - 1] + j * (t[i] - t[i - 1]), k + 1);
    while (j < n && r[j + 1] <= t[i]) {
      j++;
      sl[i] = min(sl[i] + t[i] - r[j], k + 1);
    }
  }
  j = n + 1;
  for (int i = m; i; i--) {
    if (1.0 * (n - j + 1) * (t[i + 1] - t[i]) > 2e18)
      sr[i] = k + 1;
    else
      sr[i] = min(sr[i + 1] + (n - j + 1) * (t[i + 1] - t[i]), k + 1);
    while (j > 1 && l[j - 1] >= t[i]) {
      j--;
      sr[i] = min(sr[i] + l[j] - t[i], k + 1);
    }
  }
  j = 0;
  for (int i = 1; i <= m; i++) {
    while (j < m && t[j + 1] - t[i] <= len && sl[j + 1] + sr[i] <= k) j++;
    ans = max(ans, j - i + 1);
  }
  cout << ans;
  return 0;
}
