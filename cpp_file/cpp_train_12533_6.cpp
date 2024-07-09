#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(std::cin, s);
  int n = 10, rz = 1;
  char c[10] = {0};
  if (s[0] == '?') rz = 9;
  if (s[0] >= 'A' && s[0] <= 'J') {
    c[s[0] - 'A'] = 1;
    rz = 9;
    n--;
  }
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == '?')
      rz = rz * 10;
    else if (s[i] >= 'A' && s[i] <= 'J') {
      if (c[s[i] - 'A'] == 0) {
        c[s[i] - 'A'] = 1;
        rz = rz * n;
        n--;
      }
    }
  }
  cout << rz << endl;
  return 0;
}
