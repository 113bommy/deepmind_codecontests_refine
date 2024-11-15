#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct block {
  int dat[10];
  void clear() { memset(dat, 0, sizeof(dat)); }
  block() { clear(); }
  block(int x) {
    clear();
    dat[x]++;
  }
  block(const block& oth) {
    for (int i = 0; i < (int)(10); i++) dat[i] = oth.dat[i];
  }
  block operator+(const block& oth) const {
    block ans;
    for (int i = 0; i < (int)(10); i++) ans.dat[i] = dat[i] + oth.dat[i];
    return ans;
  }
  block operator-(const block& oth) const {
    block ans;
    for (int i = 0; i < (int)(10); i++) ans.dat[i] = dat[i] - oth.dat[i];
    return ans;
  }
  block count(int l, int r) const {
    block ret;
    for (int i = 9 - l; i >= 0; i--) ret.dat[i] = dat[i + l];
    r -= l;
    for (int i = 8; i >= 0; i--) ret.dat[i] += ret.dat[i + 1];
    for (int i = 0; i < (int)(9 - r); i++) ret.dat[i] -= ret.dat[i + r + 1];
    return ret;
  }
};
struct seg_tree {
  block dat[262144];
  int bld[262144];
  void init() { memset(bld, -1, sizeof(bld)); }
  void pushdown(int v) {
    if (bld[v << 1] == -1) {
      dat[v << 1] = dat[v << 1] + dat[v];
      bld[v << 1] = bld[v];
    }
    if (bld[v << 1 | 1] == -1) {
      dat[v << 1 | 1] = dat[v << 1 | 1] + dat[v];
      bld[v << 1 | 1] = bld[v];
    }
    dat[v] = block();
    bld[v] = -1;
  }
  void add(int l, int r, const block& val, int v = 1, int cl = 0,
           int cr = 131071) {
    if (bld[v] != -1) return;
    if (l == cl && r == cr) {
      dat[v] = dat[v] + val;
      return;
    }
    pushdown(v);
    int mid = (cl + cr) >> 1;
    if (l <= mid) add(l, min(r, mid), val, v << 1, cl, mid);
    if (r > mid) add(max(l, mid + 1), r, val, v << 1 | 1, mid + 1, cr);
  }
  void blockade(int l, int r, int bi, int v = 1, int cl = 0, int cr = 131071) {
    if (bld[v] != -1) return;
    if (l == cl && r == cr) {
      bld[v] = bi;
      return;
    }
    pushdown(v);
    int mid = (cl + cr) >> 1;
    if (l <= mid) blockade(l, min(r, mid), bi, v << 1, cl, mid);
    if (r > mid) blockade(max(l, mid + 1), r, bi, v << 1 | 1, mid + 1, cr);
  }
  int q_blockade(int id, int v = 1, int cl = 0, int cr = 131071) {
    if (cl == id && cr == id) return bld[v];
    pushdown(v);
    int mid = (cl + cr) >> 1;
    if (id <= mid)
      return q_blockade(id, v << 1, cl, mid);
    else
      return q_blockade(id, v << 1 | 1, mid + 1, cr);
  }
  block query(int id, int v = 1, int cl = 0, int cr = 131071) {
    if (cl == id && cr == id) return dat[v];
    pushdown(v);
    int mid = (cl + cr) >> 1;
    if (id <= mid)
      return query(id, v << 1, cl, mid);
    else
      return query(id, v << 1 | 1, mid + 1, cr);
  }
} tre;
char ch[100005];
vector<pair<int, int> > qy[100005];
block ans[100005];
int n, q, sz;
int bid[100005];
bool tol[100005], isz[100005];
vector<int> ts;
int pre[100005], nxr[100005];
block pfx[100005];
void init_blo() {
  ch[0] = '>';
  for (int i = 0; i <= n; i++)
    if (ch[i] == '<' || ch[i] == '>') {
      tol[i] = ch[i] == '<';
      int cur = -1;
      for (int j = i + 1; j <= n && ch[j] != '<' && ch[j] != '>'; j++)
        cur = max(cur, ch[j] - '0');
      isz[i] = !(cur & 1);
    }
  stack<int> st;
  for (int i = 0; i <= n; i++) {
    if (tol[i]) {
      ts.push_back(i);
      if (st.empty())
        pre[i] = -1;
      else {
        pre[i] = st.top();
        st.pop();
      }
    }
    if (isz[i]) st.push(i);
  }
  nxr[n] = n;
  for (int i = n - 1; i >= 0; i--) nxr[i] = ch[i] == '>' ? i : nxr[i + 1];
  pfx[0] = block();
  for (int i = 1; i <= (int)(n); i++) {
    pfx[i] = pfx[i - 1];
    if (ch[i] != '<' && ch[i] != '>') pfx[i] = pfx[i] + block(ch[i] - '0');
  }
  tre.init();
}
block get_block(int l, int r) {
  if (l > r) return block();
  if (l == 0) return pfx[r];
  return pfx[r] - pfx[l - 1];
}
int prev_ts(int p) {
  int pos = lower_bound(ts.begin(), ts.end(), p) - ts.begin();
  if (pos == 0) return -1;
  return ts[pos - 1];
}
void new_block(int i) {
  tre.blockade(pre[i] + 1, i, i);
  int p = i;
  block cur = get_block(pre[i] + 1, i);
  for (;;) {
    p = prev_ts(p);
    if (p <= pre[i]) break;
    cur = cur - get_block(pre[p] + 1, p);
    p = pre[p];
  }
  tre.add(0, i, cur);
}
block query(int l, int r) {
  int b = tre.q_blockade(l);
  if (b == -1)
    return tre.query(l).count(1, 10) + get_block(l, r).count(0, 0);
  else
    return get_block(nxr[l] + 1, b).count(2, 10) + get_block(l, b).count(0, 1);
}
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", ch + 1);
  init_blo();
  for (int i = 0; i < (int)(q); i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    qy[r].push_back(make_pair(l, i));
  }
  for (int i = 0; i <= n; i++) {
    if (ch[i] == '<') new_block(i);
    for (int j = 0; j < (int)(qy[i].size()); j++)
      ans[qy[i][j].second] = query(qy[i][j].first, i);
  }
  for (int i = 0; i < (int)(q); i++) {
    for (int j = 0; j < (int)(10); j++) printf("%d ", ans[i].dat[j]);
    printf("\n");
  }
  return 0;
}
