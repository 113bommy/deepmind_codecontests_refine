#include <bits/stdc++.h>
using namespace std;
int n, i;
int a[200001];
bool p1, p2;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  p1 = true;
  p2 = true;
  for (i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) p1 = false;
    if (a[i] > a[i - 1]) p2 = false;
    if ((!p1) && (!p2)) {
      printf("3\n");
      printf("%d %d %d", i - 2, i - 1, i);
      return 0;
    }
  }
  printf("0");
  return 0;
}
