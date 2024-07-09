#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  long long int i, k = 0, j = 0, c = 1, nu = 0, q = 0, alp[10] = {0};
  for (i = 0; i < a.length(); i++) {
    if (a[i] == '?') {
      q++;
    }
    if (a[i] >= 'A' && a[i] <= 'J') {
      alp[int(a[i]) - 'A']++;
    }
  }
  for (i = 0; i < 10; i++) {
    if (alp[i] > 0) {
      j++;
    }
  }
  if (a[0] >= 'A' && a[0] <= 'J') {
    c = 9;
    k = 1;
    j--;
  } else if (a[0] == '?') {
    c = 9;
    q--;
  }
  for (i = 0; i < q; i++) {
    c = c * 10;
  }
  for (i = 0; i < j; i++) {
    c = c * (10 - i - k);
  }
  cout << c;
  return 0;
}
