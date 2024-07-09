#include <bits/stdc++.h>
int main() {
  int n;
  double ave = 0;
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    double y;
    scanf("%*lf %lf", &y);
    ave += y;
  }
  ave /= n;
  ave += 5;
  printf("%.10lf\n", ave);
  return 0;
}
