#include <bits/stdc++.h>
int n, t, b = 1 << 30, i, j, A;
char a[1234];
int main() {
  scanf("%d %s", &n, a);
  for (; i < n;) a[i + n] = a[i], t += a[i++] == 'T';
  for (; --i >= 0;) {
    A = 0;
    for (; j < t;) A += a[i + j++] != 'T';
    b = b < A ? b : A;
  }
  printf("%d", b);
  return 0;
}
