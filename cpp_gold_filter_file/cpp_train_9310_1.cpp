#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  int a, i = 1;
  cin >> s1;
  a = s1.find("at", i);
  s1.replace(a, 2, "@");
  a = s1.find("dot", i);
  while (a != s1.npos && a != s1.size() - 3) {
    s1.replace(a, 3, ".");
    a = s1.find("dot", i);
  }
  cout << s1 << " " << endl;
  return 0;
}
