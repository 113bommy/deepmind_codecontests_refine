#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << 6 << " " << n - 6;
  } else
    cout << 9 << " " << n - 9;
}
