#include <bits/stdc++.h>
using namespace std;
struct data {
  int id, a;
  data() {}
  data(int id, int a) : id(id), a(a) {}
  bool operator<(const data &r) const { return a < r.a; }
} da[100010];
int n, h;
int main() {
  scanf("%d%d", &n, &h);
  for (int i = 0; i < n; i++) scanf("%d", &da[i].a), da[i].id = i;
  if (n == 2) {
    printf("0\n");
    for (int i = 0; i < n; i++) printf("1 ");
    puts("");
    return 0;
  }
  sort(da, da + n);
  int f1 = da[n - 1].a + da[n - 2].a - da[0].a - da[1].a;
  int f2 = max(da[n - 1].a + da[0].a + h, da[n - 1].a + da[n - 2].a) -
           min(da[0].a + da[1].a + h, da[1].a + da[2].a);
  if (f1 <= f2) {
    printf("%d\n", f1);
    for (int i = 0; i < n; i++) printf("1 ");
    puts("");
  } else {
    printf("%d\n", f2);
    for (int i = 0; i < n; i++)
      if (da[0].id == i)
        printf("1 ");
      else
        printf("2 ");
    puts("");
  }
  return 0;
}
