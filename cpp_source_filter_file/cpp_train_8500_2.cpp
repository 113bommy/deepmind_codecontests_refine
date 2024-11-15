#include <bits/stdc++.h>
using namespace std;
char s[100005];
int n, m, k;
int work() {
  bitset<23000> a, b, c, e;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) {
      (s[j] == '#' ? b : a).set(i * m + j);
      (s[j] == 'E' ? e.set(i * m + j) : 0);
    }
  }
  scanf("%s", s);
  c = a;
  for (int i = 0; i < k; i++) {
    if (c == e) return i;
    if (s[i] == 'U') c = ((c >> m) & a) | (c & (b << m));
    if (s[i] == 'L') c = ((c >> 1) & a) | (c & (b << 1));
    if (s[i] == 'D') c = ((c << m) & a) | (c & (b >> m));
    if (s[i] == 'R') c = ((c << 1) & a) | (c & (b >> 1));
  }
  if (c == a) return k;
  return -1;
}
int main() {
  int i, j;
  while (~scanf("%d %d %d", &n, &m, &k)) {
    printf("%d\n", work());
  }
  return 0;
}
