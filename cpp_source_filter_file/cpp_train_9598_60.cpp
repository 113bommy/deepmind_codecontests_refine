#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << max(a + 1, n - b);
}
