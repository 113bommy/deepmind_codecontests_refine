#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i < 9; i++) cout << i << '?' << "?<>" << i + 1 << endl;
  cout << "9?"
       << "?>>??0" << endl;
  cout << "??0<>10" << endl;
  for (int i = 0; i <= 9; i++) cout << "?" << i << ">>" << i << "?" << endl;
  cout << "?>>??" << endl;
  cout << ">>?" << endl;
  return 0;
}
