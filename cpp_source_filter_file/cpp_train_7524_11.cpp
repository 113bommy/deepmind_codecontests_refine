#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string s, p;
int a[maxn], ans;
int judge(void) {
  int cnt = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    if (a[i] < 0) cnt += a[i];
    if (a[i] > 0) return 0;
  }
  if (cnt <= a['?'])
    return 1;
  else
    return 0;
}
int main(void) {
  cin >> s >> p;
  if (s.size() < p.size()) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < p.size(); i++) a[s[i]]++;
  for (int i = 0; i < p.size(); i++) a[p[i]]--;
  ans += judge();
  for (int i = 0; i <= s.size() - p.size(); i++) {
    a[s[i + p.size()]]++;
    a[s[i]]--;
    ans += judge();
  }
  cout << ans << endl;
}
