#include <bits/stdc++.h>
using namespace std;
int n, a[1000];
int next(int x) {
  int j, k = 0, r[2];
  for (int i = x; i < n && k < 2; i++)
    if (a[i] != -1) r[k++] = i;
  if (k < 2) return n;
  int r0 = r[0], r1 = r[1];
  long long val0 = a[r0], val1 = a[r1];
  if ((val1 - val0) % (r1 - r0)) return r1;
  long long d = (val1 - val0) / (r1 - r0);
  long long s = val1 - (r1 - x) * d;
  if (s <= 0) return r1;
  for (j = r1 + 1; j < n; j++) {
    val1 += d;
    if (val1 <= 0 || (a[j] != -1 && a[j] != val1)) break;
  }
  return j;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int cur = 0, ans = 0;
  while (cur < n) {
    ans++;
    cur = next(cur);
  }
  printf("%d\n", ans);
}
