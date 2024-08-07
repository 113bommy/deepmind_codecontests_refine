#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5);
const int mod = int(1e9) + 7;
int b, d, x;
int main() {
  scanf("%d%d", &b, &d);
  int pos = -1, dx = d, ax, bx;
  bool ok = 1;
  x = b;
  for (int i = 2; i <= x; i++) {
    if (x % i == 0) {
      ax = 0;
      bx = 0;
      while (x % i == 0) {
        x /= i;
        ax++;
      }
      while (dx % i == 0) {
        dx /= i;
        bx++;
      }
      pos = max((ax + bx - 1) / ax, pos);
    }
  }
  if (ok) {
    if (dx == 1) {
      printf("2-type\n%d", pos);
      return 0;
    }
  }
  if ((b - 1) % d == 0) {
    puts("3-type");
    return 0;
  }
  if ((b + 1) % d == 0) {
    puts("11-type");
    return 0;
  }
  ok = 1;
  for (int i = 2; i <= d; i++) {
    if (d % i == 0) {
      dx = 1;
      while (d % i == 0) {
        d /= i;
        dx *= i;
      }
      if (b % i == 0) continue;
      if ((b + 1) % dx == 0) continue;
      if ((b - 1) % dx == 0) continue;
      puts("7-type");
      return 0;
    }
  }
  puts("6-type");
  return 0;
}
