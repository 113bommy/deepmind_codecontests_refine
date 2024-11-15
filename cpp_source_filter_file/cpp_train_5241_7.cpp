#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 19, oo = (1 << 30) - 1, Len = 12000000;
struct Point {
  int x, y;
} Q[N * N], T[9];
int Dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, Dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
int s[N][N], t[N][N], n, C1, C2;
char Buf[Len], *B = Buf;
int IN() {
  int c, x;
  while (!isdigit(c = *B++))
    ;
  x = c - '0';
  while (isdigit(c = *B++)) x = (x << 1) + (x << 3) + c - '0';
  return x;
}
int sqr(int x) { return x * x; }
void BFS(int Sx, int Sy) {
  int f = 1, w = 0, D = 0, x, y;
  Q[1] = (Point){Sx, Sy};
  t[Sx][Sy] = 0;
  while (f > w) {
    Point A = Q[++w];
    for (int i = 0; i < 8; i++)
      if (t[x = A.x + Dx[i]][y = A.y + Dy[i]])
        t[x][y] = 0, Q[++f] = (Point){x, y};
  }
  if (f < 100) return;
  T[1] = T[2] = T[3] = T[4] = (Point){oo, oo};
  T[5] = T[6] = T[7] = T[8] = (Point){-oo, -oo};
  for (int i = 1; i < f + 1; i++) {
    if (Q[i].x < T[1].x || Q[i].x == T[1].x && Q[i].y < T[1].y) T[1] = Q[i];
    if (Q[i].x < T[2].x || Q[i].x == T[2].x && Q[i].y > T[2].y) T[2] = Q[i];
    if (Q[i].y < T[3].y || Q[i].y == T[3].x && Q[i].x < T[3].x) T[3] = Q[i];
    if (Q[i].y < T[4].y || Q[i].y == T[4].x && Q[i].x > T[4].x) T[4] = Q[i];
    if (Q[i].x > T[5].x || Q[i].x == T[5].x && Q[i].y < T[5].y) T[5] = Q[i];
    if (Q[i].x > T[6].x || Q[i].x == T[6].x && Q[i].y > T[6].y) T[6] = Q[i];
    if (Q[i].y > T[7].y || Q[i].y == T[7].x && Q[i].x < T[7].x) T[7] = Q[i];
    if (Q[i].y > T[8].y || Q[i].y == T[8].x && Q[i].x > T[8].x) T[8] = Q[i];
  }
  for (int i = 1; i < 9; i++)
    for (int j = 1; j < 9; j++)
      D = max(D, sqr(T[i].x - T[j].x) + sqr(T[i].y - T[j].y));
  if (1.0 * f / D > 0.69)
    C1++;
  else
    C2++;
}
int main() {
  fread(Buf, 1, Len, stdin);
  n = IN();
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++) s[i][j] = IN();
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++) {
      int c = s[i][j];
      for (int k = 0; k < 8; k++)
        if (s[i + Dx[k]][j + Dy[k]]) c++;
      t[i][j] = (c >= 4);
    }
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++)
      if (t[i][j]) BFS(i, j);
  printf("%d %d\n", C1, C2);
}
