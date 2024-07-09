#include <bits/stdc++.h>
using namespace std;
int n;
long double L;
long double len[400010], sp[400010];
int cnt = 0;
long double r[400010];
long double Ans = 0.0;
long double sum[400010];
pair<long double, int> seq[400010];
long double mn[400010 << 2], tag[400010 << 2];
void make_tag(int k, long double t) {
  tag[k] += t;
  mn[k] += t;
}
void push_down(int k) {
  make_tag(k << 1, tag[k]);
  make_tag(k << 1 | 1, tag[k]);
  tag[k] = 0.0;
}
void build(int k, int l, int r) {
  if (l == r) {
    mn[k] = sum[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
}
long double query(int k, int l, int r, int L, int R) {
  if (l == L && r == R) return mn[k];
  push_down(k);
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(k << 1, l, mid, L, R);
  else if (mid < L)
    return query(k << 1 | 1, mid + 1, r, L, R);
  else
    return min(query(k << 1, l, mid, L, mid),
               query(k << 1 | 1, mid + 1, r, mid + 1, R));
}
void Add(int k, int l, int r, int L, int R, long double t) {
  if (l == L && r == R) {
    make_tag(k, t);
    return;
  }
  push_down(k);
  int mid = (l + r) >> 1;
  if (R <= mid)
    Add(k << 1, l, mid, L, R, t);
  else if (mid < L)
    Add(k << 1 | 1, mid + 1, r, L, R, t);
  else {
    Add(k << 1, l, mid, L, mid, t);
    Add(k << 1 | 1, mid + 1, r, mid + 1, R, t);
  }
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
}
int main() {
  scanf("%d%Lf", &n, &L);
  long double pre = 0.0;
  int x, y;
  for (int i = (1); i <= (n); ++i) {
    scanf("%d%d%Lf", &x, &y, &sp[cnt + 2]);
    len[++cnt] = x - pre;
    len[++cnt] = y - x;
    pre = y;
  }
  len[++cnt] = L - pre;
  sp[cnt] = 0;
  for (int i = (1); i <= (cnt); ++i) {
    sum[i] = sum[i - 1];
    sum[i] -= len[i];
    double R;
    if (sp[i] > 0.0)
      R = len[i] / sp[i];
    else
      R = L;
    Ans += -R;
    r[i] = R - len[i] / (sp[i] + 2);
    sum[i] -= (-R) * (sp[i] + 1);
    seq[i] = pair<long double, int>(sp[i] + 1, i);
  }
  build(1, 1, cnt);
  sort(seq + 1, seq + cnt + 1);
  for (int t = (1); t <= (cnt); ++t) {
    int i = seq[t].second;
    long double tmp = min(query(1, 1, cnt, i, cnt), r[i] * (sp[i] + 1));
    Ans += tmp / (sp[i] + 1);
    Add(1, 1, cnt, i, cnt, -tmp);
  }
  Ans = -Ans;
  printf("%.12Lf\n", Ans);
  return 0;
}
