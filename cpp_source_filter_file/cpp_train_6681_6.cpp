#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (long long)(1e9 + 7);
const long double eps = (1e-9);
const long long oo = (long long)(1e18);
template <typename charT>
struct SuffixArray {
  int n;
  vector<int> sa, rank, lcp;
  SuffixArray(const basic_string<charT> &second)
      : n(second.length() + 1), sa(n), rank(n), lcp(n) {
    vector<int> _sa(n), bucket(n);
    iota(sa.rbegin(), sa.rend(), 0);
    sort(next(sa.begin()), sa.end(),
         [&](int i, int j) { return second[i] < second[j]; });
    for (int i = 1, j = 0; i < n; ++i) {
      rank[sa[i]] =
          rank[sa[i - 1]] + (i == 1 || second[sa[i - 1]] < second[sa[i]]);
      if (rank[sa[i]] != rank[sa[i - 1]]) bucket[++j] = i;
    }
    for (int len = 1; len <= n; len += len) {
      for (int i = 0, j; i < n; ++i) {
        if ((j = sa[i] - len) < 0) j += n;
        _sa[bucket[rank[j]]++] = j;
      }
      sa[_sa[bucket[0] = 0]] = 0;
      for (int i = 1, j = 0; i < n; ++i) {
        if (rank[_sa[i]] != rank[_sa[i - 1]] ||
            rank[_sa[i] + len] != rank[_sa[i - 1] + len])
          bucket[++j] = i;
        sa[_sa[i]] = j;
      }
      copy(sa.begin(), sa.end(), rank.begin());
      sa.swap(_sa);
      if (rank[sa[n - 1]] == n - 1) break;
    }
    for (int i = 0, j = rank[lcp[0] = 0], k = 0; i < n - 1; ++i, ++k)
      while (k >= 0 && second[i] != second[sa[j - 1] + k])
        lcp[j] = k--, j = rank[sa[j] + 1];
  }
};
template <typename T>
struct RMQ {
  vector<vector<T>> rmq;
  vector<int> lg;
  int n;
  bool t;
  RMQ(vector<T> &v, bool t) : n(v.size()), t(t) {
    lg.push_back(-1);
    for (int i = 1; i <= n + 5; i++) lg.push_back(lg.back() + !(i & (i - 1)));
    for (int i = 0; i <= n; i++) rmq.push_back(vector<T>(lg[n] + 1));
    for (int i = 0; i < n; i++) rmq[i][0] = v[i];
    for (int j = 1; j <= lg[n]; j++)
      for (int i = 0; i + (1 << j) <= n; i++) {
        if (!t)
          rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        else
          rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
      }
  }
  T query(int l, int r) {
    if (l > r) swap(l, r);
    int po = lg[r - l + 1];
    if (!t) return min(rmq[l][po], rmq[r - (1 << po) + 1][po]);
    return max(rmq[l][po], rmq[r - (1 << po) + 1][po]);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string t;
  cin >> t;
  int len = t.size();
  int n;
  cin >> n;
  string it = t;
  reverse((it).begin(), (it).end());
  t.push_back('#');
  it.push_back('#');
  vector<int> pos(n);
  vector<int> sz(n);
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    pos[i] = t.size();
    sz[i] = second.size();
    for (auto c : second) t.push_back(c);
    t.push_back('#');
    reverse((second).begin(), (second).end());
    for (auto c : second) it.push_back(c);
    it.push_back('#');
  }
  SuffixArray<char> sa(t);
  SuffixArray<char> isa(it);
  RMQ<int> rmq(sa.lcp, 0);
  RMQ<int> irmq(isa.lcp, 0);
  vector<long long> alante(sa.sa.size());
  vector<long long> atras(sa.sa.size());
  for (int i = 0; i < n; i++) {
    int p = sa.rank[pos[i]];
    int l = sa.rank[pos[i]];
    int r = sa.rank[pos[i]];
    for (int po = (1 << 17); po; po >>= 1)
      if (l - po >= 0 && rmq.query(l - po + 1, p) >= sz[i]) l -= po;
    for (int po = (1 << 17); po; po >>= 1)
      if (r + po < sa.sa.size() && rmq.query(p + 1, r + po) >= sz[i]) r += po;
    alante[l]++;
    if (r + 1 < sa.sa.size()) alante[r + 1]--;
  }
  for (int i = 0; i < n; i++) {
    int p = isa.rank[pos[i]];
    int l = isa.rank[pos[i]];
    int r = isa.rank[pos[i]];
    for (int po = (1 << 17); po; po >>= 1)
      if (l - po >= 0 && irmq.query(l - po + 1, p) >= sz[i]) l -= po;
    for (int po = (1 << 17); po; po >>= 1)
      if (r + po < isa.sa.size() && irmq.query(p + 1, r + po) >= sz[i]) r += po;
    atras[l]++;
    if (r + 1 < isa.sa.size()) atras[r + 1]--;
  }
  for (int i = 1; i < alante.size(); i++) alante[i] += alante[i - 1];
  for (int i = 1; i < atras.size(); i++) atras[i] += atras[i - 1];
  vector<long long> v1(len);
  vector<long long> v2(len);
  for (int i = 0; i < alante.size(); i++) {
    if (sa.sa[i] < len) v1[sa.sa[i]] = alante[i];
    if (isa.sa[i] < len) v2[len - 1 - isa.sa[i]] = atras[i];
  }
  long long res = 0;
  for (int i = 1; i < len; i++) res += v2[i - 1] * v1[i];
  cout << (res) << '\n';
  return 0;
}
