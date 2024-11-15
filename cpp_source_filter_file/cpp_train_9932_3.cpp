#include <bits/stdc++.h>
int list[100000];
char listname[14000][255];
struct Time {
  int h1, m1, h2, m2;
};
struct Ans {
  int h1, m1, d1, h2, m2, d2, id;
};
Ans A[1000];
struct Help {
  int Predm, day, h, m, money, id;
};
Time p[4];
int dT = 0;
int ti(int h, int m);
int time(int d, int h, int m) {
  int ans = (d - 1) * (24 * 60 - dT);
  if (ti(p[0].h1, p[0].m1) < ti(h, m)) ans += ti(p[0].h1, p[0].m1);
  for (int i = 1; i < 4; i++)
    if (ti(p[i].h1, p[i].m1) < ti(h, m))
      ans += ti(p[i].h1, p[i].m1) - ti(p[i - 1].h2, p[i - 1].m2) - 1;
  for (int i = 0; i < 3; i++)
    if (ti(p[i].h2, p[i].m2) < ti(h, m) &&
        ti(p[i + 1].h1, p[i + 1].m1) >= ti(h, m)) {
      ans += ti(h, m) - ti(p[i].h2, p[i].m2) - 1;
      ;
    }
  if (ti(p[0].h1, p[0].m1) >= ti(h, m)) ans = ti(h, m);
  if (ti(p[3].h1, p[3].m1) < ti(h, m))
    ans += ti(h, m) - ti(p[3].h2, p[3].m2) - 1;
  return ans;
}
Ans set(int id, int time1, int time2) {
  time2--;
  Ans ans;
  ans.id = id + 1;
  ans.d1 = 1;
  while (time1 >= (24 * 60 - dT)) ans.d1++, time1 -= (24 * 60 - dT);
  for (int i = 0; i < 4; i++)
    if (ti(time1 / 60, time1 % 60) >= ti(p[i].h1, p[i].m1))
      time1 += ti(p[i].h2, p[i].m2) - ti(p[i].h1, p[i].m1) + 1;
  ans.h1 = time1 / 60;
  ans.m1 = time1 % 60;
  ans.d2 = 1;
  while (time2 >= (24 * 60 - dT)) ans.d2++, time2 -= (24 * 60 - dT);
  for (int i = 0; i < 4; i++)
    if (ti(time2 / 60, time2 % 60) >= ti(p[i].h1, p[i].m1))
      time2 += ti(p[i].h2, p[i].m2) - ti(p[i].h1, p[i].m1) + 1;
  ans.h2 = time2 / 60;
  ans.m2 = time2 % 60;
  return ans;
}
int ti(int h, int m) { return h * 60 + m; }
Help H[10000];
int dp[100000][200];
int last[100000][200];
int main() {
  int n, m, k;
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 0; i < m; i++) scanf("%s", listname[i]);
  for (int i = 0; i < m; i++) scanf("%d", list + i);
  char s[50];
  for (int i = 0; i < 4; i++)
    scanf("%d:%d-%d:%d", &p[i].h1, &p[i].m1, &p[i].h2, &p[i].m2);
  for (int i = 0; i < n; i++) {
    scanf("%s%d%d:%d%d", s, &H[i].day, &H[i].h, &H[i].m, &H[i].money);
    H[i].Predm = -1;
    for (int j = 0; j < m; j++)
      if (strcmp(s, listname[j]) == 0) H[i].Predm = j;
    H[i].id = i;
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (time(H[i].day, H[i].h, H[i].m) > time(H[j].day, H[j].h, H[j].m)) {
        Help T = H[i];
        H[i] = H[j];
        H[j] = T;
      }
  for (int i = 0; i < 4; i++)
    dT += ti(p[i].h2, p[i].m2) - ti(p[i].h1, p[i].m1) + 1;
  for (int i = 0; i <= k * (60 * 24 - dT); i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i + 1][j] <= dp[i][j]) dp[i + 1][j] = dp[i][j], last[i + 1][j] = 0;
      if (dp[i][j + 1] <= dp[i][j]) dp[i][j + 1] = dp[i][j], last[i][j + 1] = 1;
      if (H[j].Predm != -1) {
        if (i + list[H[j].Predm] <= time(H[j].day, H[j].h, H[j].m)) {
          if (dp[i + list[H[j].Predm]][j + 1] <= dp[i][j] + H[j].money) {
            dp[i + list[H[j].Predm]][j + 1] = dp[i][j] + H[j].money;
            last[i + list[H[j].Predm]][j + 1] = 2;
          }
        }
      }
    }
    if (dp[i + 1][n] <= dp[i][n]) {
      dp[i + 1][n] = dp[i][n];
      last[i + 1][n] = 0;
    }
  }
  int an = 0;
  printf("%d\n", dp[k * (60 * 24 - dT)][n]);
  int i = k * (60 * 24 - dT);
  int j = n;
  while (i != 0 || j != 0) {
    if (last[i][j] == 0)
      i--;
    else if (last[i][j] == 1)
      j--;
    else if (last[i][j] == 2) {
      A[an].id = j;
      j--;
      A[an] = set(H[j].id, i - list[H[j].Predm], i);
      i -= list[H[j].Predm];
      an++;
    }
  }
  printf("%d\n", an);
  for (int i = an - 1; i >= 0; i--)
    printf("%d %d %2.2d:%2.2d %d %2.2d:%2.2d\n", A[i].id, A[i].d1, A[i].h1,
           A[i].m1, A[i].d2, A[i].h2, A[i].m2);
  return 0;
}
