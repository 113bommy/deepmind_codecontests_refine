#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  cin >> s1;
  int s2 = s1.length();
  int count = 1;
  int koeff1 = 1;
  int mass1[100];
  int for1, for2;
  for (for2 = 0; for2 < 99; for2++) {
    mass1[for2] = 0;
  };
  if (int(s1[0]) > 47 && int(s1[0]) < 58) {
    count = count * 1;
  };
  if (int(s1[0]) > 64 && int(s1[0]) < 75) {
    count = count * 9;
    koeff1 += 1;
    mass1[int(s1[0])] = 1;
  };
  if (int(s1[0]) == 63) {
    count = count * 9;
  };
  for (for1 = 1; for1 < s2; for1++) {
    if (int(s1[for1]) == 63) {
      count = count * 10;
    };
    if (int(s1[for1]) > 64 && int(s1[for1]) < 75) {
      if (mass1[int(s1[for1])] == 0) {
        count = count * (11 - koeff1);
        if (mass1[int(s1[for1])] == 0) {
          mass1[int(s1[for1])] = 1;
          koeff1 += 1;
        }
      }
    }
  }
  cout << count << endl;
}
