#include <bits/stdc++.h>
using namespace std;
int A[100005], B[100005], l[1000005], r[1000005], L[1000005], R[1000005],
    p[1000005], Time, i, n, m, now, j, q[1000005];
char s[100005][10];
bool FLAG;
void dfs(int l, int r) {
  if (l >= r) return;
  if (!p[l]) {
    R[l] = l + 1;
    dfs(l + 1, r);
    return;
  }
  L[l] = l + 1;
  if (l != r && p[l] < r) R[l] = p[l] + 1;
  dfs(l + 1, p[l]);
  dfs(p[l] + 1, r);
}
void DFS(int x) {
  l[x] = ++Time;
  if (L[x]) DFS(L[x]);
  if (R[x]) DFS(R[x]);
  r[x] = Time;
}
void DFSS(int x) {
  if (L[x]) DFSS(L[x]);
  printf("%d ", x);
  if (R[x]) DFSS(R[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &A[i], &B[i]);
    scanf("%s", s[i]);
    if (s[i][0] == 'L')
      p[A[i]] = max(p[A[i]], B[i]);
    else
      q[A[i]] = max(q[A[i]], B[i]);
  }
  for (i = 1; i <= n; i++) {
    now = p[i];
    FLAG = true;
    while (FLAG) {
      FLAG = false;
      for (j = i + 1; j <= now; j++)
        if (max(p[j], q[j]) > now) {
          now = max(p[j], q[j]);
          FLAG = true;
        }
    }
    p[i] = now;
  }
  for (i = 1; i <= n; i++)
    if (p[i] && p[i] <= i) {
      cout << "Impossible";
      return 0;
    }
  dfs(1, n);
  Time = 0;
  DFS(1);
  for (i = 1; i <= m; i++) {
    if ((s[i][0] == 'L' && (l[L[A[i]]] > l[B[i]] || r[L[A[i]]] < l[B[i]])) ||
        (s[i][0] == 'R' && (l[R[A[i]]] > l[B[i]] || r[R[A[i]]] < l[B[i]]))) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  DFSS(1);
  return 0;
}
