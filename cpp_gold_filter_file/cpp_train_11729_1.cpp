#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  string s;
  vector<int> c, C;
  cin >> s;
  c.assign(26, 0);
  C.assign(26, 0);
  for (char ch : s)
    if ('a' <= ch && ch <= 'z')
      c[ch - 'a']++;
    else
      C[ch - 'A']++;
  int opt = 0;
  for (int i = 0; i < 26; i++) opt = max({opt, c[i], C[i]});
  if (opt == (int)((s).size()) && n == 1)
    opt--;
  else
    opt = min((int)((s).size()), opt + n);
  cin >> s;
  c.assign(26, 0);
  C.assign(26, 0);
  for (char ch : s)
    if ('a' <= ch && ch <= 'z')
      c[ch - 'a']++;
    else
      C[ch - 'A']++;
  int opt1 = 0;
  for (int i = 0; i < 26; i++) opt1 = max({opt1, c[i], C[i]});
  if (opt1 == (int)((s).size()) && n == 1)
    opt1--;
  else
    opt1 = min((int)((s).size()), opt1 + n);
  cin >> s;
  c.assign(26, 0);
  C.assign(26, 0);
  for (char ch : s)
    if ('a' <= ch && ch <= 'z')
      c[ch - 'a']++;
    else
      C[ch - 'A']++;
  int opt2 = 0;
  for (int i = 0; i < 26; i++) opt2 = max({opt2, c[i], C[i]});
  if (opt2 == (int)((s).size()) && n == 1)
    opt2--;
  else
    opt2 = min((int)((s).size()), opt2 + n);
  if (opt > opt1 && opt > opt2)
    cout << "Kuro";
  else if (opt1 > opt && opt1 > opt2)
    cout << "Shiro";
  else if (opt2 > opt && opt2 > opt1)
    cout << "Katie";
  else
    cout << "Draw";
}
