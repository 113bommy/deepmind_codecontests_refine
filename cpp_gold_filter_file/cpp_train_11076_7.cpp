#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int ans = 0, t = 0;
  string s, a;
  cin >> s;
  for (long long int i = 0; i < s.length(); i++) {
    a = s.substr(i, 5);
    if (a == "heavy") t++;
    if (a == "metal") ans += t;
  }
  cout << ans;
  return 0;
}
