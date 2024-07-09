#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0;
  char zf = 1;
  char ch;
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') zf = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * zf;
}
int i, j, k, m, n, x, y, z, cnt, la[1000010], fa[1000010], size[1000010], top,
    g = 0;
int ask(int x) {
  while (fa[x] != x) x = fa[x];
  return x;
}
void merge(int x, int y) {
  if (x == y) return;
  if (size[x] > size[y]) swap(x, y);
  la[++top] = x;
  fa[x] = y;
  size[y] += size[x];
}
void undo() {
  int La = la[top];
  size[fa[La]] -= size[La];
  fa[La] = La;
  top--;
}
struct ed {
  int x, y, z;
  inline bool operator<(const ed s) const { return z < s.z; }
} q[1000010];
struct query {
  int id, x, y, val;
  inline bool operator<(const query s) const {
    if (val == s.val) return id < s.id;
    return val < s.val;
  }
} A[1000010];
int ans[1000010];
int main() {
  n = read();
  m = read();
  for (register int i = 1; i <= n; i++) size[i] = 1, fa[i] = i;
  for (register int i = 1; i <= m; i++) {
    x = read();
    y = read();
    z = read();
    q[i] = {x, y, z};
  }
  k = read();
  for (register int e = 1; e <= k; e++) {
    z = read();
    ans[e] = 1;
    for (register int i = 1; i <= z; i++) {
      x = read();
      A[++cnt] = {e, q[x].x, q[x].y, q[x].z};
    }
  }
  sort(q + 1, q + m + 1);
  sort(A + 1, A + cnt + 1);
  int qd = 1;
  for (register int i = 1; i <= cnt;) {
    while (q[qd].z < A[i].val) merge(ask(q[qd].x), ask(q[qd].y)), qd++;
    top = 0;
    do {
      int p1 = ask(A[i].x), q1 = ask(A[i].y);
      if (p1 == q1) ans[A[i].id] = 0;
      merge(p1, q1);
      i++;
    } while (A[i].val == A[i - 1].val && A[i].id == A[i - 1].id);
    while (top) undo();
  }
  for (register int i = 1; i <= k; i++) puts(ans[i] ? "YES" : "NO");
  return 0;
}
