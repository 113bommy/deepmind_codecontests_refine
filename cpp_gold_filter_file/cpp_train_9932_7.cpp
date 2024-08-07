#include <bits/stdc++.h>
using namespace std;
const int day = 1440;
struct Nodes {
  string name;
  int d, h, m;
  int t, val, nd;
  int id;
} p[110];
map<string, int> mp;
int val[110], n, m, nm;
int pre[110][31 * day][2];
int sum[31 * day];
int mark[31 * day], f[110][31 * day];
string lec;
int tot;
bool cmp(Nodes p1, Nodes p2) { return p1.t < p2.t; }
void work(int t, int &dd, int &hh, int &mm) {
  t--;
  dd = t / day;
  dd++;
  t = t % day;
  hh = t / 60;
  mm = t % 60;
}
void dfs(int i, int now, int cnt) {
  if (now == 0) {
    printf("%d\n", cnt);
    return;
  }
  if (pre[i][now][0] == -1) {
    dfs(i - 1, now, cnt);
    return;
  }
  dfs(i - 1, pre[i][now][0], cnt + 1);
  int id = pre[i][now][1];
  int d1, h1, m1, d2, h2, m2;
  int kk = lower_bound(sum, sum + tot + 1, sum[pre[i][now][0]] + 1) - sum;
  work(kk, d1, h1, m1);
  work(now, d2, h2, m2);
  printf("%d %d %02d:%02d %d %02d:%02d\n", p[id].id, d1, h1, m1, d2, h2, m2);
}
int main() {
  int i, j, k;
  int dd, mm, hh;
  while (scanf("%d%d%d", &n, &m, &nm) != EOF) {
    mp.clear();
    for (i = 1; i <= n; i++) {
      cin >> lec;
      mp[lec] = i;
    }
    for (i = 1; i <= n; i++) {
      scanf("%d", &val[i]);
    }
    tot = nm * day;
    for (i = 0; i <= tot; i++) {
      mark[i] = 0;
    }
    int tmp = 4;
    while (tmp--) {
      int h1, m1, h2, m2;
      scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
      int t1 = h1 * 60 + m1 + 1;
      int t2 = h2 * 60 + m2 + 1;
      if (t1 <= t2) {
        for (i = 0; i < nm; i++) {
          for (j = t1; j <= t2; j++) {
            mark[j + i * day] = 1;
          }
        }
      } else {
        for (i = 0; i < nm; i++) {
          for (j = t1; j <= day; j++) {
            mark[j + i * day] = 1;
          }
          for (j = 1; j <= t2; j++) {
            mark[j + i * day] = 1;
          }
        }
      }
    }
    for (i = 1; i <= m; i++) {
      cin >> p[i].name;
      scanf("%d%d:%d%d", &p[i].d, &p[i].h, &p[i].m, &p[i].val);
      p[i].t = (p[i].d - 1) * day + p[i].h * 60 + p[i].m + 1;
      k = mp[p[i].name];
      if (k == 0)
        p[i].nd = -1;
      else if (p[i].t <= val[k])
        p[i].nd = -1;
      else
        p[i].nd = val[k];
      p[i].id = i;
    }
    sort(p + 1, p + m + 1, cmp);
    for (i = 0; i <= tot; i++) {
      if (i == 0)
        sum[i] = mark[i];
      else
        sum[i] = sum[i - 1] + mark[i];
    }
    for (i = 0; i <= tot; i++) {
      sum[i] = i - sum[i];
    }
    for (i = 0; i <= m; i++) {
      for (j = 0; j <= tot; j++) {
        f[i][j] = 0;
      }
    }
    tmp = 0;
    f[0][0] = 0;
    for (i = 1; i <= m; i++) {
      j = lower_bound(sum, sum + tot + 1, tmp) - sum;
      j = min(j, tot);
      j = min(j, p[i].t - p[i].nd - 1);
      for (j = tot; j >= 0; j--) {
        if (f[i - 1][j] == -1) continue;
        f[i][j] = f[i - 1][j];
        pre[i][j][0] = -1;
        if (p[i].nd == -1 || p[i].val == 0) continue;
        k = lower_bound(sum, sum + tot + 1, sum[j] + p[i].nd) - sum;
        if (k >= p[i].t) continue;
        if (f[i - 1][j] + p[i].val >= f[i][k]) {
          f[i][k] = f[i - 1][j] + p[i].val;
          pre[i][k][0] = j;
          pre[i][k][1] = i;
        }
      }
      if (p[i].nd != -1 && p[i].val > 0) tmp += p[i].nd;
    }
    int ans = 0, id1, id2;
    for (j = 1; j <= m; j++) {
      for (i = 0; i <= tot; i++) {
        if (f[j][i] > ans) {
          ans = f[j][i];
          id1 = j;
          id2 = i;
        }
      }
    }
    if (ans == 0) {
      printf("0\n0\n");
      continue;
    }
    printf("%d\n", ans);
    dfs(id1, id2, 0);
  }
  return 0;
}
