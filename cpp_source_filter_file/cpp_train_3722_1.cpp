#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int po[999994], cr[14];
map<int, int> mert;
void calc(int L) {
  int x = 0;
  for (int i = 1; i <= L; i++) x = x * 10 + cr[i];
  if (x == 0)
    return;
  else if (!mert.count(x)) {
    mert[x] = 1;
    po[++cnt] = x;
  }
}
void dfs(int cur, int limit) {
  if (cur > limit)
    calc(limit);
  else
    for (int i = 0; i <= 1; i++) {
      cr[cur] = i;
      dfs(cur + 1, limit);
    }
}
int main() {
  cin >> n;
  for (int i = 1; i <= 9; i++) dfs(1, i);
  sort(po + 1, po + cnt + 1);
  int i = 0;
  for (i = 1; po[i] <= n; i++)
    ;
  cout << i - 1 << endl;
  return 0;
}
