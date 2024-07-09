#include <bits/stdc++.h>
using namespace std;
int f[100];
char s[100];
int main() {
  int a, b, c, r = 0;
  cin >> a >> b >> c;
  for (int i = 0; i < a; i++) {
    cin >> s;
    for (int j = 0; j < b; j++) {
      if (s[j] == 'Y') {
        f[j]++;
        if (f[j] == c) r++;
      }
    }
  }
  cout << r;
}
