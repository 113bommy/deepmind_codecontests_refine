#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10, M = 50000;
unsigned char hi[1 << 26];
unsigned short lo[1 << 26];
void add(int b) {
  ++lo[b];
  if (lo[b] == M) lo[b] = 0, ++hi[b];
}
int ask(int b) { return (int)hi[b] * M + (int)lo[b]; }
char s[N];
int main() {
  int n = 0;
  for (scanf("%s", s); s[n]; n++)
    ;
  int p[27];
  memset(p, -1, sizeof(p));
  int q[26], k = -1;
  int b, c;
  s[n] = 26 + 'a';
  c = s[0] - 'a';
  p[c] = 0;
  q[++k] = c;
  for (int i = 1; i <= n; i++) {
    b = 0;
    c = s[i] - 'a';
    for (int x = k; x > p[c]; --x) {
      b |= 1 << q[x];
      add(b);
    }
    if (~p[c]) {
      for (int x = p[c]; x < k; x++) {
        q[x] = q[x + 1];
        --p[q[x]];
      }
      q[k] = c;
      p[c] = k;
    } else {
      q[++k] = c;
      p[c] = k;
    }
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    n = 0;
    for (scanf("%s", s); s[n]; n++)
      ;
    b = 0;
    for (int i = 0; i < n; i++) b |= (1 << (s[i] - 'a'));
    printf("%d\n", ask(b));
  }
  return 0;
}
