#include <bits/stdc++.h>
using namespace std;
struct Line {
  int x0, y0, x1, y1, to;
} a[110000];
struct query {
  int x, y, to;
  char k;
  long long t;
} b[110000];
int n, m, q, h, i, j, Time, xx, yy, now, cc[110000 * 4], cover[110000 * 4],
    to[110000], fa[110000][51], go[110000], s[256], tx[4] = {0, 0, 1, -1},
                                                    ty[4] = {1, -1, 0, 0};
long long l[110000][51], ansx, ansy;
void read(int &x) {
  char k;
  for (k = getchar(); k <= 32; k = getchar())
    ;
  for (x = 0; '0' <= k; k = getchar()) x = x * 10 + k - '0';
}
void read(long long &x) {
  char k;
  for (k = getchar(); k <= 32; k = getchar())
    ;
  for (x = 0; '0' <= k; k = getchar()) x = x * 10 + k - '0';
}
void mkt(int k, int q, int h) {
  if (q < h) {
    mkt(k * 2, q, (q + h) / 2);
    mkt(k * 2 + 1, (q + h) / 2 + 1, h);
  } else
    to[q] = k;
}
void modify(int k, int q, int h, int l, int r, int x) {
  if (l <= q && h <= r)
    cc[k] = Time, cover[k] = x;
  else if (r <= (q + h) / 2)
    modify(k * 2, q, (q + h) / 2, l, r, x);
  else if ((q + h) / 2 < l)
    modify(k * 2 + 1, (q + h) / 2 + 1, h, l, r, x);
  else
    modify(k * 2, q, (q + h) / 2, l, r, x),
        modify(k * 2 + 1, (q + h) / 2 + 1, h, l, r, x);
}
int get(int x) {
  x = to[x];
  int ans1 = 0, ans2 = 0;
  while (x) {
    if (cc[x] > ans1) ans1 = cc[x], ans2 = cover[x];
    x /= 2;
  }
  return ans2;
}
bool cmp1(Line x, Line y) { return min(x.x0, x.x1) < min(y.x0, y.x1); }
bool cmp_1(query x, query y) { return x.x < y.x; }
bool cmp2(Line x, Line y) { return max(x.x0, x.x1) > max(y.x0, y.x1); }
bool cmp_2(query x, query y) { return x.x > y.x; }
bool cmp3(Line x, Line y) { return min(x.y0, x.y1) < min(y.y0, y.y1); }
bool cmp_3(query x, query y) { return x.y < y.y; }
bool cmp4(Line x, Line y) { return max(x.y0, x.y1) > max(y.y0, y.y1); }
bool cmp_4(query x, query y) { return x.y > y.y; }
bool cmp5(Line x, Line y) { return x.to < y.to; }
bool cmp_5(query x, query y) { return x.to < y.to; }
void Go(int k, int x, int y, long long t) {
  if (a[k].x0 < a[k].x1)
    ansx = t + x;
  else if (a[k].x0 > a[k].x1)
    ansx = -t + x;
  else
    ansx = x;
  if (a[k].y0 < a[k].y1)
    ansy = t + y;
  else if (a[k].y0 > a[k].y1)
    ansy = -t + y;
  else
    ansy = y;
}
int main() {
  s['R'] = 0;
  s['L'] = 1;
  s['D'] = 2;
  s['U'] = 3;
  read(n);
  read(m);
  mkt(1, 0, m);
  for (i = 1; i <= n; i++)
    read(a[i].x0), read(a[i].y0), read(a[i].x1), read(a[i].y1), a[i].to = i;
  read(q);
  for (i = 1; i <= q; i++) {
    read(b[i].x);
    read(b[i].y);
    for (b[i].k = getchar(); b[i].k <= 32; b[i].k = getchar())
      ;
    if (b[i].k == 'U')
      b[i].k = 'R';
    else if (b[i].k == 'D')
      b[i].k = 'L';
    else if (b[i].k == 'R')
      b[i].k = 'D';
    else
      b[i].k = 'U';
    read(b[i].t);
    b[i].to = i;
  }
  sort(a + 1, a + n + 1, cmp1);
  sort(b + 1, b + q + 1, cmp_1);
  Time++;
  cc[1] = Time;
  cover[1] = 0;
  h = 1;
  for (i = 1; i <= n; i++) {
    Time++;
    while (h <= q && b[h].x < min(a[i].x0, a[i].x1)) {
      if (b[h].k == 'U') go[b[h].to] = get(b[h].y);
      h++;
    }
    if (a[i].y0 == a[i].y1 && a[i].x0 > a[i].x1) fa[a[i].to][0] = get(a[i].y0);
    modify(1, 0, m, min(a[i].y0, a[i].y1), max(a[i].y0, a[i].y1), a[i].to);
  }
  while (h <= q) {
    if (b[h].k == 'U') go[b[h].to] = get(b[h].y);
    h++;
  }
  sort(a + 1, a + n + 1, cmp2);
  sort(b + 1, b + q + 1, cmp_2);
  Time++;
  cc[1] = Time;
  cover[1] = 0;
  h = 1;
  for (i = 1; i <= n; i++) {
    Time++;
    while (h <= q && b[h].x > max(a[i].x0, a[i].x1)) {
      if (b[h].k == 'D') go[b[h].to] = get(b[h].y);
      h++;
    }
    if (a[i].y0 == a[i].y1 && a[i].x0 < a[i].x1) fa[a[i].to][0] = get(a[i].y0);
    modify(1, 0, m, min(a[i].y0, a[i].y1), max(a[i].y0, a[i].y1), a[i].to);
  }
  while (h <= q) {
    if (b[h].k == 'D') go[b[h].to] = get(b[h].y);
    h++;
  }
  sort(a + 1, a + n + 1, cmp3);
  sort(b + 1, b + q + 1, cmp_3);
  Time++;
  cc[1] = Time;
  cover[1] = 0;
  h = 1;
  for (i = 1; i <= n; i++) {
    Time++;
    while (h <= q && b[h].y < min(a[i].y0, a[i].y1)) {
      if (b[h].k == 'L') go[b[h].to] = get(b[h].x);
      h++;
    }
    if (a[i].x0 == a[i].x1 && a[i].y0 > a[i].y1) fa[a[i].to][0] = get(a[i].x0);
    modify(1, 0, m, min(a[i].x0, a[i].x1), max(a[i].x0, a[i].x1), a[i].to);
  }
  while (h <= q) {
    if (b[h].k == 'L') go[b[h].to] = get(b[h].x);
    h++;
  }
  sort(a + 1, a + n + 1, cmp4);
  sort(b + 1, b + q + 1, cmp_4);
  Time++;
  cc[1] = Time;
  cover[1] = 0;
  h = 1;
  for (i = 1; i <= n; i++) {
    Time++;
    while (h <= q && b[h].y > max(a[i].y0, a[i].y1)) {
      if (b[h].k == 'R') go[b[h].to] = get(b[h].x);
      h++;
    }
    if (a[i].x0 == a[i].x1 && a[i].y0 < a[i].y1) fa[a[i].to][0] = get(a[i].x0);
    modify(1, 0, m, min(a[i].x0, a[i].x1), max(a[i].x0, a[i].x1), a[i].to);
  }
  while (h <= q) {
    if (b[h].k == 'R') go[b[h].to] = get(b[h].x);
    h++;
  }
  sort(a + 1, a + n + 1, cmp5);
  sort(b + 1, b + q + 1, cmp_5);
  for (i = 1; i <= n; i++)
    if (fa[i][0])
      l[i][0] = abs(a[i].x1 - a[fa[i][0]].x1) + abs(a[i].y1 - a[fa[i][0]].y1);
  for (j = 1; j <= 50; j++)
    for (i = 1; i <= n; i++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
      l[i][j] = l[i][j - 1] + l[fa[i][j - 1]][j - 1];
      if (l[i][j] > 10000000000000000LL) l[i][j] = 10000000000000000LL;
    }
  for (i = 1; i <= q; i++) {
    j = s[b[i].k];
    if (!go[i])
      ansx = b[i].t * tx[j] + b[i].x, ansy = b[i].t * ty[j] + b[i].y;
    else {
      if (a[go[i]].x0 != a[go[i]].x1) {
        yy = a[go[i]].y0;
        if (min(a[go[i]].x0, a[go[i]].x1) <= b[i].x &&
            b[i].x <= max(a[go[i]].x0, a[go[i]].x1))
          xx = b[i].x;
        else if (b[i].k == 'D')
          xx = max(a[go[i]].x0, a[go[i]].x1);
        else
          xx = min(a[go[i]].x0, a[go[i]].x1);
      } else {
        xx = a[go[i]].x0;
        if (min(a[go[i]].y0, a[go[i]].y1) <= b[i].y &&
            b[i].y <= max(a[go[i]].y0, a[go[i]].y1))
          yy = b[i].y;
        else if (b[i].k == 'L')
          yy = max(a[go[i]].y0, a[go[i]].y1);
        else
          yy = min(a[go[i]].y0, a[go[i]].y1);
      }
      if (b[i].t <= abs(b[i].x - xx) + abs(b[i].y - yy))
        ansx = b[i].t * tx[j] + b[i].x, ansy = b[i].t * ty[j] + b[i].y;
      else {
        b[i].t -= abs(b[i].x - xx) + abs(b[i].y - yy);
        if (b[i].t <= abs(xx - a[go[i]].x1) + abs(yy - a[go[i]].y1))
          Go(go[i], xx, yy, b[i].t);
        else {
          b[i].t -= abs(xx - a[go[i]].x1) + abs(yy - a[go[i]].y1);
          now = go[i];
          for (j = 50; j >= 0; j--)
            if (fa[now][j] && b[i].t >= l[now][j])
              b[i].t -= l[now][j], now = fa[now][j];
          if (a[fa[now][0]].x0 != a[fa[now][0]].x1) {
            yy = a[fa[now][0]].y0;
            if (min(a[fa[now][0]].x0, a[fa[now][0]].x1) <= a[now].x1 &&
                a[now].x1 <= max(a[fa[now][0]].x0, a[fa[now][0]].x1))
              xx = a[now].x1;
            else if (a[now].x1 > max(a[fa[now][0]].x0, a[fa[now][0]].x1))
              xx = max(a[fa[now][0]].x0, a[fa[now][0]].x1);
            else
              xx = min(a[fa[now][0]].x0, a[fa[now][0]].x1);
          } else {
            xx = a[fa[now][0]].x0;
            if (min(a[fa[now][0]].y0, a[fa[now][0]].y1) <= a[now].y1 &&
                a[now].y1 <= max(a[fa[now][0]].y0, a[fa[now][0]].y1))
              yy = a[now].y1;
            else if (a[now].y1 > max(a[fa[now][0]].y0, a[fa[now][0]].y1))
              yy = max(a[fa[now][0]].y0, a[fa[now][0]].y1);
            else
              yy = min(a[fa[now][0]].y0, a[fa[now][0]].y1);
          }
          if (!fa[now][0] ||
              b[i].t <= abs(a[now].x1 - xx) + abs(a[now].y1 - yy))
            Go(now, a[now].x1, a[now].y1, b[i].t);
          else
            Go(fa[now][0], xx, yy,
               b[i].t - abs(a[now].x1 - xx) - abs(a[now].y1 - yy));
        }
      }
    }
    if (ansx < 0) ansx = 0;
    if (ansx > m) ansx = m;
    if (ansy < 0) ansy = 0;
    if (ansy > m) ansy = m;
    printf("%I64d %I64d\n", ansx, ansy);
  }
}
