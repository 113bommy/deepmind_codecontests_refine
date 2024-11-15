#include <bits/stdc++.h>
using namespace std;
const int N = 125, modu = int(1e9) + 7;
int m, cnt[N], lm, res;
void solve(int x, int r, bitset<N> prv) {
  if (x > lm) {
    res = (res + r) % modu;
    return;
  }
  solve(x + 1, r, prv);
  if (cnt[x] && !prv[x]) {
    bitset<N> nxt =
        prv | (prv >> x) | (prv << x) | (prv >> (m - x)) | (prv << (m - x));
    solve(x + 1, (long long)r * cnt[x] % modu, nxt);
  }
}
int main() {
  int k, a;
  scanf("%*d%d%d", &m, &k);
  while (k--) scanf("%d", &a), cnt[min(a % m, m - a % m)]++;
  lm = (m + 1) / 2;
  bitset<N> cur;
  cur = 0;
  solve(1, 1, cur);
  printf("%d\n", res);
  return 0;
}
