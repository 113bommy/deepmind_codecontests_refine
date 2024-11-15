#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005], b[100005], c[100005], p[100005], id[100005];
multiset<int> s;
void get() {
  s.clear();
  for (int i = 1; i <= n; ++i) {
    s.insert(c[i]);
  }
  for (int i = 1; i <= n; ++i) {
    p[id[i]] |= (*s.begin()) >= c[i - 1];
    s.insert(c[n + i]);
    multiset<int>::iterator it = s.find(c[i]);
    s.erase(it);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    c[n + i] = c[i] = a[i] - b[i] + c[i - 1];
    id[i] = i;
  }
  get();
  for (int i = n; i >= 1; --i) {
    c[2 * n - i + 1] = c[n - i + 1] =
        a[i] - (i - 1 > 0 ? b[i - 1] : b[n]) + c[n - i];
    id[n - i + 1] = i;
  }
  get();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (p[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    if (p[i] == 0) continue;
    printf("%d ", i);
  }
  puts("");
  return 0;
}
