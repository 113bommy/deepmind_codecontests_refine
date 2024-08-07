#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int last_hash = -1;
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '#') last_hash = i;
  for (int i = last_hash + 1; i < s.size(); ++i) cnt += (s[i] == '(' ? 1 : -1);
  if (cnt > 0 && s[s.size() - 1] == '(') {
    cout << -1;
    return 0;
  }
  int open = 0;
  int hash = 0;
  for (int i = 0; i < s.size(); ++i) {
    open += (s[i] == '(' ? 1 : -1);
    hash += (s[i] == '#');
    if (open < 0) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < hash - 1; ++i) cout << 1 << " ";
  cout << open + 1;
}
