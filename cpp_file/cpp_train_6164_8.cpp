#include <bits/stdc++.h>
using namespace std;
int x[26];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (char c : s) {
      x[c - 'a'] = i;
    }
  }
  set<int> s;
  for (int i = 0; i < 26; ++i) {
    if (x[i] != 0) {
      s.insert(x[i]);
    }
  }
  cout << s.size();
}
