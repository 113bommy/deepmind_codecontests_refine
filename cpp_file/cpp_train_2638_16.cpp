#include <bits/stdc++.h>
using namespace std;
int prev(int x) { return x & (x - 1); }
int next(int x) { return (x << 1) - prev(x); }
int h, m, n;
int pos[100010];
class Summator {
 public:
  void init() {
    s = new int[sz_ + 1];
    memset(s, 0, (sz_ + 1) * sizeof(int));
  }
  void modify(int pos, int val) {
    for (; pos <= sz_; pos = next(pos)) {
      s[pos] += val;
    }
  }
  int findSum(int b, int e) {
    if (b == 1) {
      int ret = 0;
      for (int pos = e - 1; pos > 0; pos = prev(pos)) ret += s[pos];
      return ret;
    } else {
      return findSum(1, e) - findSum(1, b);
    }
  }
  int nextFree(int hash, int id1) {
    int curPos = pos[hash];
    if (findSum(curPos, curPos + 1) == 0) {
      modify(curPos, 1);
      id[id1] = curPos;
      return 0;
    }
    int mn, mx;
    int st;
    if (findSum(curPos, sz_ + 1) == sz_ - curPos + 1) {
      st = 1;
      mn = 1;
      mx = curPos;
    } else {
      st = curPos;
      mn = curPos;
      mx = sz_;
    }
    int before = findSum(1, st);
    while (mn < mx) {
      int md = (mn + mx) >> 1;
      if (findSum(1, md + 1) - before == md - st + 1) {
        mn = md + 1;
      } else {
        mx = md;
      }
    }
    int toPlace = mn;
    modify(toPlace, 1);
    id[id1] = toPlace;
    if (toPlace > curPos) return toPlace - curPos;
    return sz_ - curPos + toPlace;
  }
  map<int, int> id;

 public:
  int *s;
  int sz_;
};
Summator s[200010];
int ind[100010];
map<int, int> hh;
int main() {
  cin >> h >> m >> n;
  int nxtSumm = 0;
  memset(ind, -1, sizeof ind);
  for (int i = 0; i < h; ++i) {
    if (ind[i] == -1) {
      for (int cur = i; ind[cur] == -1; cur = (cur + m) % h) {
        ind[cur] = nxtSumm;
        pos[cur] = ++s[nxtSumm].sz_;
      }
      s[nxtSumm].init();
      ++nxtSumm;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string oper;
    cin >> oper;
    int curSumm;
    if (oper == "-") {
      int id;
      cin >> id;
      curSumm = ind[hh[id]];
      s[curSumm].modify(s[curSumm].id[id], -1);
    } else {
      int id, hash;
      cin >> id >> hash;
      hh[id] = hash;
      curSumm = ind[hash];
      int hol = s[curSumm].nextFree(hash, id);
      ans += hol;
    }
  }
  cout << ans << endl;
  return 0;
}
