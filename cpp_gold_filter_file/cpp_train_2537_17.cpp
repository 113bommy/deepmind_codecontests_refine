#include <bits/stdc++.h>
using namespace std;
int n, w, sum;
int t[100010];
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]), sum += t[i];
  if (sum < w || w < 0) return printf("No\n"), 0;
  if (n == 1) {
    if (w == t[1]) {
      printf("Yes\n");
      for (int i = 1; i <= 2 * t[1]; i++) printf("1 ");
      printf("\n");
    } else
      printf("No\n");
  } else if (w == 1) {
    int id = 0;
    for (int i = 1; i <= n; i++)
      if (t[i] == 1) {
        id = i;
        break;
      }
    if (!id)
      printf("No\n");
    else {
      printf("Yes\n");
      printf("%d ", id);
      for (int i = 1; i <= n; i++)
        if (i != id)
          for (; t[i]; t[i]--) printf("%d %d ", i, i);
      printf("%d\n", id);
    }
  } else {
    printf("Yes\n");
    t[1]--;
    t[2]--;
    for (int i = 1; i <= n; i++)
      for (; t[i] && w > 2; w--, t[i]--) printf("%d %d ", i, i);
    printf("1 ");
    for (int i = 2; i <= n; i++)
      for (; t[i]; t[i]--) printf("%d %d ", i, i);
    printf("1 2 ");
    for (; t[1]; t[1]--) printf("1 1 ");
    printf("2\n");
  }
}
