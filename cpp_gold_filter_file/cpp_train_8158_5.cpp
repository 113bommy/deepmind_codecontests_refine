#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-8;
const double PI = acos(-1);
int a[] = {
    0,   0,   0,   0,   0,   0,   0,   255, 0,   255, 0,   255, 0,   255, 0,
    0,   0,   0,   0,   255, 255, 0,   255, 0,   255, 255, 0,   0,   0,   0,
    0,   0,   0,   0,   255, 255, 255, 255, 255, 0,   255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 0,   255, 0,   255, 0,   0,   255, 255, 255, 0,
    255, 255, 255, 255, 255, 0,   0,   255, 0,   0,   0,   255, 0,   255, 255,
    0,   0,   255, 0,   0,   255, 255, 255, 255, 255, 0,   0,   255, 0,   255,
    255, 255, 0,   255, 0,   0,   0,   255, 0,   0,   255, 0,   0,   0,   255,
    0,   255, 0,   255, 0,   0,   255, 255, 0,   255, 255, 0,   0,   0,   0,
    0,   255, 0,   255, 255, 0,   255, 0,   0,   0,   255, 0,   0,   255, 0,
    0,   0,   255, 0,   255, 0,   0,   255, 255, 255, 0,   0,   255, 255, 255,
    0,   0,   0,   0,   255, 255, 0,   255, 0,   255, 0,   0,   0,   255, 0,
    0,   255, 255, 255, 255, 255, 0,   255, 0,   255, 0,   255, 0,   255, 0,
    255, 0,   0,   255, 0,   255, 255, 255, 255, 0,   255, 0,   255, 255, 255,
    255, 255, 0,   0,   0,   0,   0,   0,   0,   0,   255, 0,   255, 0,   255,
    0,   255, 0,   255, 0,   255, 0,   255, 0,   255, 0,   255, 0,   255, 0,
    0,   0,   0,   0,   0,   0,   255, 255, 255, 255, 255, 255, 255, 255, 0,
    0,   0,   0,   0,   255, 0,   0,   0,   0,   0,   255, 255, 0,   0,   0,
    0,   255, 255, 255, 255, 255, 255, 255, 255, 0,   255, 255, 255, 0,   255,
    0,   0,   0,   0,   255, 255, 0,   255, 255, 255, 255, 0,   255, 0,   0,
    0,   0,   255, 0,   0,   0,   0,   0,   0,   255, 255, 0,   0,   0,   255,
    0,   0,   0,   255, 255, 0,   0,   0,   0,   0,   0,   0,   0,   255, 255,
    0,   255, 255, 255, 255, 0,   255, 255, 255, 0,   255, 0,   0,   255, 255,
    255, 0,   0,   0,   255, 255, 0,   0,   0,   255, 0,   255, 255, 255, 255,
    0,   255, 0,   255, 255, 255, 0,   0,   0,   255, 0,   255, 255, 255, 0,
    255, 0,   255, 255, 0,   0,   0,   0,   255, 255, 255, 255, 0,   0,   255,
    255, 255, 0,   0,   0,   0,   0,   0,   255, 0,   255, 0,   0,   255, 255,
    255, 255, 255, 255, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   255, 255, 255, 0,   0,   0,   255, 255, 0,
    255, 255, 0,   255, 0,   0,   255, 255, 255, 0,   0,   0,   255, 255, 255,
    255, 0,   255, 0,   0,   0,   255, 0,   255, 255, 0,   0,   255, 0,   255,
    255, 0,   0,   255, 0,   255, 0,   255, 255, 0,   255, 255, 0,   255, 0,
    255, 0,   255, 0,   255, 255, 255, 0,   255, 0,   0,   255, 255, 0,   255,
    0,   0,   255, 0,   255, 0,   255, 0,   255, 255, 255, 255, 255, 0,   255,
    0,   255, 0,   0,   255, 255, 255, 255, 255, 0,   255, 0,   255, 0,   255,
    255, 255, 0,   0,   0,   0,   0,   255, 0,   255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 0,   255, 0,   255, 255, 255, 0,   0,
    255, 255, 0,   0,   255, 0,   255, 255, 255, 0,   0,   0,   0,   255, 0,
    255, 0,   0,   255, 0,   255, 0,   255, 0,   255, 255, 0,   255, 255, 0,
    0,   0,   0,   0,   255, 0,   0,   0,   0,   255, 255, 255, 0,   255, 0,
    255, 0,   255, 255, 255, 0,   0,   0,   255, 0,   255, 0,   0,   255, 0,
    0,   0,   0,   0,   0,   0,   255, 255, 255, 0,   255, 255, 0,   255, 255,
    255, 255, 0,   0,   0,   255, 255, 255, 0,   255, 255, 255, 255, 255, 255,
    255, 0,   255, 255, 0,   0,   255, 255, 255, 0,   255, 255, 0,   0,   255,
    255, 255, 255, 255, 0,   0,   255, 0,   255, 255, 255, 255, 255, 0,   255,
    255, 255, 0,   0,   255, 0,   0,   255, 0,   255, 255, 0,   0,   255, 0,
    0,   0,   255, 255, 0,   255, 255, 0,   255, 255, 0,   0,   255, 0,   0,
    255, 255, 255, 255, 0,   0,   0,   255, 0,   255, 0,   0,   255, 0,   255,
    255, 255, 0,   255, 255, 255, 0,   0,   0,   0,   255, 0,   255, 0,   255,
    0,   255, 255, 0,   0,   255, 0,   0,   0,   255, 0,   255, 0,   255, 255,
    0,   0,   255, 255, 0,   0,   0,   255, 0,   255, 255, 0,   0,   255, 0,
    255, 255, 255, 255, 255, 0,   0,   0,   255, 0,   0,   255, 255, 255, 0,
    255, 0,   255, 255, 0,   255, 0,   255, 0,   0,   0,   0,   255, 255, 255,
    0,   255, 0,   0,   0,   0,   0,   0,   0,   255, 255, 255, 255, 255, 0,
    255, 255, 255, 0,   0,   0,   255, 0,   0,   0,   255, 255, 255, 255, 0,
    255, 0,   255, 0,   0,   255, 0,   0,   0,   0,   0,   255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 0,   0,   0,   255, 255, 0,   255,
    0,   0,   255, 0,   255, 255, 255, 0,   255, 0,   255, 255, 255, 0,   255,
    0,   0,   255, 0,   0,   0,   0,   0,   0,   0,   255, 0,   255, 255, 255,
    0,   255, 0,   0,   0,   0,   255, 255, 255, 0,   0,   255, 0,   255, 0,
    255, 0,   0,   255, 0,   255, 0,   255, 255, 255, 255, 255, 0,   255, 255,
    0,   0,   0,   255, 0,   255, 0,   255, 0,   0,   0,   0,   0,   255, 255,
    0,   255, 255, 255, 0,   0,   255, 0,   0,   0,   255, 0,   0,   0,   255,
    0,   255, 0,   255, 255, 0,   255, 0,   255, 255, 255, 255, 0,   255, 0,
    255, 255, 255, 0,   0,   0,   0,   0,   0,   255, 255, 255, 0,   255, 0,
    0,   0,   255, 0,   255, 255, 255, 0,   0,   255, 0,   255, 255, 0,   255,
    255, 0,   255, 0,   0,   0,   0,   0,   0,   255, 0,   0,   255, 0,   255,
    0,   255, 0,   0,   0,   255, 0,   255, 255, 0,   255, 255, 255, 0,   0,
    255, 0,   0,   0,   0,   255, 0,   0,   255, 0,   255, 0,   0,   0,   255,
    255, 255, 255, 0,   255, 255, 255, 255, 255, 0,   255, 255, 0,   0,   255,
    255, 0,   0,   255, 255, 0,   0,   0,   0,   0,   255, 255, 0,   0,   0,
    0,   255, 255, 255, 255, 255, 0,   0,   0,   0,   0,   0,   0,   255, 0,
    0,   255, 0,   255, 255, 255, 0,   255, 0,   255, 255, 0,   0,   255, 0,
    0,   0,   255, 255, 0,   255, 255, 255, 0};
int main() {
  int x, y;
  while (cin >> y >> x) {
    cout << (a[y * 33 + x] == 0) << endl;
  }
}
