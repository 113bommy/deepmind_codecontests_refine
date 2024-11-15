#include <bits/stdc++.h>
using namespace std;
const int N = 1001013, pn = 19937;
int hasA0, hasB0, ai, aj, n, hasd, can[N], d1[N];
char A[N], B[N];
void upd(int i, int j) {
  if (ai < i || ai == i && aj > j) {
    ai = i;
    aj = j;
  }
}
set<pair<int, int> > T;
set<pair<int, int> >::iterator it;
char ch;
void read_(char *s) {
  int t = 0;
  for (ch = getchar(); ch != '\n'; ch = getchar()) s[t++] = ch;
  s[t] = '\0';
}
int hasht(char *s, int i, int j, int o) {
  int ret = 0;
  for (; i != j; i += o) ret = ret * pn + s[i];
  return ret;
}
int show(set<pair<int, int> >::iterator it) { return it->first; }
int main() {
  read_(A);
  read_(B);
  n = strlen(A);
  if (n != strlen(B)) {
    printf("-1 -1\n");
    return 0;
  }
  d1[0] = 1;
  for (int i = 1; i <= n; ++i) d1[i] = d1[i - 1] * pn;
  for (int i = 0; i < n; ++i) {
    hasA0 = A[i] + hasA0 * pn;
    hasB0 = B[n - i - 1] + hasB0 * pn;
    can[i] = hasA0 == hasB0;
  }
  aj = ai = -1;
  hasd = hasB0 = hasA0 = 0;
  if (can[n - 1]) {
    printf("%d %d\n", n - 2, n - 1);
    return 0;
  }
  for (int i = n - 1; i; --i) {
    hasd += A[i] * d1[n - i - 1];
    hasA0 = A[i] + hasA0 * pn;
    hasB0 = B[n - i - 1] + hasB0 * pn;
    if (can[i - 1]) {
      it = T.lower_bound(pair<int, int>(hasB0 - hasd, 0));
      if (it != T.end() && it->first == hasB0 - hasd) upd(i - 1, it->second);
    }
    T.insert(pair<int, int>(hasA0 - hasd, i));
  }
  printf("%d %d\n", ai, aj);
  return 0;
}
