#include <bits/stdc++.h>
using namespace std;
int a[110], n, w, s;
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s += a[i];
  }
  if (w < 1 || w > s) {
    puts("No");
    return 0;
  }
  if (n == 1) {
    if (w == a[1]) {
      puts("Yes");
      for (int i = 1; i <= 2 * a[1]; i++) printf("%d ", 1);
      puts("");
    } else {
      puts("No");
    }
    return 0;
  }
  if (w == 1) {
    int pos = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == 1) pos = i;
    if (a[pos] == 1) {
      puts("Yes");
      printf("%d ", pos);
      for (int i = 1; i <= n; i++) {
        if (i == pos) continue;
        for (int j = 1; j <= 2 * a[i]; j++) printf("%d ", j);
      }
      printf("%d\n", pos);
    } else {
      puts("No");
    }
  } else {
    puts("Yes");
    a[1]--;
    a[2]--;
    w -= 2;
    for (int i = 1; i <= n; i++) {
      while (a[i] > 0 && w > 0) {
        printf("%d %d ", i, i);
        w--;
        a[i]--;
      }
    }
    printf("1 ");
    for (int i = 2; i <= n; i++) {
      while (a[i] > 0) {
        printf("%d %d ", i, i);
        a[i]--;
      }
    }
    printf("1 2 ");
    while (a[1] > 0) {
      printf("1 1 ");
      a[1]--;
    }
    printf("2\n");
  }
  return 0;
}
