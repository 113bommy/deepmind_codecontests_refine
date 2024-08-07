#include <bits/stdc++.h>
using namespace std;
pair<int, int> l[200010], r[200010];
int a[200010], c[200010];
void work(int n) {
  if (a[1] > 1) {
    puts("-1");
    return;
  }
  l[1] = r[1] = make_pair(1, 1);
  for (int i = 2; i <= n; i++) {
    l[i] = l[i - 1].second == 2
               ? make_pair(l[i - 1].first + 1, 1)
               : make_pair(l[i - 1].first, l[i - 1].second + 1);
    r[i] = r[i - 1].second == 5
               ? make_pair(r[i - 1].first + 1, 1)
               : make_pair(r[i - 1].first, r[i - 1].second + 1);
    if (a[i] != 0) {
      if (l[i].first < a[i] || r[i].first > a[i]) {
        puts("-1");
        return;
      }
      l[i] = min(l[i], make_pair(a[i], 5));
      r[i] = max(r[i], make_pair(a[i], 1));
    }
  }
  pair<int, int> ans = l[n];
  if (ans.second == 1) ans = make_pair(l[n].first - 1, 5);
  if (ans < r[n]) {
    puts("-1");
    return;
  }
  printf("%d\n", ans.first);
  a[n] = ans.first;
  c[a[n]] = 1;
  for (int i = n - 1; i; i--) {
    a[i] = min(a[i + 1], l[i].first);
    if (c[a[i]] == 5) a[i]--;
    c[a[i]]++;
  }
  for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? 10 : ' ');
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  work(n);
  return 0;
}
