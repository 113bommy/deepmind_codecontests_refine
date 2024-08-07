#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mo = 1e9 + 7;
int n, t[N];
void add(int x, int d) {
  for (x++; x < N; x += x & -x) (t[x] += d) %= mo;
}
long long query(int x) {
  int ans = 0;
  for (x++; x; x -= x & -x) (ans += t[x]) %= mo;
  return ans;
}
int main() {
  scanf("%d", &n);
  add(0, 1);
  for (int i = 1; i <= n; i++) {
    int a, t;
    scanf("%d", &a);
    add(a, -(t = query(a) - query(a - 1)));
    add(a, (query(a) + t) * a % mo);
  }
  printf("%d\n", int((query(N - 2) + 2 * mo - 1) % mo));
}
