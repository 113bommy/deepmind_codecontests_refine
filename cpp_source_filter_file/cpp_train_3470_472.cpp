#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << 2 << endl;
  } else {
    cout << (n % 3) + 1 << endl;
  }
  return 0;
}
