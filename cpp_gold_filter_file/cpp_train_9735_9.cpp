#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7, k, p;
bool ch[1001000];
void dfs(int x) {
  if (ch[x]) return;
  ch[x] = true;
  dfs((1LL * x * k) % p);
}
int main() {
  int i, ans = 0;
  scanf("%d %d", &p, &k);
  for (i = 0; i < p; i++) {
    if ((1LL * k * i) % p == i) ans++;
  }
  for (i = 1; i < p; i++) {
    if (!ch[i]) {
      dfs(i);
      ans = (1LL * ans * p) % mod;
    }
  }
  cout << ans;
}
