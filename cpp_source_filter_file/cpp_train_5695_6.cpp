#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int cnt = 1;
  vector<int> v;
  for (int i = 1; i < 6; i++)
    if (s[i] != s[i - 1])
      v.push_back(cnt), cnt = 1;
    else
      cnt++;
  v.push_back(cnt);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int ans = 0;
  if (v[0] >= 5) ans = 1;
  if (v[0] == 4) ans = 2;
  if (v[0] == 3) {
    if (v[1] == 3) ans = 2;
    if (v[1] == 2) ans = 3;
    if (v[1] == 1) ans = 5;
  }
  if (v[0] == 2) {
    if (v.size() == 3) ans = 6;
    if (v.size() == 4) ans = 7;
    if (v.size() == 5) ans = 15;
  }
  if (v.size() == 6) ans = 30;
  cout << ans << endl;
  return 0;
}
