#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cout << (i + 1) % n + 1 << " ";
}
