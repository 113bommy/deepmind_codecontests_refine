#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, q, t = 1;
int lson[N * 2], rson[N * 2], vm[2][N * 2], ovl[N * 2];
set<pair<int, int> > sm[2][N * 2];
map<int, int> op[N * 2];
void build(int pos, int x, int y) {
  vm[1][pos] = m + 1;
  if (x == y) return;
  int mid = (x + y) >> 1;
  lson[pos] = ++t;
  rson[pos] = ++t;
  build(lson[pos], x, mid);
  build(rson[pos], mid + 1, y);
}
inline int MAX(int knd, int pos) {
  if (sm[knd][pos].empty()) return 0;
  set<pair<int, int> >::iterator it = sm[knd][pos].end();
  it--;
  return it->first;
}
inline int MIN(int knd, int pos) {
  if (sm[knd][pos].empty()) return m + 1;
  return sm[knd][pos].begin()->first;
}
void modify(int knd, int pos, int l, int r, int x, int y, pair<int, int> v) {
  if (l >= x && r <= y) {
    if (knd == 0) {
      if (sm[knd][pos].find(v) != sm[knd][pos].end()) {
        sm[knd][pos].erase(v);
        vm[knd][pos] = MAX(knd, pos);
      } else {
        sm[knd][pos].insert(v);
        vm[knd][pos] = MAX(knd, pos);
      }
    } else {
      if (sm[knd][pos].find(v) != sm[knd][pos].end()) {
        sm[knd][pos].erase(v);
        vm[knd][pos] = MIN(knd, pos);
      } else {
        sm[knd][pos].insert(v);
        vm[knd][pos] = MIN(knd, pos);
      }
    }
    if (lson[pos]) {
      vm[0][pos] = max(vm[0][pos], vm[0][lson[pos]]);
      vm[1][pos] = min(vm[1][pos], vm[1][lson[pos]]);
    }
    if (rson[pos]) {
      vm[0][pos] = max(vm[0][pos], vm[0][rson[pos]]);
      vm[1][pos] = min(vm[1][pos], vm[1][rson[pos]]);
    }
    ovl[pos] = (MIN(1, pos) <= vm[0][pos]) | (MAX(0, pos) >= vm[1][pos]);
    ovl[pos] |= ovl[lson[pos]] | ovl[rson[pos]];
    return;
  }
  if (l > y || r < x) return;
  int mid = (l + r) >> 1;
  modify(knd, lson[pos], l, mid, x, y, v);
  modify(knd, rson[pos], mid + 1, r, x, y, v);
  if (lson[pos]) {
    vm[0][pos] = max(vm[0][pos], vm[0][lson[pos]]);
    vm[1][pos] = min(vm[1][pos], vm[1][lson[pos]]);
  }
  if (rson[pos]) {
    vm[0][pos] = max(vm[0][pos], vm[0][rson[pos]]);
    vm[1][pos] = min(vm[1][pos], vm[1][rson[pos]]);
  }
  ovl[pos] = (MIN(1, pos) <= vm[0][pos]) | (MAX(0, pos) >= vm[1][pos]);
  ovl[pos] |= ovl[lson[pos]] | ovl[rson[pos]];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (op[x][y] == 0) {
      op[x][y] = i;
      if (x % 2 == 0)
        modify(0, 1, 1, n, 1, x / 2, make_pair(y / 2, i));
      else
        modify(1, 1, 1, n, (x + 1) / 2, n, make_pair((y + 1) / 2, i));
    } else {
      if (x % 2 == 0)
        modify(0, 1, 1, n, 1, x / 2, make_pair(y / 2, op[x][y]));
      else
        modify(1, 1, 1, n, (x + 1) / 2, n, make_pair((y + 1) / 2, op[x][y]));
      op[x][y] = 0;
    }
    if (ovl[1])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
