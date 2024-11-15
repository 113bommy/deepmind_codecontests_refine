#include <bits/stdc++.h>
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = getchar();
  }
  return r * t;
}
const int N = 20;
int d, p;
const int m = 5000, M = m - 10;
int val[m + 10], cnt;
long long power(long long a, long long b, long long p) {
  long long r = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) r = r * a % p;
  return r;
}
void add(int a, int b, int c) {
  printf("+ %d %d %d\n", b, c, a);
  cnt++;
  val[a] = (val[b] + val[c]) % p;
}
void pow(int a, int b) {
  printf("^ %d %d\n", b, a);
  cnt++;
  val[a] = power(val[b], d, p);
}
int p1 = 10, p2 = 30, p3 = 50, p4 = 70, p5 = 100, z = m - 1;
void mul(int t, int s, int p, int op = 1) {
  p %= ::p;
  if (op == 2) {
    add(t, z, z);
    for (int i = (0), end_i = (29); i <= end_i; i++)
      if ((p >> i) & 1) add(t, t, p5 + i);
    return;
  }
  if (op) {
    add(M, z, s);
    s = M;
    add(t, z, z);
    add(m, s, z);
  } else {
    if (p <= 1) p += ::p;
    p -= 2;
    add(t, s, s);
    if (p & 1) {
      p--;
      add(t, s, t);
    }
    add(m, s, s);
    p >>= 1;
  }
  while (p) {
    if (p & 1) add(t, m, t);
    p >>= 1;
    if (p) add(m, m, m);
  }
}
int C[N][N];
long long a[N][N];
void Swap(int a, int b) {
  add(m, z, a);
  add(a, z, b);
  add(b, z, m);
}
void pow2(int t, int s) {
  int n = d - 1;
  add(p1, z, z);
  for (int i = (1), end_i = (n - 1); i <= end_i; i++)
    add(p1 + i, 5, p1 + i - 1);
  add(p5, z, s);
  for (int i = (1), end_i = (29); i <= end_i; i++)
    add(p5 + i, p5 + i - 1, p5 + i - 1);
  for (int i = (0), end_i = (n - 1); i <= end_i; i++) {
    add(p2 + i, s, p1 + i);
    pow(p2 + i, p2 + i);
    pow(p3 + i, p1 + i);
    mul(p4 + i, s, d * power(i, d - 1, p) % p, 2);
    add(p3 + i, p3 + i, p4 + i);
    mul(p4 + i, p3 + i, p - 1);
    add(p2 + i, p2 + i, p4 + i);
    for (int j = (0), end_j = (n - 1); j <= end_j; j++)
      a[i][j] = C[d][j + 2] * power(i, d - (j + 2), p) % p;
  }
  for (int i = (0), end_i = (n - 1); i <= end_i; i++)
    std::swap(a[i][0], a[i][n - 1]);
  for (int i = (0), end_i = (n - 1); i <= end_i; i++) {
    if (!a[i][i]) {
      int q = i;
      while (!a[q][i]) q++;
      for (int j = (i), end_j = (n - 1); j <= end_j; j++)
        std::swap(a[i][j], a[q][j]);
      Swap(p2 + i, p2 + q);
    }
    long long q = power(a[i][i], p - 2, p);
    for (int j = (i), end_j = (n - 1); j <= end_j; j++)
      a[i][j] = a[i][j] * q % p;
    mul(p2 + i, p2 + i, q);
    add(p5, z, p2 + i);
    for (int i = (1), end_i = (29); i <= end_i; i++)
      add(p5 + i, p5 + i - 1, p5 + i - 1);
    for (int j = (i + 1), end_j = (n - 1); j <= end_j; j++) {
      q = a[j][i];
      for (int k = (i), end_k = (n - 1); k <= end_k; k++)
        a[j][k] = ((a[j][k] - q * a[i][k]) % p + p) % p;
      mul(M - 1, p2 + i, p - q, 2);
      add(p2 + j, p2 + j, M - 1);
    }
  }
  add(t, z, p2 + (n - 1));
}
int main() {
  for (int i = (1), end_i = (m); i <= end_i; i++) val[i] = 1;
  d = read();
  p = read();
  val[1] = 1;
  val[2] = 1;
  mul(z, z - 1, p, 0);
  for (int i = (0), end_i = (d); i <= end_i; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = (1), end_j = (i - 1); j <= end_j; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  }
  add(3, 1, 2);
  pow2(4, 3);
  mul(6, 2, p - 1);
  add(6, 6, 1);
  pow2(7, 6);
  mul(8, 7, p - 2);
  add(1, 8, 4);
  mul(1, 1, power(4, p - 2, p));
  printf("f 1\n");
  fprintf(stderr, "%d\n", cnt + 1);
  return 0;
}
