#include <bits/stdc++.h>
using namespace std;
struct longint {
  const static int BYTE = 10000;
  int x[55], len;
  longint() {
    memset(x, 0, sizeof(x));
    len = 0;
  }
  longint(int A) {
    memset(x, 0, sizeof(x));
    x[len = 1] = A;
  }
  inline longint &operator*(const longint &A) {
    longint B;
    B.len = len + A.len - 1;
    for (int i = 1; i <= len; ++i)
      for (int j = 1; j <= A.len; ++j) B.x[i + j - 1] += x[i] * A.x[j];
    for (int i = 1; i <= B.len; ++i)
      B.x[i + 1] += B.x[i] / BYTE, B.x[i] %= BYTE;
    while (B.x[B.len + 1]) ++B.len;
    return B;
  }
  inline void print() {
    printf("%d", x[len]);
    for (int i = len - 1; i; --i) printf("%04d", x[i]);
    printf("\n");
  }
};
inline bool operator<(const longint &B, const longint &A) {
  if (B.len < A.len)
    return 1;
  else if (B.len > A.len)
    return 0;
  for (int i = B.len; i; --i)
    if (B.x[i] < A.x[i])
      return 1;
    else if (B.x[i] > A.x[i])
      return 0;
  return 0;
}
int n;
bool c[777][777];
void init() {
  scanf("%d", &n);
  for (int i = 1, A, B; i < n; ++i) {
    scanf("%d%d", &A, &B);
    c[A][B] = c[B][A] = 1;
  }
}
int size[777];
longint f[711][711];
void dfs(int u, int p = -1) {
  size[u] = 1;
  f[u][1] = 1;
  for (int v = 1; v <= n; ++v) {
    if (!c[u][v] || v == p) continue;
    dfs(v, u);
    for (int i = size[u]; i; --i) {
      for (int j = 1; j <= size[v]; ++j)
        f[u][i + j] = max(f[u][i + j], f[u][i] * f[v][j]);
      f[u][i] = f[u][i] * f[v][0];
    }
    size[u] += size[v];
  }
  for (int i = 1; i <= size[u]; ++i)
    f[u][0] = max(f[u][0], f[u][i] * longint(i));
}
void work() {
  dfs(1);
  f[1][0].print();
}
int main() {
  init();
  work();
  return 0;
}
