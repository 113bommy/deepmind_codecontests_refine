#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, ta, b, tb, ans = 0, x, y;
  int h, m, q;
  q = (24 * 60) - (5 * 60);
  cin >> a >> ta >> b >> tb;
  scanf("%d:%d", &h, &m) == 2;
  int x1 = h * 60 + m, y1 = x1 + ta;
  for (int i = 0; i < 1440; i += b) {
    int y2 = i + tb;
    x = max(x1, i);
    y = min(y1, y2);
    if (x < y) {
      ans++;
    }
  }
  cout << ans;
}
