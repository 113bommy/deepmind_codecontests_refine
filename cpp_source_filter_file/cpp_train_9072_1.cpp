#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", (n + 1) / 2);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0)
      printf("%d %d\n", (i + 1) / 2, i / 2 + 1);
    else {
      printf("%d %d\n", (i + 1) / 2, (i + 1) / 2);
    }
  }
}
