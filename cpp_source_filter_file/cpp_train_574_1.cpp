#include <bits/stdc++.h>
using namespace std;
int n, k, num;
int x[100005], y[100005];
int fy[200005];
int ynum;
int count1[200005], from[200005];
long long ans[200005];
int dqid, now;
pair<int, int> fx[200005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
  num = 0;
  for (int i = 1; i <= n; ++i) {
    ++num;
    fy[num] = y[i];
    ++num;
    fy[num] = y[i] + k;
  }
  sort(fy + 1, fy + num + 1);
  ynum = unique(fy + 1, fy + num + 1) - (fy + 1);
  num = 0;
  for (int i = 1; i <= n; ++i) {
    ++num;
    fx[num].first = x[i];
    fx[num].second = 2 * i;
    ++num;
    fx[num].first = x[i] + k;
    fx[num].second = 2 * i + 1;
  }
  sort(fx + 1, fx + num + 1);
  for (int i = 1; i <= num; ++i) {
    dqid = fx[i].second / 2;
    now = fx[i].second % 2;
    if (now == 0)
      now = 1;
    else
      now = -1;
    for (int j = lower_bound(fy + 1, fy + ynum + 1, y[dqid]) - fy;
         fy[j] < y[dqid] + k; ++j) {
      if (count1[j]) {
        ans[count1[j]] +=
            (long long)(fy[j + 1] - fy[j]) * (fx[i].first - from[j]);
      }
      count1[j] += now;
      from[j] = fx[i].first;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
