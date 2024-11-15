#include <bits/stdc++.h>
using namespace std;
namespace io {
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1,
                                           __c, qu[55];
int __f, qr, _eof;
inline void flush() { fwrite(obuf, 1, oS - obuf, stdout), oS = obuf; }
inline void gc(char &x) {
  x = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                   (iS == iT ? EOF : *iS++))
                : *iS++);
}
inline void pc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
inline void pstr(const char *s) {
  int __len = strlen(s);
  for (__f = 0; __f < __len; ++__f) pc(s[__f]);
}
inline void gstr(char *s) {
  for (__c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++);
       __c < 32 || __c > 126 || __c == ' ';)
    __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                    : *iS++);
  for (; __c > 31 && __c < 127 && __c != ' ';
       ++s, __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++))
    *s = __c;
  *s = 0;
}
template <class I>
inline bool gi(I &x) {
  _eof = 0;
  for (__f = 1,
      __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                        (iS == iT ? EOF : *iS++))
                      : *iS++);
       (__c < '0' || __c > '9') && !_eof;
       __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++)) {
    if (__c == '-') __f = -1;
    _eof |= __c == EOF;
  }
  for (x = 0; __c <= '9' && __c >= '0' && !_eof;
       __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++))
    x = x * 10 + (__c & 15), _eof |= __c == EOF;
  x *= __f;
  return !_eof;
}
template <class I>
inline void print(I x) {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) pc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::gc;
using io::gi;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1000000009;
namespace AhoCorasick {
const int nodecount = 100005;
bool vist[nodecount];
int ans;
int pt[nodecount][4], cnc;
struct {
  int len, fail;
} aux[nodecount];
int mknode() {
  int v = cnc++;
  vist[v] = false;
  for (int i = (0); i < (4); i++) pt[v][i] = -1;
  aux[v] = {0, 0};
  return v;
}
void init() {
  cnc = 0;
  ans = 0;
  mknode();
}
void insert(string s) {
  int at = 0;
  for (char &c : s) {
    if (pt[at][c - 'A'] == -1) pt[at][c - 'A'] = mknode();
    at = pt[at][c - 'A'];
  }
  aux[at].len = s.length();
}
void automatize() {
  queue<int> bfs;
  for (int i = (0); i < (4); i++) {
    aux[pt[0][i]].fail = 0;
    if (pt[0][i] != -1)
      bfs.push(pt[0][i]);
    else
      pt[0][i] = 0;
  }
  while (!bfs.empty()) {
    int at = bfs.front();
    bfs.pop();
    for (int ch = (0); ch < (4); ch++) {
      int &nex = pt[at][ch];
      if (nex == -1) {
        nex = pt[aux[at].fail][ch];
        continue;
      }
      bfs.push(nex);
      aux[nex].fail = pt[aux[at].fail][ch];
      aux[nex].len = max(aux[nex].len, aux[aux[nex].fail].len);
    }
  }
}
}  // namespace AhoCorasick
using namespace AhoCorasick;
int _dp[1005][105][15];
int n;
int dp(int t, int i, int s) {
  if (s > 10) return 0;
  if (t == n) return s == 0;
  if (_dp[t][i][s] != -1) return _dp[t][i][s];
  int re = 0;
  for (int c = (0); c < (4); c++) {
    re += dp(t + 1, pt[i][c], aux[pt[i][c]].len > s ? 0 : (s + 1));
    if (re >= MOD) re -= MOD;
  }
  return _dp[t][i][s] = re;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> n >> m;
  int k3 = m;
  init();
  while (m--) {
    string s;
    cin >> s;
    for (char &c : s) {
      if (c == 'C') c = 'B';
      if (c == 'G') c = 'C';
      if (c == 'T') c = 'D';
    }
    insert(s);
  }
  automatize();
  memset(_dp, -1, sizeof _dp);
  cout << dp(0, 0, 0) << endl;
}
