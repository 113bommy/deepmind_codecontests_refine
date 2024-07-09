#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, p, j;
  long long k, s = 0, r, num;
  cin >> k;
  for (i = 1; i; i++) {
    if (s + i * 9 * pow(10, i - 1) >= k) {
      break;
    }
    s += i * 9 * pow(10, i - 1);
  }
  s = k - s;
  r = (s - 1) / i;
  p = (s - 1) % i;
  num = 1 * pow(10, i - 1);
  num += r;
  j = i - 1 - p;
  long long int a = (num % (long long int)(pow(10, j + 1)));
  long long int b = (long long int)pow(10, j);
  cout << a / b;
}
