#include <bits/stdc++.h>
using namespace std;
int a[200];
int b[200];
int n, m, num, s, t;
char st[200];
int Abs(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
bool Work() {
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 30; ++j) {
      if (a[i] & 1) ++b[j];
      a[i] /= 2;
    }
  }
  for (int i = 0; i < 30; ++i)
    if (b[i] % (num + 1) != 0) return true;
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &num);
  bool g1 = false, g2 = false;
  bool empty = true;
  bool can1 = false, can2 = false;
  for (int i = 0; i < n; ++i) {
    scanf("%s", st);
    int t1 = 0, t2 = 0;
    for (int j = 0; j < m; ++j) {
      if (st[j] == 'R') {
        s = j;
        ++t1;
      }
      if (st[j] == 'G') {
        t = j;
        ++t2;
      }
    }
    if (t2 && t1 + t2 < m) can2 = true;
    if (t1 && t1 + t2 < m) can1 = true;
    if (t1 && !t2) g1 = true;
    if (t2 && !t1) g2 = true;
    if (t1 && t2) a[i] = Abs(s - t) - 1;
    if (t1 || t2) empty = false;
  }
  if (empty) {
    printf("Second\n");
    return 0;
  }
  if (!can2) {
    printf("Second\n");
    return 0;
  }
  if (!can1) {
    printf("First\n");
    return 0;
  }
  if (m == 1) {
    printf("Second\n");
    return 0;
  }
  if (g1 && g2)
    printf("Draw\n");
  else if (g1 && !g2)
    printf("Second\n");
  else if (!g1 && g2)
    printf("First\n");
  else {
    if (Work())
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}
