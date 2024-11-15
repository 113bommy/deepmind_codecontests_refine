#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1e9 + 7;
void add(int64_t& a, int64_t b) {
  a %= MOD;
  b %= MOD;
  a = (a + b + 2 * MOD) % MOD;
}
void mul(int64_t& a, int64_t b) { a = a * b % MOD; }
int N;
int64_t V[200000];
vector<int> edges[200000];
int64_t num[200000][2];
void dfs(int i, int p) {
  for (int j : edges[i])
    if (j != p) {
      dfs(j, i);
      num[i][0] += num[j][1];
      num[i][1] += num[j][0] + 1;
    }
}
int64_t ans = 0;
void dfs2(int i, int p, int64_t n0, int64_t n1) {
  int64_t C = 2 * (n0 * num[i][0] - n1 * num[i][1]);
  add(C, 2 * (n0 + num[i][0]));
  add(C, num[i][0] * num[i][0] - num[i][1] * num[i][1]);
  for (int j : edges[i])
    if (j != p)
      add(C, -(num[j][1] * num[j][1] - (num[j][0] + 1) * (num[j][0] + 1)));
  add(ans, C * V[i]);
  for (int j : edges[i])
    if (j != p) {
      int m0 = n1 + num[i][1] - num[j][0] - 1;
      int m1 = n0 + num[i][0] - num[j][1] + 1;
      dfs2(j, i, m0, m1);
    }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) scanf("%ld", &V[i]);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }
  dfs(0, -1);
  dfs2(0, -1, 0, 0);
  cout << ans << endl;
  return 0;
}
