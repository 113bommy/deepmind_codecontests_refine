#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int N;
int mx, mn = 2000000000;
int main() {
  scanf("%d", &N);
  for (int Ni = 0; Ni < N; Ni++) {
    int t;
    scanf("%d", &t);
    mx = max(mx, t);
    mn = min(mn, t);
    m[t]++;
  }
  int p = m[mn], q;
  if (mn == mx && m[mn] != 1) {
    puts("NO");
    return 0;
  }
  for (int mi = mn + 1; mi < mx; mi++) {
    q = m[mi] - p;
    if (q < 1) {
      puts("NO");
      return 0;
    }
    p = q;
  }
  if (m[mx] != p)
    puts("NO");
  else
    puts("YES");
}
