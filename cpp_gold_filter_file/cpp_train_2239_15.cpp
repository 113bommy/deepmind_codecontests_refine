#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long d1, d2, d3;
  cin >> d1 >> d2 >> d3;
  cout << min(min((2 * d1 + 2 * d2), (d1 + d2 + d3)),
              min((2 * d1 + 2 * d3), (2 * d2 + 2 * d3)));
  return 0;
}
