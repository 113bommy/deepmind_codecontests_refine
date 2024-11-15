#include <bits/stdc++.h>
using namespace std;
int k, m, ini;
set<int> s;
set<int>::iterator it;
void gen(int cur, int num) {
  if (s.size() > m) return;
  if (num == 0) {
    int dif = abs(cur - k);
    if (dif < 10000) {
      s.insert(ini * 10000 + dif);
      s.insert(dif * 10000 + ini);
    }
    return;
  }
  gen(cur + (num % 10), num / 10);
  gen(cur - (num % 10), num / 10);
  gen(cur * (num % 10), num / 10);
}
int main() {
  int i;
  scanf("%d %d", &k, &m);
  for (i = 0; i < 9999; i++) {
    ini = i;
    gen(ini % 10, ini / 10);
  }
  for (i = 0, it = s.begin(); i < m; i++, it++) printf("%08d\n", *it);
  return 0;
}
