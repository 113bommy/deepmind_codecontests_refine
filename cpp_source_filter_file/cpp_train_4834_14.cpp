#include <bits/stdc++.h>
using namespace std;
vector<int> ans[105];
vector<int> lag, kom;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  lag.resize(m);
  kom.resize(k);
  for (int i = 0; i < m; cin >> lag[i], i++)
    ;
  for (int i = 0; i < k; cin >> kom[i], i++)
    ;
  int kol = 0;
  for (int i = 0; i < m; i++) {
    kol = 0;
    for (int j = 0; j < k; j++)
      if (kom[j] % lag[i] == 0) kol++;
    ans[kol].push_back(i + 1);
  }
  for (int i = 1; i <= k; i++)
    if (ans[i].size()) {
      cout << ans[i].size() << "\n";
      for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
      break;
    }
  return 0;
}
