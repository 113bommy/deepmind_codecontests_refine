#include <bits/stdc++.h>
using namespace std;
int n, a, w, i, ans, m;
int main() {
  cin >> n >> w >> m;
  for (i = 1; i <= n; i++) {
    cin >> a;
    ans = (a * w) % m;
    cout << ans / a << " ";
  }
}
