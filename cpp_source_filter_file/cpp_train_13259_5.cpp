#include <bits/stdc++.h>
using namespace std;
int sg(long long x) {
  if (x <= 3) return 0;
  if (x <= 15) return 1;
  if (x <= 81) return 2;
  if (x <= 6723) return 0;
  if (x <= 50625) return 3;
  if (x <= 2562991876) return 1;
  return 2;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    long long ans = 0;
    while (n--) {
      long long t;
      cin >> t;
      ans ^= sg(t);
    }
    if (ans)
      cout << "Furlo" << endl;
    else
      cout << "Rublo" << endl;
  }
}
