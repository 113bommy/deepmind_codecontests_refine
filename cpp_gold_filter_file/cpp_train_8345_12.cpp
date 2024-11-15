#include <bits/stdc++.h>
using namespace std;
double calc(string s) {
  int n = s.length(), p = 0, q = 0, cnt = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    char ch = (q & 1) ? 'R' : 'L';
    if (s[i] == 'X')
      ++q;
    else if (s[i] == ch)
      ++p, ++q, cur = 0;
    else
      ++p, q += 2, cnt += cur, cur = !cur;
  }
  if (q & 1) ++q, cnt += cur;
  if (p * 2 > q) {
    p -= cnt;
    q -= 2 * cnt;
  }
  return 1.0 * p / q;
}
int main() {
  string s, t;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (i > 0 && s[i] == s[i - 1] && s[i] != 'X') t += 'X';
    t += s[i];
  }
  double ans;
  if (t[0] == t[t.length() - 1] && t[0] != 'X')
    ans = max(calc(t + 'X'), calc('X' + t));
  else
    ans = calc(t);
  cout << fixed << setprecision(6) << floor(ans * 1e8) / 1e6 << endl;
}
