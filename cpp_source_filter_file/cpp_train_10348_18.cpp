#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, g, b, j;
  cin >> n >> m;
  g = max(n, m);
  b = min(n, m);
  cout << g + (b - 1) << "\n";
  for (int i = 1; i <= g; i++) cout << "1 " << i << endl;
  for (int j = 2; j <= b; j++) cout << j << " 1" << endl;
  return 0;
}
