#include <bits/stdc++.h>
using namespace std;
long long i, j, t, m, n, k, res, l, a, r;
multiset<int> sv, sv1, sh, sh1;
char c;
int main() {
  cin >> n >> m >> k;
  sv.insert(0);
  sv.insert(n);
  sh.insert(0);
  sh.insert(m);
  sv1.insert(n);
  sh1.insert(m);
  for (i = 0; i < k; i++) {
    cin >> c >> a;
    if (c == 'H') {
      r = *sh.lower_bound(a + 1);
      l = *(--sh.lower_bound(a + 1));
      sh.insert(a);
      sh1.erase(sh1.lower_bound(r - l));
      sh1.insert(r - a);
      sh1.insert(a - l);
    }
    if (c == 'V') {
      r = *sv.lower_bound(a + 1);
      l = *(--sv.lower_bound(a + 1));
      sv.insert(a);
      sv1.erase(sv1.lower_bound(r - l));
      sv1.insert(r - a);
      sv1.insert(a - l);
    }
    cout << (*(--sh1.end())) * (*(--sv1.end())) << endl;
  }
  return 0;
}
