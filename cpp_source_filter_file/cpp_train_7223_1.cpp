#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string str;
  cin >> N;
  cin.ignore();
  while (N--) {
    bool a = 0, b = 0;
    getline(cin, str);
    if (str.size() > 5 && str.substr(0, 5) == "miao.") a = 1;
    if (str.size() > 5 && str.substr(str.size() - 5) == "lala.") b = 1;
    if ((a ^ b) == 0)
      cout << "OMG>.< I don't know!" << endl;
    else if (a)
      cout << "Rainbow's" << endl;
    else
      cout << "Freda's" << endl;
  }
  return 0;
}
