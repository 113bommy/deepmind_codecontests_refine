#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n <= min(m, k))
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
