#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  int tmp[4];
  tmp[0] = a + b;
  tmp[1] = b + d;
  tmp[2] = c + d;
  tmp[3] = c + a;
  sort(tmp, tmp + 4);
  int can = n - (tmp[3] - tmp[0]);
  if (can < 0) can = 0;
  cout << n * can << endl;
  return 0;
}
