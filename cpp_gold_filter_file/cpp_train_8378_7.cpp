#include <bits/stdc++.h>
using namespace std;
long long c1 = 0, v1, u, u1 = 0, a[100002], s[100002], h[51];
void qs(int q, int w) {
  int e = q, r = w;
  long long t = a[q + (rand() % (w - q + 1))], y;
  do {
    while (a[e] < t) e++;
    while (a[r] > t) r--;
    if (e <= r) {
      y = a[e];
      a[e] = a[r];
      a[r] = y;
      y = s[e];
      s[e] = s[r];
      s[r] = y;
      e++;
      r--;
    }
  } while (e <= r);
  if (q < r) qs(q, r);
  if (e < w) qs(e, w);
}
long long l(long long e, long long r) {
  long long c;
  c = min(v1, r) - max(c1, e);
  if (c < 0) return 0;
  u = max(c1, e);
  return c + 1;
}
int main() {
  int q, w, t = 0, y;
  h[0] = 1;
  for (w = 1; w < 51; w++) h[w] = h[w - 1] * 2;
  long long e, r;
  scanf("%d%d", &y, &q);
  v1 = h[y - 1] - 1;
  for (; q; q--) {
    scanf("%d%I64d%I64d", &w, &e, &r);
    w--;
    e -= h[w];
    r -= h[w];
    w++;
    e *= h[y - w];
    r++;
    r *= h[y - w];
    r--;
    scanf("%d", &w);
    if (w) {
      c1 = max(c1, e);
      v1 = min(v1, r);
    } else {
      a[t] = e;
      s[t] = r;
      t++;
    }
  }
  if (c1 > v1) {
    printf("Game cheated!");
    return 0;
  }
  a[t] = s[t] = -1;
  t++;
  a[t] = s[t] = h[y - 1];
  qs(0, t - 1);
  for (w = 0; w < t;) {
    r = s[w];
    for (w++; r >= a[w]; w++) r = max(r, s[w]);
    e = l(r + 1, a[w] - 1);
    u1 += e;
  }
  if (u1 == 0) printf("Game cheated!");
  if (u1 == 1) printf("%I64d", u + h[y - 1]);
  if (u1 > 1) printf("Data not sufficient!");
  return 0;
}
