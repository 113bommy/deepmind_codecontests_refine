#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << min(n, min(m, (n + m) / 3 + 1));
}
