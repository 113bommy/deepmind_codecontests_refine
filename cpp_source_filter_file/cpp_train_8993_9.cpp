#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T max1(T a, T b, T c = -1234567, T d = -1234567) {
  T ans = a > b ? a : b;
  if (c != -1234567) ans = max1(ans, c);
  if (d != -1234567) ans = max1(ans, d);
  return ans;
}
template <class T>
inline T min1(T a, T b, T c = -1234567, T d = -1234567) {
  T ans = a < b ? a : b;
  if (c != -1234567) ans = min(ans, c);
  if (d != -1234567) ans = min(ans, d);
  return ans;
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
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / abs1(a) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
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
const int maxn = 2000;
int orig[maxn];
int bian[maxn], lbian;
int n;
int ans[maxn], rans[maxn], lans, lrans;
int cnt[maxn];
int last;
inline void check() {
  lbian = 0;
  for (int i = 0; i <= n; i++)
    if (abs(orig[i] - orig[i + 1]) != 1) {
      bian[lbian++] = i + 1;
    }
}
bool dfs(int deep) {
  if (deep == 3) return 0;
  int ranbian[maxn], ranlbian = lbian;
  memcpy(ranbian, bian, sizeof(bian));
  for (int i = 0; i < ranlbian; i++)
    for (int j = 0; j < ranlbian; j++)
      if (i != j && ranbian[i] < ranbian[j]) {
        rans[lrans++] = ranbian[i], rans[lrans++] = ranbian[j];
        reverse(orig + ranbian[i], orig + ranbian[j]);
        check();
        bool ff = 1;
        for (int k = 1; k <= n; k++)
          if (orig[k] != k) {
            ff = 0;
            break;
          }
        if (ff) {
          memcpy(ans, rans, sizeof(rans));
          lans = lrans;
          return 1;
        }
        if (dfs(deep + 1)) return 1;
        reverse(orig + ranbian[i], orig + ranbian[j]);
        lrans -= 2;
      }
  for (int i = 0; i < ranlbian; i++) {
    int a = ranbian[i], b = 0;
    for (int j = 0; j < n; j++)
      if (orig[j] == orig[a - 1] + 1) {
        b = j;
        break;
      }
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    check();
    rans[lrans++] = min(a, b);
    rans[lrans++] = max(a, b) + 1;
    if (lbian <= (2 - deep) * 2) {
      if (dfs(deep + 1)) return 1;
    }
    lrans -= 2;
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    for (int j = 0; j < n; j++)
      if (orig[j] == orig[a - 1] - 1) {
        b = j;
        break;
      }
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    check();
    rans[lrans++] = min(a, b);
    rans[lrans++] = max(a, b) + 1;
    if (lbian <= (2 - deep) * 2) {
      if (dfs(deep + 1)) return 1;
    }
    lrans -= 2;
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    a = ranbian[i] - 1;
    for (int j = 0; j < n; j++)
      if (orig[j] == orig[a + 1] + 1) {
        b = j;
        break;
      }
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    check();
    rans[lrans++] = min(a, b);
    rans[lrans++] = max(a, b) + 1;
    if (lbian <= (2 - deep) * 2) {
      if (dfs(deep + 1)) return 1;
    }
    lrans -= 2;
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    for (int j = 0; j < n; j++)
      if (orig[j] == orig[a + 1] - 1) {
        b = j;
        break;
      }
    reverse(orig + min(a, b), orig + 1 + max(a, b));
    check();
    rans[lrans++] = min(a, b);
    rans[lrans++] = max(a, b) + 1;
    if (lbian <= (2 - deep) * 2) {
      if (dfs(deep + 1)) return 1;
    }
    lrans -= 2;
    reverse(orig + min(a, b), orig + 1 + max(a, b));
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", orig + i);
  orig[n + 1] = n + 1;
  check();
  last = lbian;
  dfs(0);
  printf("%d\n", lans / 2);
  for (int i = lans - 2; i >= 0; i -= 2)
    printf("%d %d\n", ans[i], ans[i + 1] - 1);
  return 0;
}
