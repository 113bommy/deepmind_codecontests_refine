#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 111;
const int LEN = 505;
int n, k;
int p[N];
int len[N];
int f[N][N];
char s[N][LEN];
vector<int> have;
int get(int x) {
  int ret = 0;
  for (int i = 0; i < (int)have.size(); i++)
    if (have[i] != x) ret += f[have[i]][x];
  return ret;
}
int get(int x, int y) {
  int ret = 0;
  for (int i = 0; i < (int)have.size(); i++)
    if (have[i] != x) ret -= f[have[i]][x];
  for (int i = 0; i < (int)have.size(); i++)
    if (have[i] != x && have[i] != y) ret += f[have[i]][y];
  return ret;
}
int main() {
  scanf("%d%d\n", &n, &k);
  for (int i = 1; i <= n; i++) {
    gets(s[i] + 1);
    len[i] = (int)strlen(s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      f[i][j] = f[j][i] = 0;
      int ptr = 0;
      while (ptr + 1 <= min(len[i], len[j]) && s[i][ptr + 1] == s[j][ptr + 1])
        ++ptr;
      f[i][j] = f[j][i] = ptr;
    }
  }
  int ans = 0;
  vector<int>::iterator it;
  for (int i = 1; i <= n; i++) {
    if ((int)have.size() < k) {
      ans += get(i);
      have.push_back(i);
      continue;
    }
    int add = 0;
    int idx = -1;
    for (int j = 0; j < (int)have.size(); j++) {
      int val = get(have[j], i);
      if (val > add) {
        add = val;
        idx = have[j];
      }
    }
    if (add > 0) {
      it = find(have.begin(), have.end(), idx);
      have.erase(it);
      have.push_back(i);
      ans += add;
    }
  }
  have.clear();
  for (int i = 1; i <= n; i++) p[i] = i;
  int iter = 10000;
  if (n <= 20) {
    iter *= 100;
  }
  while (iter--) {
    random_shuffle(p + 1, p + 1 + n);
    have.clear();
    int cur = 0;
    for (int i = 1; i <= k; i++) {
      cur += get(p[i]);
      have.push_back(p[i]);
    }
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}
