#include <bits/stdc++.h>
using namespace ::std;
struct info {
  int s;
  int e;
  int id;
};
bool operator<(const info &in1, const info &in2) {
  return ((in1.s < in2.s) || ((in1.s == in2.s) && (in1.e > in2.e)) ||
          ((in1.s == in2.s) && (in1.e == in2.e) && (in1.id < in2.id)));
}
class SegT {
 public:
  int op(int x, int y) { return max(x, y); }
  int up(int n) {
    int m = 1;
    n--;
    while (n) {
      n >>= 1;
      m <<= 1;
    }
    return m;
  }
  SegT(vector<int> &v) {
    ID = 0;
    sz = up(v.size());
    P = new int[2 * sz];
    Q = new int[2 * sz];
    for (int i = 0; i < sz; i++) {
      P[sz + i] = (i < v.size()) ? v[i] : ID;
      Q[sz + i] = (i < v.size()) ? i : -1;
    }
    for (int i = sz - 1; i > 0; i--) {
      if (P[2 * i] < P[2 * i + 1]) {
        P[i] = P[2 * i + 1];
        Q[i] = Q[2 * i + 1];
      } else {
        P[i] = P[2 * i];
        Q[i] = Q[2 * i];
      }
    }
  }
  ~SegT() { delete[] P; }
  int range_val(int idx, int beg, int end, int s, int e, int &res) {
    if (s > end || e < beg) {
      res = -1;
      return ID;
    }
    if (beg >= s && end <= e) {
      res = Q[idx];
      return P[idx];
    }
    int mid = (beg + end) / 2;
    int res1;
    int res2;
    int u = range_val(2 * idx, beg, mid, s, e, res1);
    int v = range_val(2 * idx + 1, mid + 1, end, s, e, res2);
    if (u < v) {
      res = res2;
      return v;
    } else {
      res = res1;
      return u;
    }
  }
  int range_val(int s, int e, int &res) {
    return range_val(1, 0, sz - 1, s, e, res);
  }

 private:
  int ID;
  int sz;
  int *P;
  int *Q;
};
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  vector<info> P(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    P[i].s = x;
    P[i].e = y;
    P[i].id = 1 + i;
  }
  std::sort(P.begin(), P.end());
  vector<info> Q;
  Q.reserve(n);
  Q.push_back(P[0]);
  for (int i = 1; i < n; i++)
    if (P[i].e > Q.back().e) Q.push_back(P[i]);
  vector<int> v(Q.size());
  for (int i = 0; i < Q.size(); i++) v[i] = Q[i].e - Q[i].s;
  SegT segT(v);
  int64_t ans = 0;
  int opt_i = -1;
  int opt_j = -1;
  for (int j = 0; j < m; j++) {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (a >= Q.back().e) continue;
    if (b <= Q.front().s) continue;
    int x = -1;
    int y = -1;
    if (Q.front().s >= a)
      x = 0;
    else {
      if (Q.back().s < a)
        x = Q.size();
      else {
        int beg = 0;
        int end = Q.size() - 1;
        while ((end - beg) > 1) {
          int mid = (beg + end) / 2;
          if (Q[mid].s >= a)
            end = mid;
          else
            beg = mid;
        }
        x = end;
      }
    }
    if (Q.back().e <= b)
      y = Q.size() - 1;
    else {
      if (Q.front().e > b)
        y = -1;
      else {
        int beg = 0;
        int end = Q.size() - 1;
        while ((end - beg) > 1) {
          int mid = (beg + end) / 2;
          if (Q[mid].e <= b)
            beg = mid;
          else
            end = mid;
        }
        y = beg;
      }
    }
    if (x > 0) {
      int rt = min(Q[x - 1].e, b);
      int64_t val = (int64_t)(rt - a) * (int64_t)c;
      if (val > ans) {
        ans = val;
        opt_i = Q[x - 1].id;
        opt_j = 1 + j;
      }
    }
    if ((1 + y) < Q.size()) {
      int lt = max(Q[y + 1].s, a);
      int64_t val = (int64_t)(b - lt) * (int64_t)c;
      if (val > ans) {
        ans = val;
        opt_i = Q[y + 1].id;
        opt_j = 1 + j;
      }
    }
    if (x >= 0 && x < Q.size() && y >= 0 && y < Q.size() && x <= y) {
      int idx;
      int len = segT.range_val(x, y, idx);
      int64_t val = (int64_t)len * (int64_t)c;
      if (val > ans) {
        ans = val;
        opt_i = Q[idx].id;
        opt_j = 1 + j;
      }
    }
  }
  std::cout << ans << std::endl;
  if (ans > 0) printf("%d %d\n", opt_i, opt_j);
  return 0;
}
