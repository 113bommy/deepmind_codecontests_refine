#include <bits/stdc++.h>
using namespace std;
char b[1000005], n[1000005];
long long c, lb, ln, bb;
int mode() {
  int ans = 0;
  for (int i = 0; i < lb; i++) {
    ans = ans * 10 + b[i] - '0';
    ans %= c;
  }
  return ans;
}
void s() {
  int cur = ln - 1;
  while (n[cur] == '0') {
    n[cur--] = '9';
  }
  n[cur] -= 1;
}
int m() {
  long long ans = 1;
  long long cur = bb, cu = 1;
  int j;
  for (int i = ln - 1; i >= 0; i--) {
    for (j = 1; j <= n[i] - '0'; j++) {
      cu = (cu * cur) % c;
    }
    ans = (ans * cu) % c;
    for (; j <= 10; j++) {
      cu = (cu * cur) % c;
    }
    cur = cu;
    cu = 1;
  }
  return ans;
}
int main() {
  scanf("%s%s%d", b, n, &c);
  lb = strlen(b);
  ln = strlen(n);
  bb = mode();
  s();
  long long ans = ((bb - 1 + c) * m()) % c;
  if (ans == 0) ans = c;
  printf("%d\n", ans);
}
