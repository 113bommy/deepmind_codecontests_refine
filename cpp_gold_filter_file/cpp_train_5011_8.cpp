#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
      if (s[i + 1] == 'R')
        s[i + 1] = 'B';
      else
        s[i + 1] = 'R';
    } else if (s[i] == s[i + 1] && s[i + 1] != s[i + 2]) {
      if (s[i + 1] == 'R' && s[i + 2] != 'B')
        s[i + 1] = 'B';
      else if (s[i + 1] == 'R' && s[i + 2] == 'B')
        s[i + 1] = 'G';
      else if (s[i + 1] == 'B' && s[i + 2] != 'G')
        s[i + 1] = 'G';
      else if (s[i + 1] == 'B' && s[i + 2] == 'G')
        s[i + 1] = 'R';
      else if (s[i + 1] == 'G' && s[i + 2] != 'R')
        s[i + 1] = 'R';
      else if (s[i + 1] == 'G' && s[i + 2] == 'R')
        s[i + 1] = 'B';
    }
  }
  int k = s.size() - 1;
  if (s[k] == s[k - 1]) {
    if (s[k - 1] == 'R')
      s[k] = 'B';
    else
      s[k] = 'R';
  }
  int cnt = 0;
  for (int i = 0; i < t.size(); i++) {
    if (s[i] != t[i]) cnt++;
  }
  cout << cnt << endl;
  cout << s << endl;
}
