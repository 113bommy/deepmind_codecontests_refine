#include <bits/stdc++.h>
using namespace std;
int tmp[100010 * 4], age[100010 * 4], c[100010], n, k,
    tt = 0, tot = 0, T, val[100010], ans[100010], mx[100010 * 12];
struct Person {
  int sup, ag, id;
} p[100010];
struct Query {
  int a, b, al, ar, msp, id;
  void init(int _id) {
    scanf("%d%d", &a, &b);
    msp = max(p[a].sup, p[b].sup);
    al = max(p[a].ag - k, p[b].ag - k);
    ar = min(p[a].ag + k, p[b].ag + k);
    id = _id;
  }
} q[100010];
bool cmp1(Person _, Person __) { return _.sup < __.sup; }
bool cmp2(Query _, Query __) { return _.msp < __.msp; }
void add(int x) {
  while (x <= tot) c[x]++, x += ((x) & (-x));
}
int sum(int x) {
  int res = 0;
  while (x > 0) res += c[x], x -= ((x) & (-x));
  return res;
}
int get(int tg) {
  int l = 1, r = tot;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (age[mid] <= tg)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
void update(int t, int x, int nl, int nr, int v) {
  if (nl == nr) {
    mx[x] = max(mx[x], v);
    return;
  }
  int mid = (nl + nr) >> 1;
  if (t <= mid)
    update(t, x << 1, nl, mid, v);
  else
    update(t, x << 1 | 1, mid + 1, nr, v);
  mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
int query(int ml, int mr, int x, int nl, int nr) {
  int res = 0;
  if (ml <= nl && nr <= mr) return mx[x];
  int mid = (nl + nr) >> 1;
  if (ml <= mid) res = max(res, query(ml, mr, x << 1, nl, mid));
  if (mr > mid) res = max(res, query(ml, mr, x << 1 | 1, mid + 1, nr));
  return res;
}
void pre() {
  int rec = -1;
  for (int i = 0; i <= tt; i++) {
    if (tmp[i] > rec) {
      rec = tmp[i];
      age[++tot] = tmp[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    int tx = get(p[i].ag), tl = get(p[i].ag - k), tr = get(p[i].ag + k);
    add(tx);
    val[p[i].id] = sum(tr) - sum(tl - 1);
  }
}
void work() {
  int now = n;
  for (int i = T; i >= 1; i--) {
    while (p[now].sup >= q[i].msp && now > 0) {
      update(get(p[now].ag), 1, 1, tot, val[p[now].id]);
      now--;
    }
    if (q[i].al > q[i].ar) {
      ans[q[i].id] = -1;
      continue;
    }
    int tl = get(q[i].al), tr = get(q[i].ar);
    int tp = query(tl, tr, 1, 1, tot);
    ans[q[i].id] = (tp == 0) ? -1 : tp;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].sup);
  for (int i = 1; i <= n; i++) {
    int ta;
    scanf("%d", &ta);
    tmp[++tt] = ta;
    tmp[++tt] = ta - k;
    tmp[++tt] = ta + k;
    p[i].ag = ta, p[i].id = i;
  }
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) q[i].init(i);
  sort(tmp + 1, tmp + tt + 1);
  sort(p + 1, p + n + 1, cmp1);
  sort(q + 1, q + T + 1, cmp2);
  pre();
  work();
  for (int i = 1; i <= T; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
