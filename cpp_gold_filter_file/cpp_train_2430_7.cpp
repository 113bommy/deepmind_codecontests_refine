#include <bits/stdc++.h>
using namespace std;
char A[1000005], B[1000005];
long long c, b;
int at, bt;
int main() {
  ios::sync_with_stdio(false);
  scanf("%s", A + 1);
  at = strlen(A + 1);
  scanf("%s", B + 1);
  bt = strlen(B + 1);
  bool tw = false;
  for (int i = bt; i >= 1; i--) {
    B[i]--;
    tw = false;
    if (B[i] < '0') {
      tw = true;
      B[i] = '9';
    }
    if (tw == false) break;
  }
  scanf("%I64d", &c);
  for (int i = 1; i <= at; i++) b = (b * 10LL + 1LL * (A[i] - '0')) % c;
  long long cast = 1;
  for (int i = 1; i <= bt; i++) {
    long long broad = cast;
    for (int j = 0; j < 9; j++) cast = cast * broad % c;
    for (int k = 0; k < int(B[i] - '0'); k++) cast = cast * b % c;
  }
  long long ti = cast * (b - 1LL) % c;
  if (ti <= 0) ti = ti + c;
  printf("%I64d\n", ti);
  return 0;
}
