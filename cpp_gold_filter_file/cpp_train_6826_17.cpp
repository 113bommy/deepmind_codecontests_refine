#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int s = 0, sum = -10000000;
  string c, ans;
  int sh, ush, score;
  for (int i = 0; i < n; i++) {
    cin >> c >> sh >> ush;
    s = 0;
    for (int j = 0; j < 5; j++) {
      cin >> score;
      s += score;
    }
    s += ((sh * 100) - (ush * 50));
    if (s > sum) {
      sum = s;
      ans = c;
    }
  }
  cout << ans;
  return 0;
}
