#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int check[MAXN] = {};
int prime[MAXN], ptot;
vector<int> cnt[5][MAXN];
int len;
int mp[5][5];
void init(int N) {
  ptot = 0;
  for (int i = 2; i <= N; i++) {
    if (!check[i]) {
      prime[++ptot] = i;
      int p = i;
      for (int j = 1; j < 5; j++) {
        p /= 10;
        cnt[j][p].push_back(i);
      }
    }
    for (int j = 1; j <= ptot; j++) {
      if (i * prime[j] > N) break;
      check[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int dfs(int cur) {
  int num = 0;
  for (int i = 0; i < cur; i++) {
    num = num * 10 + mp[cur][i];
  }
  if (cur + 1 == len) return cnt[1][num].size();
  int ret = 0;
  for (int i = 0; i < cnt[len - cur][num].size(); i++) {
    int v = cnt[len - cur][num][i];
    for (int j = len - 1; j >= cur; j--) {
      mp[cur][j] = mp[j][cur] = v % 10;
      v /= 10;
    }
    ret += dfs(cur + 1);
  }
  return ret;
}
void work() {
  char str[5] = {};
  scanf("%s", str);
  len = strlen(str);
  for (int i = 0; i < len; i++) {
    mp[0][i] = mp[i][0] = str[i] - '0';
  }
  printf("%d\n", dfs(1));
  return;
}
int main() {
  init(1e5);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) work();
  return 0;
}
