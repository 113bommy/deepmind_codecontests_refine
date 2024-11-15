#include <bits/stdc++.h>
using namespace std;
int arr[200010];
int times[200010];
long long pow2[200010];
long long ans = 1;
int main() {
  int n;
  cin >> n;
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow2[i] = (2 * pow2[i - 1]) % 1000000007;
    if (pow2[i] < 0) pow2[i] += 1000000007;
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    times[i] = 0;
  }
  int t = 1;
  bool flag;
  for (int i = 1; i <= n; i++) {
    if (!times[i]) {
      flag = true;
      int cur = i;
      int count = 1;
      int count2 = 1;
      while (flag) {
        times[cur] = t;
        t++;
        if (times[arr[cur]] < times[i] and times[arr[cur]] > 0) {
          count = times[cur] - times[i] + 1;
          ans = (ans * pow2[count]) % 1000000007;
          if (ans < 0) ans += 1000000007;
          flag = false;
        } else if (times[arr[cur]] < times[cur] and times[arr[cur]] > 0) {
          count = times[arr[cur]] - times[i];
          count2 = times[cur] - times[arr[cur]] + 1;
          ans = (ans * (pow2[count] * (pow2[count2] - 2)) % 1000000007) %
                1000000007;
          if (ans < 0) ans += 1000000007;
          flag = false;
        }
        cur = arr[cur];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
