#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n % 2 == 0)
    cout << n - 9 << " " << 9;
  else
    cout << n - 4 << " " << 4;
  return 0;
}
