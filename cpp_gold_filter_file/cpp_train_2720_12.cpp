#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n % 4 == 3 || n % 4 == 0)
    cout << 0;
  else
    cout << 1;
  return 0;
}
