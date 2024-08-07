#include <bits/stdc++.h>
using namespace std;
int m;
int d[20], u[2000000], v[2000000];
void Move(int n, int a, int b, int rev, int flg) {
  if (n == 0) return;
  int top;
  for (top = n - 1; top >= 0 && d[top] == d[n - 1]; top--)
    ;
  if (!flg || n - top - 1 == 1 || rev) {
    Move(top + 1, a, 6 - a - b, 0, 0);
    for (int i = 0; i < n - top - 1; i++) u[m] = a, v[m++] = b;
    Move(top + 1, 6 - a - b, b, 0, 0);
  } else {
    if (top == -1) {
      for (int i = 0; i < n - 1; i++) u[m] = a, v[m++] = 6 - a - b;
      u[m] = a, v[m++] = b;
      for (int i = 0; i < n - 1; i++) u[m] = 6 - a - b, v[m++] = b;
      return;
    }
    Move(top + 1, a, b, 0, 0);
    for (int i = 0; i < n - top - 1; i++) u[m] = a, v[m++] = 6 - a - b;
    Move(top + 1, b, a, 0, 0);
    for (int i = 0; i < n - top - 1; i++) u[m] = 6 - a - b, v[m++] = b;
    Move(top + 1, a, b, 0, 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  reverse(d, d + n);
  m = 0;
  Move(n, 1, 3, 0, 1);
  printf("%d\n", m);
  for (int i = 0; i < m; i++) printf("%d %d\n", u[i], v[i]);
  return 0;
}
