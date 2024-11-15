#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 15;
const int maxb = 1000000 + 15;
int n, a[maxn];
int ans1[maxb], ans2[maxb], sum;
int p1, p2, p3;
int done(int x) {
  ans1[++sum] = p1;
  ans2[sum] = x;
  a[x] -= a[p1];
  a[p1] <<= 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += (a[i] > 0);
  if (sum < 2) {
    printf("-1\n");
    return 0;
  }
  if (sum == 2) {
    printf("0\n");
    return 0;
  }
  sum = 0;
  int i;
  for (p1 = 1, p2 = 2, i = 3; i <= n; i++)
    for (p3 = i;;) {
      if (a[p1] > a[p2]) swap(p1, p2);
      if (a[p2] > a[p3]) swap(p2, p3);
      if (a[p1] > a[p2]) swap(p1, p2);
      if (a[p1] == 0) break;
      for (int xx = a[p2] / a[p1]; xx > 0; xx >>= 1)
        if (xx & 1)
          done(p2);
        else
          done(p3);
    }
  printf("%d\n", sum);
  for (int i = 1; i <= sum; i++) printf("%d %d\n", ans1[i], ans2[i]);
  return 0;
}
