#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 3 == 2)
    cout << "1 "
         << "2 " << n - 3 << "\n";
  else
    cout << "1 "
         << "1 " << n - 1 << "\n";
}
