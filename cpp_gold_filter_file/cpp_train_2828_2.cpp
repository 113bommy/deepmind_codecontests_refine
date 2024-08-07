#include <bits/stdc++.h>
using namespace std;
int n;
char mat[5001][5001];
vector<int> e[5001];
bool vst[5001];
bool dfs(int now, int pre) {
  vst[now] = true;
  for (int next = 0; next < n; ++next)
    if (mat[now][next] - '0') {
      if (mat[next][pre] - '0') {
        printf("%d %d %d\n", pre + 1, now + 1, next + 1);
        return true;
      }
      if (!vst[next] && dfs(next, now)) return true;
    }
  return false;
}
int main() {
  scanf("%d%*c", &n);
  for (int i = 0; i < n; ++i) {
    gets(mat[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (!vst[i] && dfs(i, i)) return 0;
  }
  puts("-1");
}
