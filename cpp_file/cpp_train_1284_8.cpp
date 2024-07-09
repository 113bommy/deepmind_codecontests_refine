#include <bits/stdc++.h>
using namespace std;
int n, k, t, mt[30][30], ev[1000000], it = 0;
bool usedw[30], usedm[30];
void rec(int cost, int l, int r) {
  if (r == n + 1) {
    l++;
    r = 1;
  }
  if (l == n + 1) {
    ev[++it] = cost;
    return;
  }
  int newL = l, newR = r;
  newR++;
  rec(cost, newL, newR);
  if (!usedw[l] && !usedm[r] && mt[l][r] != 0) {
    usedw[l] = true;
    usedm[r] = true;
    rec(cost + mt[l][r], newL, newR);
    usedw[l] = false;
    usedm[r] = false;
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &t);
  for (int i = 1; i <= k; i++) {
    int l, r, v;
    scanf("%d%d%d", &l, &r, &v);
    mt[l][r] = v;
  }
  rec(0, 1, 1);
  sort(ev + 1, ev + it + 1);
  cout << ev[t] << endl;
  return 0;
}
