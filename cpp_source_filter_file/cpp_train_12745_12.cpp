#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p;
  cin >> n >> p >> k;
  if (n - k > 1) cout << "<<";
  for (int i = p - k; i < p + k + 1; i++) {
    if (i == p)
      cout << " " << '(' << p << ')';
    else if (i > 0 && i <= n)
      cout << " " << i;
  }
  if (p + k < n)
    cout << " "
         << ">>" << endl;
  return 0;
}
