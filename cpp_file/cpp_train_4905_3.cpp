#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n;
struct side {
  int y, next;
} e[N * 2 + 9];
int lin[N + 9], cs;
void Ins(int x, int y) {
  e[++cs].y = y;
  e[cs].next = lin[x];
  lin[x] = cs;
}
void Ins2(int x, int y) {
  Ins(x, y);
  Ins(y, x);
}
void into() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Ins2(x, y);
  }
}
int siz[N + 9];
long double dp[N + 9][N + 9], tmp[N + 9];
void Dfs_dp(int k, int fa) {
  siz[k] = 1;
  for (int i = 0; i <= n; ++i) dp[k][i] = 0;
  dp[k][0] = 1;
  for (int i = lin[k]; i; i = e[i].next) {
    int y = e[i].y;
    if (y == fa) continue;
    Dfs_dp(y, k);
    for (int i = 0; i < siz[k]; ++i)
      for (int j = 0; j < siz[y]; ++j) {
        tmp[i + j] += dp[k][i] * dp[y][j] * (0.5 / (siz[y] - j) - 1);
        tmp[i + j + 1] += dp[k][i] * dp[y][j];
      }
    siz[k] += siz[y];
    for (int i = 0; i < siz[k]; ++i) dp[k][i] = tmp[i], tmp[i] = 0;
  }
}
long double ans[N + 9];
void Get_ans() {
  for (int i = 1; i <= n; ++i) {
    Dfs_dp(i, 0);
    ans[i] = 1;
    for (int j = lin[i]; j; j = e[j].next) {
      int y = e[j].y;
      long double sum = 0;
      for (int k = 0; k < siz[y]; ++k) sum += dp[y][k] * 0.5 / (siz[y] - k);
      ans[i] *= sum;
    }
  }
}
void work() { Get_ans(); }
void outo() {
  for (int i = 1; i <= n; ++i) {
    double t = ans[i];
    printf("%.10lf\n", t);
  }
}
int main() {
  into();
  work();
  outo();
  return 0;
}
