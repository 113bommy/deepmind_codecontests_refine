#include <bits/stdc++.h>
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
struct Point {
  int x, y, c, fa;
  friend bool operator==(Point a, Point b) {
    return (a.x == b.x && a.y == b.y);
  }
} w[2], b[2], list[4][1000 * 1000 + 1];
int otherx, othery;
void printlist(int k, Point a) {
  if (a.fa == -1) return;
  if (a.fa != 1) printlist(k, list[k][a.fa]);
  printf("%d %d\n", a.x, a.y);
}
int n, m, head, tail, v[4][1000 + 1][1000 + 1];
void closer(int k, Point st, Point ed) {
  Point a, b;
  head = tail = 1;
  memset(v[k], 0, sizeof(v[k]));
  v[k][st.x][st.y] = head;
  list[k][head] = st, list[k][head].c = 0, list[k][head].fa = -1;
  if (st == ed) return;
  while (head <= tail) {
    a = list[k][head];
    for (int i = 0; i < 8; i++) {
      b = a, b.x += dx[i], b.y += dy[i], b.c++;
      if (b.x < 1 || b.y < 1 || b.x > n || b.y > m || v[k][b.x][b.y] != 0)
        continue;
      tail++;
      v[k][b.x][b.y] = tail;
      b.fa = head;
      list[k][tail] = b;
      if (b == ed) return;
    }
    head++;
  }
}
void printlast(int k) {
  if (k == 0) {
    printf("%d %d\n", b[0].x - 1, b[0].y + 2);
    printf("%d %d\n", b[0].x - 3, b[0].y + 1);
    printf("%d %d\n", b[0].x - 1, b[0].y);
  } else {
    printf("%d %d\n", w[0].x + 1, w[0].y + 2);
    printf("%d %d\n", w[0].x + 3, w[0].y + 1);
    printf("%d %d\n", w[0].x + 1, w[0].y);
  }
}
bool choose;
int main() {
  n = read(), m = read(), w[1].x = read(), w[1].y = read(), b[1].x = read(),
  b[1].y = read();
  w[0].x = n / 2, w[0].y = m / 2, b[0].x = n / 2 + 1, b[0].y = m / 2;
  closer(0, w[1], w[0]), closer(1, b[1], b[0]);
  closer(2, w[1], b[0]);
  closer(3, b[1], w[0]);
  if ((w[1].x + w[1].y) % 2 != (b[1].x + b[1].y) % 2) {
    if (list[0][v[0][w[0].x][w[0].y]].c <= list[1][v[1][b[0].x][b[0].y]].c)
      printf("WHITE\n"), printlist(0, list[0][v[0][w[0].x][w[0].y]]);
    else if (list[2][v[2][b[0].x][b[0].y]].c >=
             list[1][v[1][b[0].x][b[0].y]].c + 2)
      printf("BLACK\n"), printlist(1, list[1][v[1][b[0].x][b[0].y]]);
    else
      printf("WHITE\n"), printlist(2, list[2][v[2][b[0].x][b[0].y]]),
          printlast(0);
  } else {
    if (list[1][v[1][b[0].x][b[0].y]].c < list[0][v[0][w[0].x][w[0].y]].c)
      printf("BLACK\n"), printlist(1, list[1][v[1][b[0].x][b[0].y]]);
    else if (list[3][v[3][w[0].x][w[0].y]].c > list[0][v[0][w[0].x][w[0].y]].c)
      printf("WHITE\n"), printlist(0, list[0][v[0][w[0].x][w[0].y]]);
    else
      printf("BLACK\n"), printlist(3, list[3][v[3][w[0].x][w[0].y]]),
          printlast(1);
  }
  fflush(stdout);
}
