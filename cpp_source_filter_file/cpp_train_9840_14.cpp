#include <bits/stdc++.h>
using namespace std;
const int max_n = 1111111, inf = 1111111111;
int n;
long long sum[2][max_n];
map<int, pair<int, int> > q;
pair<int, int> a[2][max_n];
int main() {
  scanf("%d", &n);
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[k][i].first);
      a[k][i].second = i;
    }
  }
  sort(a[0], a[0] + n);
  sort(a[1], a[1] + n);
  for (int k = 0; k < 2; ++k) {
    sum[k][0] = 1;
    for (int i = 0; i < n; ++i) {
      sum[k][i + 1] = sum[k][i] + a[k][i].first;
    }
  }
  for (int i = 0; i <= n; ++i) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (sum[1][mid] <= sum[0][i]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (q.count(sum[0][i] - sum[1][l])) {
      pair<int, int> p = q[sum[0][i] - sum[1][l]];
      printf("%d\n", i - p.first);
      for (int j = p.first + 1; j <= i; ++j) {
        printf("%d ", a[0][j - 1].second + 1);
      }
      printf("\n");
      printf("%d\n", l - p.second);
      for (int j = p.second + 1; j <= l; ++j) {
        printf("%d ", a[1][j - 1].second + 1);
      }
      printf("\n");
      return 0;
    } else {
      q[sum[0][i] - sum[1][i]] = make_pair(i, l);
    }
  }
  return 0;
}
