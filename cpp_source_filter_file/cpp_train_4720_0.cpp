#include <bits/stdc++.h>
using namespace std;
const int maxv = 10000001;
const int maxq = 4000;
int r[maxv];
void calc() {
  for (int i = 1; i <= maxq; ++i) {
    int t = i * i;
    for (int j = t, jj = 1; j < maxv; ++jj, j += t) r[j] = jj;
  }
}
int main() {
  calc();
  int a, n;
  cin >> a >> n;
  long long R;
  for (int i = a; i < a + n; ++i) R += r[i];
  cout << R << endl;
  return 0;
}
