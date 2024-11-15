#include <bits/stdc++.h>
using namespace std;
struct Pos {
  int a, b, c;
  Pos() {}
  Pos(int a, int b, int c) : a(a), b(b), c(c) {}
};
const int MaxN = 70;
char matrix[MaxN][MaxN];
Pos q[MaxN * MaxN * MaxN];
int d[MaxN * MaxN * MaxN];
int p[MaxN * MaxN * MaxN];
bool used[MaxN][MaxN][MaxN];
void USED(int a, int b, int c) {
  used[a][b][c] = true;
  used[a][c][b] = true;
  used[b][a][c] = true;
  used[b][c][a] = true;
  used[c][a][b] = true;
  used[c][b][a] = true;
}
vector<pair<int, int> > res;
void add(int a, int b, int c, int dist, int l, int &r) {
  if (used[a][b][c]) return;
  q[r] = Pos(a, b, c);
  d[r] = dist;
  p[r] = l;
  USED(a, b, c);
  r++;
}
int main() {
  int n;
  scanf("%d", &n);
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  a--, b--, c--;
  for (int i = 0; i < n; i++) scanf("%s", matrix[i]);
  int l = 0, r = 1;
  q[l] = Pos(a, b, c);
  USED(a, b, c);
  p[l] = -1;
  d[l] = 0;
  while (l < r) {
    Pos cur = q[l];
    int A = cur.a, B = cur.b, C = cur.c;
    if (A + B + C == 3) {
      printf("%d\n", d[l]);
      while (p[l] != -1) {
        if (q[l].a != q[p[l]].a) res.push_back(make_pair(q[p[l]].a, q[l].a));
        if (q[l].b != q[p[l]].b) res.push_back(make_pair(q[p[l]].b, q[l].b));
        if (q[l].c != q[p[l]].c) res.push_back(make_pair(q[p[l]].c, q[l].c));
        l = p[l];
      }
      for (int i = (int)res.size() - 1; i >= 0; i--)
        printf("%d %d", res[i].first + 1, res[i].second + 1);
      return 0;
    }
    for (int to = 0; to < n; to++) {
      if (to == A || to == B || to == C) continue;
      if (matrix[A][to] == matrix[B][C]) add(to, B, C, d[l] + 1, l, r);
      if (matrix[B][to] == matrix[A][C]) add(A, to, C, d[l] + 1, l, r);
      if (matrix[C][to] == matrix[A][B]) add(A, B, to, d[l] + 1, l, r);
    }
    l++;
  }
  printf("-1");
}
