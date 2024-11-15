#include <bits/stdc++.h>
using namespace std;
int Nextint() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  int x = 0;
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
const int maxn = 1010;
int N, M, lt, c1[maxn], c2[maxn], cnt, srt[maxn];
int qx[maxn][2], lx, qy[maxn][2], ly;
char S[maxn][maxn];
int que[maxn * 8][2];
bool Ck(int x1, int y1, int x2, int y2, int x, int y) {
  if (x >= x1 && x <= x2 && (y == y1 || y == y2)) return true;
  if (y >= y1 && y <= y2 && (x == x1 || x == x2)) return true;
  return false;
}
bool Chk(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  if (!(x2 > x1 + 1 && y2 > y1 + 1 && x4 > x3 + 1 && y4 > y3 + 1)) return false;
  int cnt1 = (x2 - x1 + y2 - y1) * 2;
  int cnt2 = (x4 - x3 + y4 - y3) * 2;
  for (int i = 1; i <= lt; i++) {
    bool flag = true;
    if (Ck(x1, y1, x2, y2, que[i][0], que[i][1])) {
      cnt1--;
      flag = false;
    }
    if (Ck(x3, y3, x4, y4, que[i][0], que[i][1])) {
      cnt2--;
      flag = false;
    }
    if (flag || cnt1 < 0 || cnt2 < 0) return false;
  }
  if (cnt1 != 0 || cnt2 != 0) return false;
  printf("YES\n");
  printf("%d %d %d %d\n%d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
  return true;
}
int main() {
  scanf("%d%d\n", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      S[i][j] = getchar();
      if (S[i][j] == '#' && lt <= 4 * (N + M)) {
        lt++;
        que[lt][0] = i;
        que[lt][1] = j;
      }
    }
    scanf("\n");
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      if (S[i][j] == '#' && S[i + 1][j] == '#' && S[i][j + 1] == '#' &&
          lx <= 20) {
        bool flag = false;
        if (i > 2)
          if (S[i - 1][j] == '#' && S[i - 1][j + 1] == '#' &&
              S[i - 2][j] == '#' && S[i - 2][j + 1] == '#')
            flag = true;
        if (j > 2)
          if (S[i + 1][j - 1] == '#' && S[i][j - 1] == '#' &&
              S[i + 1][j - 2] == '#' && S[i + 1][j - 2] == '#')
            flag = true;
        if (!flag) {
          lx++;
          qx[lx][0] = i;
          qx[lx][1] = j;
        }
      }
      if (S[i][j] == '#' && S[i - 1][j] == '#' && S[i][j - 1] == '#' &&
          ly <= 20) {
        bool flag = false;
        if (j <= M - 2)
          if (S[i][j + 1] == '#' && S[i - 1][j + 1] == '#' &&
              S[i][j + 2] == '#' && S[i - 1][j + 2] == '#')
            flag = true;
        if (i <= N - 2)
          if (S[i + 1][j - 1] == '#' && S[i + 1][j] == '#' &&
              S[i + 2][j - 1] == '#' && S[i + 2][j] == '#')
            flag = true;
        if (!flag) {
          ly++;
          qy[ly][0] = i;
          qy[ly][1] = j;
        }
      }
    }
  if (lx > 20 || ly > 20 || lt == 4 * (N + M))
    printf("NO\n");
  else {
    for (int i2 = 1; i2 <= lx; i2++)
      for (int j1 = 1; j1 <= ly; j1++)
        for (int j2 = 1; j2 <= ly; j2++)
          if (j1 == ly || j2 == ly) {
            if (Chk(qx[1][0], qx[1][1], qy[j1][0], qy[j1][1], qx[i2][0],
                    qx[i2][1], qy[j2][0], qy[j2][1]))
              return 0;
          }
    printf("NO\n");
  }
  return 0;
}
