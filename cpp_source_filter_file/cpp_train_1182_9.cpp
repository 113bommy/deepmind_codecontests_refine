#include <bits/stdc++.h>
using namespace std;
const int maxn = 500100;
int n, q, dir, len, tot;
int tim, st, pre;
int sum[maxn * 5][10], cnt[10];
char c[maxn];
bool bo[maxn];
vector<int> V[maxn];
void add(int x) {
  tim++;
  V[x].push_back(tim);
  for (int i = 0; i < 10; i++) sum[tim][i] = cnt[i];
}
int Find(int x, int y) {
  int t = lower_bound(V[x].begin(), V[x].end(), y) - V[x].begin();
  if (t == V[x].size()) return tim + 1;
  return V[x][t];
}
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", c + 1);
  tim = 0;
  for (int i = 1; i <= n; i++) {
    if (!bo[i]) {
      st = i;
      pre = 0;
      dir = 1;
      while (st >= i && st <= n) {
        bo[st] = 1;
        if (c[st] >= '0' && c[st] <= '9') {
          int t = c[st] - '0';
          cnt[t]++;
          c[st]--;
          pre = 0;
        } else if (c[st] == '<' || c[st] == '>') {
          dir = c[st] == '>' ? 1 : -1;
          if (pre) c[pre] = 0;
          pre = st;
        }
        add(st);
        st += dir;
      }
      add(st);
    }
  }
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int xx = V[u][0], yy = min(Find(u - 1, xx), Find(v + 1, xx));
    for (int j = 0; j < 10; j++)
      printf("%d%c", sum[yy - 1][j] - sum[xx - 1][j], j == 9 ? '\n' : ' ');
  }
  return 0;
}
