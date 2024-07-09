#include <bits/stdc++.h>
using namespace std;
int main() {
  long double P = 3.1415926535897932384;
  long double x1, y1, r1, x2, y2, r2, diff, a1, a2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  if (r1 >= r2) {
    diff = r1 - r2;
  } else {
    diff = r2 - r1;
  }
  long double theta, theta1, theta2, d, area;
  d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  cout.precision(9);
  if (d >= r1 + r2) {
    area = 0;
    cout << area;
  } else if (d <= diff) {
    if (r1 >= r2) {
      area = M_PI * r2 * r2;
      cout << area;
    } else {
      area = M_PI * r1 * r1;
      cout << area;
    }
  } else {
    theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d)) * 2;
    theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d)) * 2;
    a1 = (long double)0.5 * theta2 * r2 * r2 - 0.5 * r2 * r2 * sin(theta2);
    a2 = (long double)0.5 * theta1 * r1 * r1 - 0.5 * r1 * r1 * sin(theta1);
    cout << a1 + a2;
  }
  return 0;
}
