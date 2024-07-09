#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int I(int n) {
  if (n <= 1) return 1;
  return I(n - 1) + (n - 1) * I(n - 2);
}
int P(int n, int k) {
  int p = 1;
  for (int i = 0; i < k; ++i) p *= n - i;
  return p;
}
int f(int a, int b) { return P(a + b, b) * I(a); }
void solve(istream &in, ostream &out) {
  int n;
  in >> n;
  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    int c;
    in >> c;
    if (c == 1)
      ++a;
    else
      ++b;
  }
  out << f(a, b) << endl;
}
int main() {
  solve(cin, cout);
  return 0;
}
