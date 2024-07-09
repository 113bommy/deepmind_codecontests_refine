#include <bits/stdc++.h>
using namespace std;
const int N = 200000, M = 400;
int n, a[N + 9], c[N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++c[a[i]];
  }
}
int d[N + 9], pos[N * 2 + 9], ans;
void Get_ans(int x, int y) {
  for (int i = 1; i <= n; ++i) d[i] = a[i] == x ? 1 : a[i] == y ? -1 : 0;
  for (int i = 0; i <= n << 1; ++i) pos[i] = -1;
  int now = 0;
  pos[now + n] = 0;
  for (int i = 1; i <= n; ++i) {
    now += d[i];
    pos[now + n] == -1 ? pos[now + n] = i : ans = max(ans, i - pos[now + n]);
  }
}
int ord[N + 9];
bool cmp(const int &a, const int &b) { return c[a] > c[b]; }
int vis[N + 9];
void Get_ans() {
  int mx = 0;
  for (int i = 1; i <= n; ++i)
    if (c[i] > c[mx]) mx = i;
  int co = 0;
  for (int i = 1; i <= n; ++i)
    if (c[i]) ord[++co] = i;
  sort(ord + 1, ord + co + 1, cmp);
  for (int i = 1; i <= M && i <= co; ++i)
    if (ord[i] ^ mx) Get_ans(ord[i], mx);
  for (int i = 1; i <= n; ++i) ord[i] = i;
  for (int i = 1; i <= 5; ++i) random_shuffle(ord + 1, ord + n + 1);
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[ord[i]]) continue;
    if (ord[i] ^ mx) Get_ans(ord[i], mx);
    vis[ord[i]] = 1;
    ++c;
    if (c > M) return;
  }
}
void work() { Get_ans(); }
void outo() { printf("%d\n", ans); }
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
