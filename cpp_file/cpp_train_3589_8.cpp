#include <bits/stdc++.h>
#pragma GCC optimize(4)
using namespace std;
int boy[110], girl[110];
int gcd(int a, int b) {
  if (b > a) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}
int get_lcm(int n, int m) { return n * m / gcd(n, m); }
inline int read() {
  char ch;
  int res = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') res = -1;
  res *= ch - 48;
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return res;
}
int main() {
  int n = read(), m = read();
  int num_boy = read();
  for (int i = 1; i <= num_boy; i++) {
    int ID = read();
    boy[ID] = 1;
  }
  int num_girl = read();
  for (int i = 1; i <= num_girl; i++) {
    int ID = read();
    girl[ID] = 1;
  }
  int max = 2 * get_lcm(n, m);
  for (int i = 0; i <= max - 1; i++) {
    int id_b = i % n, id_g = i % m;
    if (boy[id_b] || girl[id_g]) boy[id_b] = girl[id_g] = 1;
  }
  int wa = 0;
  for (int i = 0; i <= n - 1; i++)
    if (!boy[i]) wa = 1;
  for (int i = 0; i <= m - 1; i++)
    if (!girl[i]) wa = 1;
  if (wa)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
