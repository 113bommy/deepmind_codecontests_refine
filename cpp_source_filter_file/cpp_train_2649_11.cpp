#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, a, b, x[100001], i;
  cin >> a >> b;
  for (i = 0; i < a; ++i) {
    cin >> x[i];
  }
  sort(x, x + a);
  for (i = 0; i < a; ++i) {
    sum += x[i] * b;
    b -= 1;
    if (b <= 0) b++;
  }
  cout << sum;
}
