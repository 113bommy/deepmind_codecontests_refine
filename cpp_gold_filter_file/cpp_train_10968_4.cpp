#include <bits/stdc++.h>
using namespace std;
int static const N = 1010;
int static const M = 5010;
struct grana {
  int x, y;
};
bool povezan[N][N], used1[N], used2[N];
int n, ud[N], m;
grana gr[M];
int radi() {
  for (int i = 0; i < n; i++) ud[i] = 100000000;
  ud[0] = 0;
  for (int i = 0; i < n * 2; i++) {
    for (int j = 0; j < m; j++) {
      if (used1[gr[j].x] && used2[gr[j].x] && used1[gr[j].y] &&
          used2[gr[j].y]) {
        if (ud[gr[j].y] > ud[gr[j].x] + 2) {
          ud[gr[j].y] = ud[gr[j].x] + 2;
        }
        if (ud[gr[j].y] <= ud[gr[j].x]) ud[gr[j].x] = ud[gr[j].y] - 1;
      }
    }
  }
  for (int j = 0; j < m; j++)
    if (used1[gr[j].x] && used2[gr[j].x] && used1[gr[j].y] && used2[gr[j].y]) {
      int dd = ud[gr[j].y] - ud[gr[j].x];
      if (dd != 1 && dd != 2) return 0;
    }
  return 1;
}
int main() {
  scanf("%i%i", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%i%i", &gr[i].x, &gr[i].y);
    gr[i].x--;
    gr[i].y--;
  }
  used1[0] = 1;
  used2[n - 1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (used1[gr[j].x]) used1[gr[j].y] = true;
      if (used2[gr[j].y]) used2[gr[j].x] = true;
    }
  }
  if (radi()) {
    printf("Yes\n");
    for (int j = 0; j < m; j++)
      if (used1[gr[j].x] && used2[gr[j].x] && used1[gr[j].y] && used2[gr[j].y])
        printf("%i\n", ud[gr[j].y] - ud[gr[j].x]);
      else
        printf("2\n");
  } else
    printf("No\n");
  return 0;
}
