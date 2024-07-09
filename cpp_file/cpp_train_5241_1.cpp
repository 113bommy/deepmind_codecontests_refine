#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 100;
const int K = 8;
const int dif = 13;
const double zero = 1e-7;
int n, x, st, ed, u, d, l, r, cx, cy, rr, unround, ress, resr, rounddisp, pcl;
int dat[maxn][maxn], gar[maxn][maxn], tar[maxn][maxn];
char ch;
struct points {
  int x, y, d;
  points() {}
  points(int xx, int yy, int dd) {
    x = xx, y = yy;
    d = dd;
  }
} b[maxn * maxn];
vector<points> q;
inline double csqr(double x) { return x * x; }
inline int cabs(int x) { return x > 0 ? x : -x; }
inline int cmax(int x, int y) { return x < y ? y : x; }
inline double cfabs(int x) {
  if (x > zero) return x;
  if (x < -zero) return -x;
  return 0;
}
struct fastio11 {
  int getint() {
    for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
      ;
    x = ch - 48;
    while ((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - 48;
    return x;
  }
} tool1;
struct binarygraph {
  int dat[maxn][maxn];
  int n, cnt, l, r;
  double c, t, maxd, mind;
  void preset(int size) {
    n = size;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) dat[i][j] = 0;
  }
  void delblanks() {
    maxd = 0;
    mind = n;
    c = n / 2.0;
    for (int i = 2; i < n; i++) {
      for (l = 1; l <= n && dat[i][l] == 0; l++)
        ;
      for (r = n; r >= 1 && dat[i][r] == 0; r--)
        ;
      if (l <= n) {
        t = cfabs(sqrt(csqr(i - c) + csqr(l - c)));
        if (t - maxd > zero) maxd = t;
        if (t - mind < -zero) mind = t;
      }
      if (r >= 1) {
        t = cfabs(sqrt(csqr(i - c) + csqr(r - c)));
        if (t - maxd > zero) maxd = t;
        if (t - mind < -zero) mind = t;
      }
    }
  }
  void printout() {
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf(dat[i][j] ? "W" : " ");
      printf("\n");
    }
    printf("cnt=%lf\nmaxd=%lf\nmind=%lf\n", maxd - mind, maxd, mind);
  }
  int check() { return maxd / mind - 1.41 < zero; }
} tool2;
int main() {
  n = tool1.getint();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dat[i][j] = tool1.getint();
  for (int i = 3; i <= n - 2; i++)
    for (int j = 3; j <= n - 2; j++) {
      int cnt = 0;
      for (int k = i - 2; k <= i + 2; k++)
        for (int l = j - 2; l <= j + 2; l++)
          if (dat[k][l]) cnt++;
      gar[i][j] = cnt;
    }
  memcpy(tar, gar, sizeof(tar));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (tar[i][j] >= dif) {
        q.clear();
        q.push_back(b[ed = 1] = points(i, j, tar[i][j]));
        tar[i][j] = 0;
        st = 0;
        while (st < ed) {
          points t = b[++st];
          if (t.x > 1 && tar[t.x - 1][t.y] >= dif) {
            q.push_back(b[++ed] = points(t.x - 1, t.y, tar[t.x - 1][t.y]));
            tar[t.x - 1][t.y] = 0;
          }
          if (t.x < n && tar[t.x + 1][t.y] >= dif) {
            q.push_back(b[++ed] = points(t.x + 1, t.y, tar[t.x + 1][t.y]));
            tar[t.x + 1][t.y] = 0;
          }
          if (t.y > 1 && tar[t.x][t.y - 1] >= dif) {
            q.push_back(b[++ed] = points(t.x, t.y - 1, tar[t.x][t.y - 1]));
            tar[t.x][t.y - 1] = 0;
          }
          if (t.y < n && tar[t.x][t.y + 1] >= dif) {
            q.push_back(b[++ed] = points(t.x, t.y + 1, tar[t.x][t.y + 1]));
            tar[t.x][t.y + 1] = 0;
          }
        }
        if (ed < 50) continue;
        u = r = 0;
        l = d = 0x7fffffff;
        for (int p = 0; p < q.size(); p++) {
          if (q[p].x > u) u = q[p].x;
          if (q[p].x < d) d = q[p].x;
          if (q[p].y > r) r = q[p].y;
          if (q[p].y < l) l = q[p].y;
        }
        tool2.preset(cmax(r - l + 1, u - d + 1));
        for (int p = 0; p < q.size(); p++)
          tool2.dat[q[p].x - d + 1][q[p].y - l + 1] = 1;
        tool2.delblanks();
        if (tool2.check())
          resr++;
        else
          ress++;
      }
  printf("%d %d\n", resr, ress);
  return 0;
}
