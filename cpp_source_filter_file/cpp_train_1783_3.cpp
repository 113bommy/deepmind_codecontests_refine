#include <bits/stdc++.h>
using namespace std;
void add_leading_zero() {
  cout << "d0d1usut0dudstedeuu";
  cout << "uu0u1dsdt0udusteueddd";
}
void add_up() {
  cout << "d"
       << "d10utu"
       << "d"
       << "d10utu"
       << "uu"
       << "d10utu"
       << "d"
       << "d10utu"
       << "d"
       << "l10rtr"
       << "010ltdt"
       << "u10dtd"
       << "uu";
  cout << "0dlrtu";
  cout << "d"
       << "d10utu"
       << "d"
       << "d10utu"
       << "uu"
       << "d10utu"
       << "d"
       << "d10utu"
       << "d"
       << "l10rtr"
       << "010ltdt"
       << "u10dtd"
       << "uu";
  cout << "lltr";
}
void add_per_bit() {
  cout << "d10utu"
       << "d"
       << "l10rtr"
       << "ll0l1rrr";
  add_up();
  cout << "uu"
       << "d10utu"
       << "d"
       << "d10utu"
       << "d"
       << "l10rtr";
  add_up();
}
int main() {
  for (int i = 0; i <= 30; i++) add_leading_zero(), cout << "l";
  cout << "rdd";
  for (int i = 0; i <= 30; i++) cout << "0r";
  cout << "uu";
  for (int i = 0; i <= 30; i++) {
    add_per_bit();
    cout << "ul";
  }
  cout << "r";
  return 0;
}
