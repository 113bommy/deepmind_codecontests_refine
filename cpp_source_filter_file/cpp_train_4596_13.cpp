#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int L = 8388608 + 5;
const int mo = 998244353;
const int N = (1 << 17) + 5;
const int P = 6;
const int M = 17;
long long quickmi(long long x, long long tim) {
  x = (x % mo + mo) % mo;
  long long ret = 1;
  for (; tim; tim /= 2, x = x * x % mo)
    if (tim & 1) ret = ret * x % mo;
  return ret;
}
long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
int f[L][4];
int n, k;
int X, Y, Z;
int to[N];
long long tmp[4][4];
long long g[N];
int main() {
  n = get();
  k = get();
  X = get(), Y = get(), Z = get();
  int all = 0;
  for (int i = 1; i <= n; i++) {
    int a = get(), b = get(), c = get();
    all ^= a, b ^= a, c ^= a;
    int x = 0;
    for (int i = M - 1; i >= M - P; i--) {
      x = x * 4;
      if ((b & (1 << i)) > 0) x ^= 1;
      if ((c & (1 << i)) > 0) x ^= 2;
    }
    to[0] = 0;
    for (int w = 0; w <= M - P - 1; w++) {
      int tr = 1 * ((b & (1 << w)) > 0) + 2 * ((c & (1 << w)) > 0);
      for (int i = 0; i <= (1 << w) - 1; i++) to[i ^ (1 << w)] = to[i] ^ tr;
    }
    x <<= (M - P);
    for (int i = 0; i <= (1 << (M - P)) - 1; i++) f[x ^ i][to[i]]++;
  }
  int Lim = (1 << (M - P)) * (1 << (2 * P));
  for (int i = 1 << (M - P), d = M - P; d < M; i <<= 2, d++)
    for (int j = 0; j < Lim; j += i << 2)
      for (int k = 0; k < (1 << d); k++) {
        for (int x = j + k, w = 0; w < 4; w++, x = x + i) {
          tmp[w][0] = f[x][0];
          tmp[w][1] = f[x][1];
          tmp[w][2] = f[x][2];
          tmp[w][3] = f[x][3];
        }
        f[j + k][0] = (tmp[0][0] + tmp[1][0] + tmp[2][0] + tmp[3][0]) % mo;
        f[j + k][1] = (tmp[0][1] + tmp[1][1] + tmp[2][1] + tmp[3][1]) % mo;
        f[j + k][2] = (tmp[0][2] + tmp[1][2] + tmp[2][2] + tmp[3][2]) % mo;
        f[j + k][3] = (tmp[0][3] + tmp[1][3] + tmp[2][3] + tmp[3][3]) % mo;
        f[(1 << d) + j + k][0] =
            (tmp[0][0] + tmp[1][1] + tmp[2][2] + tmp[3][3]) % mo;
        f[(1 << d) + j + k][1] =
            (tmp[0][1] + tmp[1][0] + tmp[2][3] + tmp[3][2]) % mo;
        f[(1 << d) + j + k][2] =
            (tmp[0][2] + tmp[1][3] + tmp[2][0] + tmp[3][1]) % mo;
        f[(1 << d) + j + k][3] =
            (tmp[0][3] + tmp[1][2] + tmp[2][1] + tmp[3][0]) % mo;
      }
  for (int i = 0; i <= (1 << M) - 1; i++) {
    g[i] = quickmi(X + Y + Z, f[i][0]) * quickmi(X - Y + Z, f[i][1]) % mo *
           quickmi(X + Y - Z, f[i][2]) % mo * quickmi(X - Y - Z, f[i][3]) % mo;
  }
  for (int i = 1; i < (1 << M); i <<= 1)
    for (int j = 0; j < (1 << M); j += i << 1)
      for (int k = 0; k < i; k++) {
        long long l = g[j + k], r = g[i + j + k];
        g[i + j + k] = l < r ? l - r + mo : l - r;
        g[j + k] = l + r >= mo ? l + r - mo : l + r;
      }
  long long ny = quickmi((1 << M), mo - 2);
  for (int i = 0; i <= (1 << M) - 1; i++) g[i] = g[i] * ny % mo;
  for (int i = 0; i <= (1 << k) - 1; i++) printf("%I64d ", g[i ^ all]);
  return 0;
}
