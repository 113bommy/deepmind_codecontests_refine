#include <bits/stdc++.h>
const int inf = 1000000009;
const double pi = acos(-1.0);
using namespace std;
int i, j, k, m, n, r, g;
vector<int> v;
int lost() {
  for (int i = 0; i < 15; i++) {
    int cnt = 0;
    for (int j = 0; j < v.size(); j++)
      if (v[j] & (1 << i)) cnt++;
    if (cnt % (k + 1) != 0) return 0;
  }
  return 1;
}
int main() {
  cin >> m >> n >> k;
  string s;
  for (i = 0; i < m; i++) {
    cin >> s;
    if (s.find('R') == -1 && s.find('G') == -1) continue;
    if (s.find('R') == -1) {
      if (s.find('-') != -1) g++;
    } else if (s.find('G') == -1) {
      if (s.find('-') != -1) r++;
    } else {
      int x = s.find('R');
      int y = s.find('G');
      v.push_back(abs(x - y) - 1);
    }
  }
  if (g > 0 && r > 0)
    cout << "Draw";
  else if (g > 0)
    cout << "First";
  else if (r > 0)
    cout << "Second";
  else {
    if (lost())
      cout << "Second";
    else
      cout << "First";
  }
  return 0;
}
