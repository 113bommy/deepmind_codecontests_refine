#include <bits/stdc++.h>
using namespace std;
int n;
string s, d;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if ((n - i) % 2 == 0)
      d = d + s[i];
    else
      d = s[i] + d;
  }
  cout << d;
}
