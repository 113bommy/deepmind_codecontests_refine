#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double time = (double)d / v, per = g + r;
  double k = fmod(time, per);
  time += (double)(l - d) / v;
  if (k >= g) time += per - k;
  printf("%0.6lf\n", time);
}
