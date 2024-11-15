#include <bits/stdc++.h>
const char c[] = "XAC";
struct Str {
  int len;
  int l, r, ac;
  Str() {}
  Str(int len, int l, int r, int ac) : len(len), l(l), r(r), ac(ac) {}
  Str friend operator+(Str p, Str q) {
    return Str(p.len + q.len, p.l, q.r, p.ac + q.ac + (p.r == 1 && q.l == 2));
  }
};
int k, x, n, m;
Str s[100];
char ans[111];
int valid(Str p) {
  if (p.len == 1) return p.l == p.r && p.ac == 0;
  if (p.len == 2) return p.ac == (p.l == 1 && p.r == 2);
  return (p.len - (p.l != 1) - (p.r != 2) >= 2 * p.ac);
}
void print(Str p) {
  int L, R;
  ans[0] = c[p.l];
  ans[p.len - 1] = c[p.r];
  L = 1;
  R = p.len - 2;
  if (p.l == 1 && p.ac) --p.ac, ans[L++] = 'C';
  if (p.r == 2 && p.ac) --p.ac, ans[R--] = 'A';
  for (; p.ac > 0; --p.ac) {
    ans[L] = 'A';
    ans[L + 1] = 'C';
    L += 2;
  }
  for (; L <= R; ++L) {
    ans[L] = 'X';
  }
  ans[p.len] = 0;
  printf("%s\n", ans);
}
int f() {
  int i, j, o;
  s[1].len = n;
  s[2].len = m;
  for (i = 0; i < (n / 2 + 1) * 9; ++i) {
    s[1].ac = i / 9;
    s[1].l = i % 3;
    s[1].r = (i / 3) % 3;
    if (!valid(s[1])) continue;
    for (j = 0; j < (m / 2 + 1) * 9; ++j) {
      s[2].ac = j / 9;
      s[2].l = j % 3;
      s[2].r = (j / 3) % 3;
      if (!valid(s[2])) continue;
      for (o = 3; o <= k; ++o) {
        s[o] = s[o - 2] + s[o - 1];
        if (s[o].ac > x) break;
      }
      if (o <= k) continue;
      if (s[k].ac == x) {
        print(s[1]);
        print(s[2]);
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d%d%d", &k, &x, &n, &m);
  if (!f()) printf("Happy new year!\n");
  return 0;
}
