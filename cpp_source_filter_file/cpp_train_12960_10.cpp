#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
struct Node {
  int x, l;
} A[MAXN];
int F[MAXN][MAXN][2], N, Ans;
bool cmp(Node a, Node b) { return a.x < b.x; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d%d", &A[i].x, &A[i].l);
  sort(A + 1, A + N + 1, cmp);
  A[0].x = -(1 << 30);
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= i; j++)
      for (int p = 0; p < 2; p++) {
        Ans = max(Ans, F[i][j][p]);
        int Pr = A[j].x + p * A[j].l;
        for (int k = i + 1, mx = -(1 << 30), a, b; k <= i + 1; k++)
          for (int d = 0; d < 2; d++) {
            int nxt = A[k].x + d * A[k].l;
            if (nxt > mx) mx = nxt, a = k, b = d;
            F[k][a][b] =
                max(F[k][a][b], F[i][j][p] + min(A[k].l, nxt - Pr) + mx - nxt);
          }
      }
  printf("%d\n", Ans);
  return 0;
}
