#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << max(0, (n * k + 99) / 100) - n;
}
