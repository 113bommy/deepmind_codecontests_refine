#include <bits/stdc++.h>
using namespace std;
long long a, sum;
long long b[100009];
long long z[19];
int main() {
  cin >> a;
  for (int i = 0; i < a; i++) cin >> b[i];
  z[0] = 1;
  for (int i = 1; i < 20; i++) z[i] = z[i - 1] * 2;
  for (int i = 0; i < a - 1; i++) {
    for (int j = 18; j >= 0; j--)
      if (i + z[j] < a) {
        b[i + z[j]] += b[i];
        sum += b[i];
        b[i] = 0;
      }
    cout << sum;
  }
}
