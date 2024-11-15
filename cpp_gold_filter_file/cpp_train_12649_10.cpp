#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> V;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    V.push_back(x);
  }
  sort(V.begin(), V.end());
  int ans = INT_MAX;
  for (int i = 0; i < n / 2; ++i) {
    int j = i + n / 2;
    ans = min(ans, V[j] - V[i]);
  }
  cout << ans << endl;
  return 0;
}
