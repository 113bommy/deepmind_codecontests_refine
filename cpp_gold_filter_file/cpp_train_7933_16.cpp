#include <bits/stdc++.h>
using namespace std;
char **a = new char *[8], **s = new char *[8], **d;
void l(int e, int r) {
  if (((0 <= e) && (e < 8)) && ((0 <= r) && (r < 8)))
    if (s[e][r] != 'S') s[e][r] = 'M';
}
int main() {
  int q, w, e, r, t;
  for (w = 0; w < 8; w++) {
    a[w] = new char[9];
    s[w] = new char[9];
    scanf("%s", a[w]);
  }
  for (w = 0; w < 8; w++) {
    for (e = 0; e < 8; e++)
      for (r = 0; r < 8; r++) s[e][r] = a[e][r];
    for (e = 0; e < 8; e++)
      for (r = 0; r < 8; r++)
        if (a[e][r] == 'M') {
          l(e + 1, r);
          l(e + 1, r - 1);
          l(e + 1, r + 1);
          l(e - 1, r);
          l(e - 1, r - 1);
          l(e - 1, r + 1);
          l(e, r + 1);
          l(e, r - 1);
        }
    for (e = 7; e >= 0; e--)
      for (r = 0; r < 8; r++)
        if (a[e][r] == 'S') {
          s[e][r] = '.';
          if (e < 7) s[e + 1][r] = 'S';
        }
    d = a;
    a = s;
    s = d;
  }
  for (e = 0; e < 8; e++)
    for (r = 0; r < 8; r++)
      if (a[e][r] == 'M') {
        printf("WIN");
        return 0;
      }
  printf("LOSE");
  return 0;
}
