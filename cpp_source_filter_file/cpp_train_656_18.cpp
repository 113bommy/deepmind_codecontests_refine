#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += a * a;
  }
  cout << ans << endl;
  return 0;
}
