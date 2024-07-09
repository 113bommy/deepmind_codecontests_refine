#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int n, a[maxn], freq[101];
int solve(int d, int v) {
  unordered_map<int, int> presum;
  presum[0] = -1;
  int ans = 0;
  int sum = 0;
  int minsum = 0, maxsum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == d) sum++;
    if (a[i] == v) sum--;
    if (sum >= minsum && sum <= maxsum) {
      ans = max(ans, i - presum[sum]);
    } else
      presum[sum] = i;
    minsum = min(minsum, sum);
    maxsum = max(maxsum, sum);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ans = 0;
  cin >> n;
  int d = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]] += 1;
    if (freq[d] < freq[a[i]]) d = a[i];
  }
  for (int i = 1; i <= 100; i++) {
    if (d == i) continue;
    ans = max(ans, solve(d, i));
  }
  cout << ans;
  return 0;
}
