#include <bits/stdc++.h>
using namespace std;
long long n, m, wor = 0;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> s;
  wor = n * (m - 1);
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1]) wor += n * (m - 1);
  long long cnt = 1;
  for (int i = 1; i < n; i++) {
    if (cnt < 2) {
      if (s[i] == s[i - 1])
        continue;
      else
        cnt++;
    } else {
      if (s[i - 2] == s[i])
        cnt++;
      else {
        wor -= cnt * (cnt - 1) / 2;
        if (s[i] == s[i - 1])
          cnt = 1;
        else
          cnt = 2;
      }
    }
  }
  wor -= cnt * (cnt - 1) / 2;
  cout << wor << endl;
  return 0;
}
