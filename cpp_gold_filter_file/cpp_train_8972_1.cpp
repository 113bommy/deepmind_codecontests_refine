#include <bits/stdc++.h>
using namespace std;
long long area[1005], n;
vector<int> lef, righ;
bool cmp(int first, int second) { return area[first] < area[second]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int adj1 = 2;
  for (int i = 3; i <= n; i++) {
    cout << 2 << ' ' << 1 << ' ' << adj1 << ' ' << i << endl;
    int u;
    cin >> u;
    if (u < 0) {
      adj1 = i;
    }
  }
  int far1 = -1;
  long long mx = 0;
  for (int i = 2; i <= n; i++) {
    if (i == adj1) continue;
    cout << 1 << ' ' << adj1 << ' ' << 1 << ' ' << i << endl;
    long long u;
    cin >> u;
    area[i] = u;
    if (u > mx) {
      far1 = i;
      mx = u;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (i == far1) continue;
    cout << 2 << ' ' << 1 << ' ' << far1 << ' ' << i << endl;
    int u;
    cin >> u;
    if (u < 0)
      lef.push_back(i);
    else
      righ.push_back(i);
  }
  sort(lef.begin(), lef.end(), cmp);
  sort(righ.begin(), righ.end(), cmp);
  cout << 0 << ' ';
  cout << 1 << ' ';
  for (auto u : lef) {
    cout << u << ' ';
  }
  cout << far1 << ' ';
  for (int i = (int)righ.size() - 1; i >= 0; i--) {
    cout << righ[i] << ' ';
  }
  return 0;
}
