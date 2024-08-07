#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int read() {
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    ;
  int x = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    x = x * 10 + ch - '0';
  return x;
}
const int N = 1e5;
int A[N + 5], B[N + 5], C[N + 5], D[N + 5], n;
int U[N * 4 + 5][2];
map<int, int> M;
struct node {
  int isquery, pos, l, r;
  node(int _isquery, int _pos, int _l, int _r)
      : isquery(_isquery), pos(_pos), l(_l), r(_r) {}
  friend bool operator<(node a, node b) {
    if (a.pos != b.pos)
      return a.pos < b.pos;
    else
      return a.isquery;
  }
};
void insert(int which, int pos) {
  while (pos <= N) {
    U[pos][which] += 1;
    pos += (pos & (-pos));
  }
}
int getsum(int which, int pos) {
  int re = 0;
  while (pos > 0) {
    re += U[pos][which];
    pos -= (pos & (-pos));
  }
  return re;
}
bool solve(int A[], int B[], int C[], int D[], int n) {
  memset(U, 0, sizeof(U));
  ;
  vector<node> V;
  for (int i = 0; i < n; i++) {
    V.push_back(node(1, A[i], C[i], D[i]));
    V.push_back(node(0, B[i], C[i], D[i]));
  }
  stable_sort(V.begin(), V.end());
  int cnt = 0;
  for (int i = 0; i < V.size(); i++) {
    if (V[i].isquery) {
      int p = getsum(1, V[i].l - 1), q = getsum(0, N) - getsum(0, V[i].r);
      if (p + q != cnt) return false;
    } else {
      insert(0, V[i].l);
      insert(1, V[i].r);
      cnt++;
    }
  }
  return true;
}
int main() {
  n = read();
  vector<int> V;
  for (int i = 0; i < n; i++) {
    A[i] = read();
    B[i] = read();
    C[i] = read();
    D[i] = read();
    V.push_back(A[i]);
    V.push_back(B[i]);
    V.push_back(C[i]);
    V.push_back(D[i]);
  }
  stable_sort(V.begin(), V.end());
  for (int i = 0; i < V.size(); i++) {
    if (i && V[i] == V[i - 1])
      M[V[i]] = M[V[i - 1]];
    else
      M[V[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    A[i] = M[A[i]];
    B[i] = M[B[i]];
    C[i] = M[C[i]];
    D[i] = M[D[i]];
  }
  int p = solve(A, B, C, D, n);
  int q = solve(C, D, A, B, n);
  (p && q) ? puts("YES") : puts("NO");
}
