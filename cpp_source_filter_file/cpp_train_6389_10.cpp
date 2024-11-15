#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T max1(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T min1(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T gcd1(T a, T b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd1(b, a % b);
}
template <class T>
inline T lb(T num) {
  return num & (-num);
}
inline int jud(double a, double b) {
  if (abs1(a - b) < eps) return 0;
  if (a < b) return -1;
  return 1;
}
template <class t>
inline int find(int val, t *a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 1) return 0;
  int be = 0, en = na - 1;
  if (a[0] <= a[na - 1]) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(a[mid], val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(a[mid], val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && a[be] > val && be != 0) be--;
    if (!f_small && a[be] < val && be != na - 1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(a[mid], val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(a[mid], val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && a[be] < val && be != 0) be--;
    if (f_small && a[be] > val && be != na - 1) be++;
  }
  return be;
}
inline int bitnum(unsigned long long nValue) {
  nValue = ((0xaaaaaaaaaaaaaaaaull & nValue) >> 1) +
           (0x5555555555555555ull & nValue);
  nValue = ((0xccccccccccccccccull & nValue) >> 2) +
           (0x3333333333333333ull & nValue);
  nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue) >> 4) +
           (0x0f0f0f0f0f0f0f0full & nValue);
  nValue = ((0xff00ff00ff00ff00ull & nValue) >> 8) +
           (0x00ff00ff00ff00ffull & nValue);
  nValue = ((0xffff0000ffff0000ull & nValue) >> 16) +
           (0x0000ffff0000ffffull & nValue);
  nValue = ((0xffffffff00000000ull & nValue) >> 32) +
           (0x00000000ffffffffull & nValue);
  return nValue;
}
long long pow(long long n, long long m, long long mod = 0) {
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
const int maxn = 100100;
template <class t>
struct segment_node {
  int be, en;
  t maxv, sum;
};
template <class t>
struct segment_tree {
  int l;
  segment_node<t> tree[maxn * 4 + 100];
  inline int gleft(int no) { return no << 1; }
  inline int gright(int no) { return (no << 1) + 1; }
  inline int gfa(int no) { return no >> 1; }
  inline segment_tree() { l = 0; }
  void build(int no, int l, int r, t orig = 0, t *a = NULL) {
    if (l == r) {
      tree[no].be = tree[no].en = l;
      if (a == NULL)
        tree[no].maxv = orig;
      else
        tree[no].maxv = a[l];
      tree[no].sum = tree[no].maxv;
      return;
    }
    tree[no].be = l;
    tree[no].en = r;
    int mid = (l + r) / 2;
    build(gleft(no), l, mid, orig, a);
    build(gright(no), mid + 1, r, orig, a);
    tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
    tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
  }
  void down(int l, int r, int no, t ranadd, int f) {
    if (l <= tree[no].be && r >= tree[no].en) {
      if (f > 0) {
        tree[no].sum += 1;
        tree[no].maxv = ranadd;
      } else if (f < 0) {
        tree[no].sum -= 1;
        tree[no].maxv = 0;
      } else
        tree[no].maxv = max1(ranadd, tree[no].maxv);
      return;
    }
    int mid = (tree[no].be + tree[no].en) / 2;
    if (r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd, f);
    if (r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd, f);
    tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
    tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
  }
  t getmax(int l, int r, int no1) {
    if (l > r) return 0;
    if (l <= tree[no1].be && r >= tree[no1].en) return tree[no1].maxv;
    t ans = 0;
    int mid = (tree[no1].be + tree[no1].en) / 2;
    if (r >= tree[no1].be && l <= mid)
      ans = max1(getmax(max1(l, tree[no1].be), min1(r, mid), gleft(no1)), ans);
    if (r >= mid + 1 && l <= tree[no1].en)
      ans = max1(getmax(max1(l, mid + 1), min1(r, tree[no1].en), gright(no1)),
                 ans);
    return ans;
  }
  int getrank(int rank, int no) {
    if (rank > tree[no].sum) return -1;
    if (tree[no].be == tree[no].en) return tree[no].be;
    if (rank <= tree[gleft(no)].sum) return getrank(rank, gleft(no));
    return getrank(rank - (tree[gleft(no)].sum), gright(no));
  }
};
segment_tree<int> sgt, sgth;
int h[maxn], no[maxn];
bool ff[maxn];
int arr[maxn][12];
int n, nq;
int dp[12];
int main() {
  scanf("%d%d", &n, &nq);
  sgt.build(1, 0, n);
  sgth.build(1, 0, maxn + 11);
  memset(no, -1, sizeof(no));
  for (int i = 0; i < nq; i++) {
    int cate;
    scanf("%d", &cate);
    if (cate == 1) {
      int hh, no1;
      scanf("%d%d", &no1, &hh);
      no1--;
      h[no1] = hh - i;
      no[i] = no1;
      memset(arr[no1], -1, sizeof(arr[no1]));
      for (int j = max1(i - 9, 0); j < i; j++)
        if (!ff[no[j]]) arr[no1][j - i + 9] = no[j];
      arr[no1][9] = n;
      arr[no1][10] = no1;
      sort(arr[no1], arr[no1] + 11);
      int mid = 0;
      while (mid < 10 && arr[no1][mid] <= no1) mid++;
      int rans = 0;
      for (int j = mid; j <= 10; j++) {
        rans = max1(sgt.getmax(arr[no1][j - 1] + 1, arr[no1][j] - 1, 1), rans);
        if (arr[no1][j] != n && h[arr[no1][j]] > h[no1])
          rans = max1(sgt.getmax(arr[no1][j], arr[no1][j], 1), rans);
      }
      rans++;
      sgt.down(no1, no1, 1, rans, 1);
      sgth.down(h[no1] + maxn, h[no1] + maxn, 1, rans, 1);
      memset(dp, 0, sizeof(dp));
      dp[mid - 1] = rans;
      for (int j = mid - 2; j >= 0; j--) {
        if (arr[no1][j] == -1) break;
        for (int k = j + 1; k < mid; k++)
          if (h[arr[no1][j]] < h[arr[no1][k]]) dp[j] = max1(dp[k] + 1, dp[j]);
      }
      for (int j = 0; j < mid - 1; j++) {
        if (arr[no1][j] == -1) continue;
        sgt.down(arr[no1][j], arr[no1][j], 1, dp[j], 0);
        sgth.down(h[arr[no1][j]] + maxn, h[arr[no1][j]] + maxn, 1, dp[j], 0);
      }
    } else {
      int no1;
      scanf("%d", &no1);
      int ranno[10];
      for (int j = 1; j <= no1; j++) {
        ranno[j] = sgt.getrank(1, 1);
        sgt.down(ranno[j], ranno[j], 1, 0, -1);
        sgth.down(h[ranno[j]] + maxn, h[ranno[j]] + maxn, 1, 0, -1);
      }
      for (int j = no1 - 1; j >= 1; j--) {
        int rans = sgth.getmax(h[ranno[j]] + 1 + maxn, maxn + 10, 1);
        sgth.down(h[ranno[j]] + maxn, h[ranno[j]] + maxn, 1, rans + 1, 1);
        sgt.down(ranno[j], ranno[j], 1, rans + 1, 1);
      }
      ff[ranno[no1]] = 1;
    }
    printf("%d\n", sgt.getmax(0, n, 1));
  }
  return 0;
}
