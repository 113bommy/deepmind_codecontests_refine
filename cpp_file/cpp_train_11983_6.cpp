#include <bits/stdc++.h>
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline bool repr(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool repl(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T gcd(T a, T b) {
  T t;
  if (a < b) {
    while (a) {
      t = a;
      a = b % a;
      b = t;
    }
    return b;
  } else {
    while (b) {
      t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
struct Cg {
  __attribute__((always_inline)) inline char operator()() { return getchar(); }
};
struct Cp {
  __attribute__((always_inline)) inline void operator()(char x) { putchar(x); }
};
__attribute__((always_inline)) inline bool IS(char x) {
  return x == 10 || x == 13 || x == ' ';
}
template <typename T>
struct Fr {
  T P;
  __attribute__((always_inline)) inline Fr &operator,(int &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator int() {
    int x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(long long &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator long long() {
    long long x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(char &x) {
    for (x = P(); IS(x); x = P())
      ;
    return *this;
  }
  __attribute__((always_inline)) inline operator char() {
    char x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(char *x) {
    char t = P();
    for (; IS(t); t = P())
      ;
    if (~t) {
      for (; !IS(t) && ~t; t = P()) *x++ = t;
    }
    *x++ = 0;
    return *this;
  }
  __attribute__((always_inline)) inline Fr &operator,(double &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator double() {
    double x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(long double &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator long double() {
    long double x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(unsigned int &x) {
    x = 0;
    unsigned char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  __attribute__((always_inline)) inline operator unsigned int() {
    unsigned int x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(unsigned long long &x) {
    x = 0;
    unsigned char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  __attribute__((always_inline)) inline operator unsigned long long() {
    unsigned long long x;
    *this, x;
    return x;
  }
};
Fr<Cg> in;
template <typename T>
struct Fw {
  T P;
  __attribute__((always_inline)) inline Fw &operator,(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(unsigned int x) {
    if (x) {
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(unsigned int x) {
    if (x) {
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(unsigned long long x) {
    if (x) {
      unsigned char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(unsigned long long x) {
    if (x) {
      unsigned char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(char x) {
    P(x);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(char x) {
    P(x);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(long double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
};
Fw<Cp> out;
const int N = 100007;
std::pair<std::pair<int, int>, int> px[N];
int n, s[N], q[N], pre[N];
bool vis[N];
inline void br() {
  int st = 0, qe = 0;
  for (int i = 1, iend = n; i <= iend; i++)
    if (s[i]) st |= 1 << i - 1;
  vis[st] = 1;
  q[qe++] = st;
  for (int i = 0; i < qe; i++) {
    if (q[i] == 0) {
      out, "YES\n";
      std::vector<std::pair<std::pair<int, int>, int>> ans;
      int y = 0;
      while (y != st) {
        ans.push_back(px[y]);
        y = pre[y];
      }
      out, (int)ans.size(), '\n';
      for (__typeof((ans).rend()) j = (ans).rbegin(); j != (ans).rend(); ++j)
        out, j->first.first + 1, ' ', j->first.second + 1, ' ', j->second + 1,
            '\n';
      return;
    }
    int x = q[i];
    for (int j = 0, jend = n; j < jend; j++)
      for (int k = 0, kend = j; k < kend; k++)
        for (int l = 0, lend = k; l < lend; l++)
          if (j - k == k - l) {
            int y = x ^ (1 << j) ^ (1 << k) ^ (1 << l);
            if (!vis[y]) {
              vis[y] = 1;
              q[qe++] = y;
              pre[y] = x;
              px[y] = std::make_pair(std::make_pair(l, k), j);
            }
          }
  }
  out, "NO\n";
  return;
}
int main() {
  in, n;
  for (int i = 1, iend = n; i <= iend; i++) in, s[i];
  if (n <= 16) {
    return br(), 0;
  }
  std::vector<std::pair<std::pair<int, int>, int>> ans;
  int c = 0;
  for (int i = 1, iend = n; i <= iend; i++) c += s[i];
  for (int i = 1, iend = n; i <= iend; i++)
    if (s[i] && c >= 3) {
      int t = i + 1;
      for (int j = 1, jend = 100; j <= jend; j++) {
        if (i + j * 2 <= n && s[i + j] && s[i + j * 2]) {
          ans.push_back(std::make_pair(std::make_pair(i, i + j), i + j * 2));
          s[i] ^= 1;
          s[i + j] ^= 1;
          s[i + j * 2] ^= 1;
          c -= 3;
          goto ok;
        }
      }
      while (!s[t]) t++;
      t -= i;
      if (i + t * 2 <= n) {
        c -= 2;
        s[i] ^= 1;
        s[i + t] ^= 1;
        s[i + t * 2] ^= 1;
        ans.push_back(std::make_pair(std::make_pair(i, i + t), i + t * 2));
        c -= s[i + t * 2] ? -1 : 1;
        goto ok;
      }
      if (t % 2 == 0) {
        c -= 2;
        s[i] ^= 1;
        s[i + t] ^= 1;
        s[i + t / 2] ^= 1;
        ans.push_back(std::make_pair(std::make_pair(i, i + t / 2), i + t));
        c -= s[i + t / 2] ? -1 : 1;
        goto ok;
      }
      if ((i + t != n && s[i + t + 1]) || t == 1) {
        ++t;
        s[i] ^= 1;
        s[i + t] ^= 1;
        s[i + t / 2] ^= 1;
        ans.push_back(std::make_pair(std::make_pair(i, i + t / 2), i + t));
        c--;
        c -= s[i + t] ? -1 : 1;
        c -= s[i + t / 2] ? -1 : 1;
        goto ok;
      }
      --t;
      s[i] ^= 1;
      s[i + t] ^= 1;
      s[i + t / 2] ^= 1;
      ans.push_back(std::make_pair(std::make_pair(i, i + t / 2), i + t));
      c--;
      c -= s[i + t] ? -1 : 1;
      c -= s[i + t / 2] ? -1 : 1;
    ok:;
    }
  for (int x = 1, xend = n; x <= xend; x++)
    if (s[x]) {
      if (x + 6 <= n) {
        ans.push_back(std::make_pair(std::make_pair(x + 3, x + 4), x + 5));
        ans.push_back(std::make_pair(std::make_pair(x + 4, x + 5), x + 6));
        ans.push_back(std::make_pair(std::make_pair(x, x + 3), x + 6));
      } else {
        ans.push_back(std::make_pair(std::make_pair(x - 5, x - 4), x - 3));
        ans.push_back(std::make_pair(std::make_pair(x - 6, x - 5), x - 4));
        ans.push_back(std::make_pair(std::make_pair(x - 6, x - 3), x));
      }
    }
  out, "YES\n";
  out, (int)ans.size(), '\n';
  for (__typeof((ans).end()) i = (ans).begin(); i != (ans).end(); ++i)
    out, i->first.first, ' ', i->first.second, ' ', i->second, '\n';
}
