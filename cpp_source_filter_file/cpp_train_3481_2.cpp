#include <bits/stdc++.h>
using namespace std;
int x[4], y[4];
char str[10];
bool gao(int rx, int ry, int kx, int ky, int bx, int by) {
  if (rx == kx && bx == kx && by >= min(ry, ky) && by <= max(ry, ky))
    return false;
  if (ry == ky && by == ky && bx >= min(rx, kx) && bx <= max(rx, kx))
    return false;
  return true;
}
int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%s", str);
    x[i] = str[0] - 'a';
    y[i] = str[1] - '1';
  }
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int kx = x[3] + dx, ky = y[3] + dy;
      if (kx >= 0 && kx < 8 && ky >= 0 && ky < 8) {
        int beat = 0;
        if (gao(x[0], y[0], kx, ky, x[2], y[2]) && (kx == x[0] || ky == y[0]) &&
            (kx != x[0] || ky != y[0]))
          beat = 1;
        if (gao(x[0], y[0], kx, ky, x[2], y[2]) && (kx == x[0] || ky == y[0]) &&
            (kx != x[0] || ky != y[0]))
          beat = 1;
        if (abs(kx - x[2]) <= 1 && abs(ky - y[2]) <= 1) beat = 1;
        if (!beat) {
          puts("OTHER");
          return 0;
        }
      }
    }
  }
  puts("CHECKMATE");
  return 0;
}
