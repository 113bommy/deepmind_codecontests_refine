#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
map<int, int> f, l;
long long pref[300100], a[300100];
const long long MAX = 1000000000000000;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (f.find(a[i]) == f.end()) {
      f[a[i]] = i;
    }
    l[a[i]] = i;
    pref[i] = pref[i - 1];
    if (a[i - 1] > 0) pref[i] += a[i - 1];
  }
  long long mx = -MAX, ansx, ansy;
  for (int i = 1; i <= n; i++) {
    int x = f[a[i]], y = l[a[i]];
    if (x != y && pref[y] - pref[x + 1] + 2 * a[i] > mx) {
      mx = pref[y] - pref[x + 1] + 2 * a[i];
      ansx = x, ansy = y;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i < ansx || i > ansy) ans.push_back(i);
    if (ansx <= i && i <= ansy && a[i] < 0) ans.push_back(i);
  }
  cout << mx << " " << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
