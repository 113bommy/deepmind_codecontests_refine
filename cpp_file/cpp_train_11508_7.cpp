#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  if (d > 2 * h || d == h && h == 1 && n > 2) {
    printf("-1\n");
    return 0;
  }
  if (n == 2) {
    printf("1 2\n");
    return 0;
  }
  for (int i = 2; i <= h + 1; i++) {
    printf("%d %d\n", i - 1, i);
  }
  int last = h + 2;
  int startx = 1;
  int flagD = 0;
  if (h == d) {
    flagD = 1;
    startx = 2;
  }
  if (!flagD) {
    printf("%d %d\n", 1, last++);
    for (int len = h + 2; len <= d; len++) {
      printf("%d %d\n", last - 1, last++);
    }
    for (int i = 0; i < n - d - 1; i++) {
      printf("%d %d\n", 1, last++);
    }
  } else {
    for (int i = 0; i < n - h - 1; i++) {
      printf("%d %d\n", 2, last++);
    }
  }
  return 0;
}
