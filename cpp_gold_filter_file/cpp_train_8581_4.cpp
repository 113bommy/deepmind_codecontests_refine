#include <bits/stdc++.h>
using namespace std;
int a[5];
int l[5] = {0, 4, 1, 2, 3};
int r[5] = {0, 2, 3, 4, 1};
int main() {
  for (int i = 1; i <= 4; i++) cin >> a[i];
  for (; a[1] != 1 || a[2] != 1 || a[3] != 1 || a[4] != 1;) {
    int x = rand() % 4 + 1;
    if (a[x] == 1 && a[r[x]] == 1) continue;
    if (a[x] % 2 == 0 && a[r[x]] % 2 == 0)
      printf("/%d\n", x), a[x] >>= 1, a[r[x]] >>= 1;
    else if (a[x] % 2 == 1 && a[r[x]] % 2 == 1)
      printf("+%d\n", x), a[x]++, a[r[x]]++;
    else if (a[x] % 2 == 1)
      printf("+%d\n", l[x]), a[l[x]]++, a[x]++;
    else
      printf("+%d\n", r[x]), a[r[x]]++, a[r[r[x]]]++;
  }
  return 0;
}
