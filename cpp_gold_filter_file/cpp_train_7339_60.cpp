#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 100005;
char s[8][8];
int main() {
  ;
  for (int i = 0; i < 8; ++i) {
    gets(s[i]);
  }
  int mn1 = 10;
  int mn2 = 10;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (s[i][j] == 'W') {
        int flag = 0;
        for (int k = 0; k < i; ++k) {
          if (s[k][j] != '.') {
            flag = 1;
          }
        }
        if (!flag) mn1 = min(i, mn1);
      } else if (s[i][j] == 'B') {
        int flag = 0;
        for (int k = 7; k > i; --k) {
          if (s[k][j] != '.') {
            flag = 1;
          }
        }
        if (!flag) mn2 = min(7 - i, mn2);
      }
    }
  }
  if (mn1 <= mn2) {
    cout << "A";
  } else {
    cout << "B";
  }
  return 0;
}
