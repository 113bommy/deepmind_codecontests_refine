#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (a % 2 == 0) {
    cout << (a + 2) / 2;
  } else {
    cout << (a + 1) / 2;
  }
  return 0;
}
