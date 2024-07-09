#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
const int dx[9] = {0, -2, -2, -1, -1, 1, 1, 2, 2},
          dy[9] = {0, -1, 1, -2, 2, -2, 2, -1, 1};
int n, m, i, j, dis[1005][1005][2], x, y, xx, yy;
bool inmap(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }
void bfs(int x, int y, int typ) {
  dis[x][y][typ] = 0;
  queue<int> qx, qy;
  qx.push(x);
  qy.push(y);
  while (!qx.empty()) {
    int x = qx.front(), y = qy.front();
    int i;
    qx.pop();
    qy.pop();
    for (((i)) = (1); ((i)) <= ((8)); ((i))++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (inmap(nx, ny) && dis[nx][ny][typ] > dis[x][y][typ] + 1) {
        dis[nx][ny][typ] = dis[x][y][typ] + 1;
        qx.push(nx);
        qy.push(ny);
      }
    }
  }
}
void solve(int x, int y, int typ) {
  for (;;) {
    if (dis[x][y][typ] == 0) break;
    int i;
    for (((i)) = (1); ((i)) <= ((8)); ((i))++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (inmap(nx, ny) && dis[nx][ny][typ] == dis[x][y][typ] - 1) {
        printf("%d %d\n", nx, ny);
        x = nx;
        y = ny;
        break;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &x, &y, &xx, &yy);
  memset((dis), (0x16), (sizeof((dis))));
  bfs(n / 2, m / 2, 0);
  bfs(n / 2 + 1, m / 2, 1);
  double wg = dis[x][y][0];
  double wb = dis[x][y][1];
  double bg = dis[xx][yy][1] + 0.5;
  double bb = dis[xx][yy][0] + 0.5;
  if ((x + y) % 2 == (xx + yy) % 2) {
    if (bg < wg) {
      puts("BLACK");
      solve(xx, yy, 1);
      return 0;
    }
    if (bb < wg + 1) {
      puts("BLACK");
      solve(xx, yy, 0);
      solve(n / 2, m / 2, 1);
      return 0;
    }
    puts("WHITE");
    solve(x, y, 0);
  } else {
    if (wg < bg) {
      puts("WHITE");
      solve(x, y, 0);
      return 0;
    }
    if (wb < bg + 1) {
      puts("WHITE");
      solve(x, y, 1);
      solve(n / 2 + 1, m / 2, 0);
      return 0;
    }
    puts("BLACK");
    solve(xx, yy, 1);
  }
  return 0;
}
