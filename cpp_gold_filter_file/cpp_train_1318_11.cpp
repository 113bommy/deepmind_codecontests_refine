#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int jk = 0, jk1 = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-')
      jk++;
    else
      jk1++;
  }
  if (jk1 == 0)
    cout << "YES";
  else if (jk % jk1 == 0)
    cout << "YES" << endl;
  else
    cout << "NO";
}
