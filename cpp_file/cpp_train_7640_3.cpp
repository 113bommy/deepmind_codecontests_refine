#include <bits/stdc++.h>
using namespace std;
int mat[210000];
long long rev[210000];
const long long mod = 1000000007;
long long pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret *= a;
      ret %= mod;
    }
    a = a * a % mod;
    b /= 2;
  }
  return ret;
}
long long cal(int a, int b) {
  long long ret = 1;
  for (int i = b + 1; i <= a; i++) {
    ret *= i;
    ret %= mod;
  }
  for (int i = 1; i <= a - b; i++) {
    ret *= rev[i];
    ret %= mod;
  }
  return ret;
}
int main() {
  for (int i = 1; i <= 200000; i++) {
    rev[i] = pow(i, mod - 2);
  }
  int n, m, g;
  while (scanf("%d%d%d", &n, &m, &g) != EOF) {
    if (n + m == 0) {
      while (1)
        ;
    }
    if (m == 0) {
      for (int i = 0; i < n; i++) {
        mat[i] = 0;
      }
      for (int i = n - 1; i; i--) {
        if (mat[i - 1] == 0 && mat[i] == 0) {
          mat[i - 1] = 1;
        } else {
          mat[i - 1] = 0;
        }
      }
      if (mat[0] == g) {
        printf("1\n");
      } else {
        printf("0\n");
      }
      continue;
    } else if (n == 0) {
      for (int i = 0; i < m; i++) {
        mat[i] = 1;
      }
      for (int i = m - 1; i; i--) {
        if (mat[i - 1] == 0 && mat[i] == 0) {
          mat[i - 1] = 1;
        } else {
          mat[i - 1] = 0;
        }
      }
      if (mat[0] == g) {
        printf("1\n");
      } else {
        printf("0\n");
      }
      continue;
    }
    long long ans = 0;
    long long tmp = cal(n + m - min(n, n + m - 2) - 1, n - min(n, n + m - 2));
    for (int i = min(n, n + m - 2); i >= 0; i--) {
      if ((i & 1) == g) {
        ans += tmp;
        ans %= mod;
      }
      if (i) {
        tmp *= (n + m - (i - 1) - 1);
        tmp %= mod;
        tmp *= rev[n - (i - 1)];
        tmp %= mod;
      }
    }
    if (m == 1) {
      n += 2;
      for (int i = 0; i < n; i++) {
        mat[i] = 0;
      }
      for (int i = n - 1; i; i--) {
        if (mat[i - 1] == 0 && mat[i] == 0) {
          mat[i - 1] = 1;
        } else {
          mat[i - 1] = 0;
        }
      }
      if (mat[0] == g) {
        ans++;
        ans %= mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
