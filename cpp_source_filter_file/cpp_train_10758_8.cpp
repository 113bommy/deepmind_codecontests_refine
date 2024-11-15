#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long LINF = 2e16;
const int magic = 348;
const int MOD = 998244353;
const double eps = 1e-10;
const double pi = acos(-1);
inline int getint() {
  bool f;
  char ch;
  int res;
  while (!isdigit(ch = getchar()) && ch != '-') {
  }
  if (ch == '-')
    f = false, res = 0;
  else
    f = true, res = ch - '0';
  while (isdigit(ch = getchar())) res = res * 10 + ch - '0';
  return f ? res : -res;
}
const int MAXN = 4e5;
int d;
char s[MAXN + 48];
int len;
char ans[MAXN + 48];
unsigned long long pw[MAXN + 48];
struct BIT {
  unsigned long long c[MAXN + 48];
  inline void init() {
    for (register int i = 1; i <= len; i++) c[i] = 0;
  }
  inline void update(int first, unsigned long long delta) {
    while (first <= len) c[first] += delta, first += first & (-first);
  }
  inline unsigned long long query(int first) {
    unsigned long long res = 0;
    while (first) res += c[first], first -= first & (-first);
    return res;
  }
  inline unsigned long long calc(int left, int right) {
    return query(right) - query(left - 1);
  }
} L, R;
inline void updatech(int pos, char ch, int fl) {
  L.update(pos, pw[len - pos] * ch * fl);
  R.update(pos, pw[pos - 1] * ch * fl);
}
inline bool ispal(int left, int right) {
  return L.calc(left, right) * pw[left - 1] ==
         R.calc(left, right) * pw[len - right];
}
inline bool check_bad(int pos) {
  if (pos >= d && ispal(pos - d + 1, pos)) return true;
  if (pos >= d + 1 && ispal(pos - d, pos)) return true;
  return false;
}
inline bool dfs(int pos, bool same) {
  if (pos == len + 1) return (!same) ? true : false;
  for (char ch = (same ? s[pos] : 'a'); ch <= 'z'; ch++) {
    updatech(pos, ch, 1);
    ans[pos] = ch;
    if (check_bad(pos)) {
      updatech(pos, ch, -1);
      continue;
    }
    bool ns = same;
    if (ch != s[pos]) ns = false;
    bool res = dfs(pos + 1, ns);
    if (res) return true;
    updatech(pos, ch, -1);
  }
  return false;
}
int main() {
  d = getint();
  scanf("%s", s + 1);
  len = strlen(s + 1);
  pw[0] = 1;
  for (register int i = 1; i <= len; i++) pw[i] = pw[i - 1] * MOD;
  L.init();
  R.init();
  bool res = dfs(1, 1);
  if (!res)
    puts("Impossible");
  else
    printf("%s", ans + 1);
  return 0;
}
