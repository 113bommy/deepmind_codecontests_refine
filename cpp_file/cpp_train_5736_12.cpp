#include <bits/stdc++.h>
using namespace std;
int n, k, a[200005], num[200005], cnt[200005 * 2], temp[200005 * 2];
long long ans;
int main() {
  scanf("%d%d", &n, &k);
  cnt[n] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == k) memcpy(temp, cnt, sizeof(cnt));
    if (a[i] < k) num[i] = -1;
    if (a[i] == k) num[i] = 0;
    if (a[i] > k) num[i] = 1;
    num[i] += num[i - 1];
    cnt[num[i] + n]++;
    ans += temp[n + num[i]] + temp[n + num[i] - 1];
  }
  printf("%lld\n", ans);
}
