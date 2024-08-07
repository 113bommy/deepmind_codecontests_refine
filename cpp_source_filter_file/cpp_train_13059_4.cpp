#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2100][2100];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
}
int col[2100][2100], num;
const int xy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int check(int x1, int y1, int x2, int y2, int x3, int y3) {
  bool kk[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < 4; i++) kk[col[x1 + xy[i][0]][y1 + xy[i][1]]] = 1;
  for (int i = 0; i < 4; i++) kk[col[x2 + xy[i][0]][y2 + xy[i][1]]] = 1;
  for (int i = 0; i < 4; i++) kk[col[x3 + xy[i][0]][y3 + xy[i][1]]] = 1;
  for (int i = 1; i <= 4; i++)
    if (!kk[i]) return i;
}
void work() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!col[i][j] && s[i][j] != '.') {
        if (s[i][j] == 'b') {
          puts("NO");
          return;
        } else if (s[i][j] == 'w') {
          if (j <= m - 2 && s[i][j + 1] == 'b' && s[i][j + 2] == 'w' &&
              !col[i][j + 1] && !col[i][j + 2]) {
            col[i][j] = col[i][j + 1] = col[i][j + 2] =
                check(i, j, i, j + 1, i, j + 2);
          } else if (i <= n - 2 && s[i + 1][j] == 'b' && s[i + 2][j] == 'w' &&
                     !col[i + 1][j] && !col[i + 2][j]) {
            col[i][j] = col[i + 1][j] = col[i + 2][j] =
                check(i, j, i, j + 1, i, j + 2);
          } else {
            puts("NO");
            return;
          }
        }
      }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (col[i][j] == 1)
        putchar('a');
      else if (col[i][j] == 2)
        putchar('b');
      else if (col[i][j] == 3)
        putchar('c');
      else if (col[i][j] == 4)
        putchar('d');
      else
        putchar('.');
    puts("");
  }
}
int main() {
  init();
  work();
}
