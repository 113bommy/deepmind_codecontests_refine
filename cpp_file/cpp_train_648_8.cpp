#include <bits/stdc++.h>
using namespace std;
const int Rea = 1e5 + 3;
struct Rin {
  char c;
  inline char gc() {
    static char rea[Rea];
    static char *head, *tail;
    return head == tail && (tail = (head = rea) + fread(rea, 1, Rea, stdin),
                            head == tail)
               ? EOF
               : *head++;
  }
  inline Rin &operator>>(int &x) {
    bool tag = false;
    x = 0;
    for (c = gc(); c > '9' || c < '0'; c = gc())
      if (c == '-') {
        c = gc();
        tag = true;
        break;
      }
    for (; c >= '0' && c <= '9'; c = gc()) x = (x << 1) + (x << 3) + (c ^ '0');
    if (tag) x = -x;
    return *this;
  }
  inline Rin &operator>>(long long &x) {
    bool tag = false;
    x = 0;
    for (c = gc(); c > '9' || c < '0'; c = gc())
      if (c == '-') {
        c = gc();
        tag = true;
        break;
      }
    for (; c >= '0' && c <= '9'; c = gc()) x = (x << 1) + (x << 3) + (c ^ '0');
    if (tag) x = -x;
    return *this;
  }
} rin;
inline void jh(int &x, int &y) {
  if (x ^ y) x ^= y ^= x ^= y;
  return;
}
inline void jh(long long &x, long long &y) {
  if (x ^ y) x ^= y ^= x ^= y;
  return;
}
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
inline long long min(long long x, long long y) { return x < y ? x : y; }
inline long long max(long long x, long long y) { return x > y ? x : y; }
int n, m, q;
const int N = 2e5 + 3;
set<int> zjj[N];
set<int> gyq[N];
namespace tietietree {
struct node {
  bool ans;
  int zjj, gyq;
  inline void init() {
    zjj = m + 1;
    gyq = 0;
    ans = false;
    return;
  }
} nod[N << 2];
inline void up(int i) {
  nod[i].zjj = min(nod[(i << 1)].zjj, nod[((i << 1) | 1)].zjj);
  nod[i].gyq = max(nod[(i << 1)].gyq, nod[((i << 1) | 1)].gyq);
  nod[i].ans = nod[(i << 1)].ans || nod[((i << 1) | 1)].ans ||
               (nod[(i << 1)].zjj <= nod[((i << 1) | 1)].gyq);
  return;
}
inline void maketree(int l, int r, int i) {
  nod[i].init();
  if (l == r) return;
  int mid = l + r >> 1;
  maketree(l, mid, (i << 1));
  maketree(mid + 1, r, ((i << 1) | 1));
  return;
}
inline void updata(int l, int r, int i, int qx) {
  set<int>::iterator fd;
  if (l == r) {
    nod[i].zjj = zjj[l].empty() ? m + 1 : *zjj[l].begin();
    nod[i].gyq = gyq[l].empty() ? 0 : (fd = gyq[l].end(), *(--fd));
    nod[i].ans = (nod[i].zjj <= nod[i].gyq);
    return;
  }
  int mid = l + r >> 1;
  if (qx <= mid)
    updata(l, mid, (i << 1), qx);
  else
    updata(mid + 1, r, ((i << 1) | 1), qx);
  up(i);
  return;
}
}  // namespace tietietree
using namespace tietietree;
map<pair<int, int>, bool> qy;
void work() {
  int x, y, z;
  rin >> x >> y;
  if (qy.find(make_pair(x, y)) == qy.end()) {
    if (x & 1)
      zjj[x + 1 >> 1].insert(y + 1 >> 1);
    else
      gyq[x >> 1].insert(y >> 1);
  } else {
    if (x & 1)
      zjj[x + 1 >> 1].erase(y + 1 >> 1);
    else
      gyq[x >> 1].erase(y >> 1);
  }
  updata(1, n, 1, x + 1 >> 1);
  puts(nod[1].ans ? "NO" : "YES");
  return;
}
int main() {
  rin >> n >> m >> q;
  maketree(1, n, 1);
  for (; q; q--) work();
  return 0;
}
