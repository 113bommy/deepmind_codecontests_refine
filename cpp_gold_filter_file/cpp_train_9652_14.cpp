#include <bits/stdc++.h>
int l[21], s[21], m;
int work1(int d) {
  int temp = 0;
  for (int i = m; i >= d; i--) temp = temp * 2 + s[i];
  return (temp);
}
int work2(int d) {
  if (s[d] == 1)
    return (work1(d));
  else if (d == m)
    return (2 * s[d] - 1);
  else
    return (work1(d + 1) * 2 + s[d] * 2 + work2(d + 1));
}
void move(int d, int a, int c, int b) {
  if (d > m) return;
  if (d < m) move(d + 1, a, b, c);
  for (int i = 1; i <= s[d]; i++) printf("%d %d\n", a, c);
  if (d < m) move(d + 1, b, c, a);
}
void draw(int d, int a, int c, int b) {
  int i;
  if (s[d] == 1)
    move(d, a, c, b);
  else if (d == m) {
    s[d]--;
    move(d, a, b, c);
    printf("%d %d\n", a, c);
    move(d, b, c, a);
  } else {
    move(d + 1, a, c, b);
    for (i = 1; i <= s[d]; i++) printf("%d %d\n", a, b);
    move(d + 1, c, a, b);
    for (i = 1; i <= s[d]; i++) printf("%d %d\n", b, c);
    draw(d + 1, a, c, b);
  }
}
int main() {
  int n, i, ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &l[i]);
  m = 1;
  s[1] = 1;
  for (i = 2; i <= n; i++) {
    if (l[i] != l[i - 1]) {
      m++;
      s[m] = 1;
    } else
      s[m]++;
  }
  ans = work2(1);
  printf("%d\n", ans);
  draw(1, 1, 3, 2);
  return (0);
}
