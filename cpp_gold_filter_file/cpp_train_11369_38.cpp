#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int x = 0, y = 0;
  cin >> s;
  for (int i = 0; s[i]; i++)
    if (s[i] == '>') {
      if (s[i - 2] == '/') y -= 2;
      for (int i = 0; i < y; i++) cout << " ";
      for (int j = x; j <= i; j++) cout << s[j];
      cout << endl;
      if (s[i - 2] != '/') y += 2;
      x = i + 1;
    }
}
