#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if ((m - n) >= 0 && (k - n) >= 0) {
    cout << "yes";
  } else {
    cout << "no";
  }
  return 0;
}
