#include <bits/stdc++.h>
int getward(int dx, int dy);
int getward(int dx, int dy) {
  if (dx > 0) return 1;
  if (dy > 0) return 2;
  if (dx < 0) return 3;
  if (dy < 0) return 4;
  return 0;
}
int check(int w, int ww);
int check(int w, int ww) { return (w % 4 + 1 == ww); }
int main(int argc, const char* argv[]) {
  int n;
  scanf("%d", &n);
  int i;
  int x, y, xx, yy;
  int ward = 3, ww;
  int ans = 0;
  scanf("%d%d", &x, &y);
  for (i = 0; i < n; i++) {
    xx = x;
    yy = y;
    scanf("%d%d", &x, &y);
    ww = ward;
    ward = getward(x - xx, y - yy);
    ans += check(ww, ward);
  }
  printf("%d\n", ans);
  return 0;
}
