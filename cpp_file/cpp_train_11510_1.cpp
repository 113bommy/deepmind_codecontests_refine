#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1000050];
long long v[2000010];
long long all[2000010];
int last[2000010];
int c[1000050];
int ans[1000050];
struct qj {
  int l;
  int r;
  int num;
};
qj s[2000010];
bool cmp(const qj& a, const qj& b) { return a.r < b.r; }
int lowbit(int x) { return x & -x; }
void update(int pos, long long x) {
  while (pos <= n) {
    c[pos] = c[pos] ^ x;
    pos += lowbit(pos);
  }
  return;
}
long long getans(int x) {
  long long ans = 0;
  while (x > 0) {
    ans = ans ^ c[x];
    x -= lowbit(x);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  v[0] = 1e18;
  all[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    v[i] = a[i];
    all[i] = all[i - 1] ^ a[i];
  }
  sort(v, v + n + 1);
  int len = unique(v, v + n + 1) - v;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &s[i].l, &s[i].r);
    s[i].num = i;
  }
  sort(s, s + m, cmp);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (now == m) break;
    int k = lower_bound(v, v + len, a[i]) - v;
    update(i, v[k]);
    if (last[k] != 0) update(last[k], v[k]);
    last[k] = i;
    while (now < m && s[now].r == i) {
      ans[s[now].num] = all[s[now].r] ^ all[s[now].l - 1] ^
                        getans(s[now].l - 1) ^ getans(s[now].r);
      now++;
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
