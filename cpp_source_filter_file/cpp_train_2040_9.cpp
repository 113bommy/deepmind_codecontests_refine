#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << (n + 1) / 2;
  } else {
    cout << (n / 2) - 1;
  }
}
