#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  string s;
  cin >> n >> s;
  bool flag = false;
  for (int i = 0; i < n - 5; i++) {
    for (int j = 1; i + 4 * j < n; j++) {
      if (s[i] == '*' and s[i + j] == '*' and s[i + 2 * j] == '*' and
          s[i + 3 * j] == '*' and s[i + 4 * j] == '*') {
        flag = true;
        break;
      }
    }
  }
  if (flag)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
