#include <bits/stdc++.h>
using namespace std;
double eval(string s) {
  int g = 0, t = 0, f = 0, c = 0;
  for (unsigned int i = 0; i < s.length(); i++) {
    if (s[i] == 'X')
      t++;
    else if (s[i] == (t & 1 ? 'R' : 'L'))
      g++, t++, f = 0;
    else
      g++, t += 2, c += f, f = !f;
  }
  if (t & 1) t++, c += f;
  if (g * 2 > t) g -= c, t -= c * 2;
  return double(g) / t;
}
int main() {
  string s, t;
  cin >> s;
  for (unsigned int i = 0; i < s.length() - 1; i++) {
    t += s[i];
    if (s[i] != 'X' && s[i] == s[i + 1]) t += 'X';
  }
  string::iterator a = s.end();
  --a;
  if (s[s.length() - 1] != (*a))
    t += s[s.length() - 1];
  else
    t += (*a);
  double ans;
  if (t[0] == t[t.length() - 1] && t[0] != 'X')
    ans = max(eval('X' + t), eval(t + 'X'));
  else
    ans = eval(t);
  ans = floor(ans * 1e8) / 1e6;
  printf("%.6lf\n", ans);
}
