#include <bits/stdc++.h>
using namespace std;
const int maxn = 50033, seed = 31131;
unsigned int Pow[maxn], h[maxn];
int mark[maxn], n;
char s[maxn];
unsigned int H(int x, int y) { return h[y] - h[x - 1] * Pow[y - x + 1]; }
int ask(int f, int x, int y) {
  int l = 1, r = f ? n - max(x, y) + 1 : min(x, y), m;
  while (l < r) {
    m = (l + r + 1) / 2;
    if (f ? H(x, x + m - 1) == H(y, y + m - 1)
          : H(x - m + 1, x) == H(y - m + 1, y))
      l = m;
    else
      r = m - 1;
  }
  return l;
}
bool check(int l) {
  for (int i = 1; i + l - 1 <= n; i += l)
    if (s[i] == s[i + l] && ask(0, i, i + l) + ask(1, i, i + l) - 1 >= l)
      return 1;
  return 0;
}
void modify(int l) {
  for (int i = 1; i + 2 * l - 1 <= n; i++)
    if (H(i, i + l - 1) == H(i + l, i + l + l - 1)) mark[i] = l, i += l - 1;
  int L = 0;
  for (int i = 1; i <= n; i++)
    if (mark[i] == l)
      i += l - 1;
    else
      s[++L] = s[i];
  n = L;
  for (int i = 1; i <= n; i++) h[i] = h[i - 1] * seed + s[i];
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  Pow[0] = 1;
  for (int i = 1; i <= n; i++)
    Pow[i] = Pow[i - 1] * seed, h[i] = h[i - 1] * seed + s[i];
  for (int i = 1; i + i <= n; i++)
    if (check(i)) modify(i);
  s[n + 1] = 0, puts(s + 1);
  return 0;
}
