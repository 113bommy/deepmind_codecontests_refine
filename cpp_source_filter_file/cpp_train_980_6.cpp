#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a, b;
  int aw = 0, bw = 0;
  for (int i = 0; i < a.size(); i += 2) {
    if (a[i] == '8' && b[i] == '[') aw++;
    if (a[i] == '[' && b[i] == '(') aw++;
    if (a[i] == '(' && b[i] == '8') aw++;
    if (b[i] == '8' && a[i] == '[') bw++;
    if (b[i] == '[' && a[i] == '(') bw++;
    if (b[i] == '(' && a[i] == '8') bw++;
  }
  if (aw == bw)
    cout << "TIE" << endl;
  else if (aw > bw)
    cout << "TEAM 1 WINS" << endl;
  else if (aw < bw)
    cout << "TEAM 2 WINS" << endl;
  return 0;
}
