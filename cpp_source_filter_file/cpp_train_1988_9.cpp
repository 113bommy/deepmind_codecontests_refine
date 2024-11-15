#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 4 != 0) {
    cout << "! -1\n";
    return 0;
  }
  cout << "? 1" << endl;
  int a;
  cin >> a;
  cout << "? " << 1 + n / 2 << endl;
  int b;
  cin >> b;
  if (a == b) {
    cout << "! 1" << endl;
    return 0;
  }
  int lo = 2, hi = n / 2;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    int c, d;
    cout << "? " << mid << endl;
    cin >> c;
    cout << "? " << mid + n / 2 << endl;
    cin >> d;
    if (d == c) {
      cout << "! " << c << endl;
      return 0;
    }
    if ((long long)(d - c) * (b - a) > 0) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  cout << "? " << lo << endl;
  int x;
  cin >> x;
  cout << "? " << lo + n / 2 << endl;
  int y;
  cin >> y;
  if (x == y) {
    cout << "! " << lo << endl;
  } else {
    cout << "! -1" << endl;
  }
}
