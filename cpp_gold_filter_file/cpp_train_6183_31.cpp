#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double sol = 0.0;
  if (fmod((d / v), (g + r)) >= g) sol += (r - (fmod((d / v), (g + r)) - g));
  sol += l / v;
  printf("%.8lf", sol);
}
