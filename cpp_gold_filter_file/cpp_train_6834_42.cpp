#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 36) return cout << -1, 0;
  for (int i = 0; i < n / 2; i++) cout << 8;
  if (n % 2) cout << 4;
}
