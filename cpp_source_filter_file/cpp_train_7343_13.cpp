#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[105];
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (a[i] > a[i + 1]) {
          printf("%d %d\n", i + 1, i + 2);
          swap(a[i], a[i + 1]);
        }
      }
    }
  }
  return 0;
}
