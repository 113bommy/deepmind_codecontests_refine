#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  if (n == 1)
    cout << "1" << endl;
  else if (n == 2)
    cout << "2" << endl;
  else if (n == 3)
    cout << "3" << endl;
  else
    cout << (n / 2) + 1 << endl;
}
