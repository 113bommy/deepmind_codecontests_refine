#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int m, n, s, bug[N], stu[N], fee[N], bugs[N], stus[N], ans[N];
inline bool bugcmp(const int a, const int b) { return bug[a] > bug[b]; }
inline bool stucmp(const int a, const int b) { return stu[a] > stu[b]; }
inline bool feecmp(const int a, const int b) { return fee[a] > fee[b]; }
int ava[N];
inline bool chk(int t) {
  int sy = 0, *c = stus, mo = 0, ac = 0;
  for (int *i = bugs; i < bugs + m; i++) {
    for (; stu[*c] >= bug[*i] && c < stus + n; c++)
      ava[ac++] = *c, push_heap(ava, ava + ac, feecmp);
    if (sy) {
      ans[*i] = ans[*(i - 1)], sy--;
    } else {
      if (ac == 0) return false;
      sy = t - 1, ans[*i] = ava[0], mo += fee[ava[0]],
      pop_heap(ava, ava + ac--, feecmp);
      if (mo > s) return false;
    }
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < m; i++) scanf("%d", bug + i), bugs[i] = i;
  for (int i = 0; i < n; i++) scanf("%d", stu + i), stus[i] = i;
  for (int i = 0; i < n; i++) scanf("%d", fee + i);
  sort(bugs, bugs + m, bugcmp);
  sort(stus, stus + n, stucmp);
  int ta = 0, tb = n;
  while (ta + 1 < tb) {
    int tm = (ta + tb) / 2;
    if (chk(tm))
      tb = tm;
    else
      ta = tm;
  }
  if (!chk(tb)) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for (int i = 0; i < m; i++) printf("%d ", ans[i] + 1);
  return 0;
}
