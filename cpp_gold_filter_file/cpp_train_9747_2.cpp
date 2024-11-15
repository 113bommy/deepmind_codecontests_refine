#include <bits/stdc++.h>
using namespace std;
struct data {
  int x, y;
} O, Q[50005 * 3], S[50005 * 3], U[50005 * 3], D[50005 * 3];
int _U, _D, _S, cnt, T;
int x, y;
data operator+(const data &a, const data &b) {
  return (data){a.x + b.x, a.y + b.y};
}
data operator-(const data &a, const data &b) {
  return (data){a.x - b.x, a.y - b.y};
}
long long operator*(const data &a, const data &b) {
  return 1ll * a.x * b.y - 1ll * b.x * a.y;
}
int operator<(const data &a, const data &b) { return a.x < b.x; }
struct idol {
  data a[50005], d[50005], mi;
  int n;
  void read() {
    scanf("%d", &n);
    mi.y = 1e9;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      if (a[i].y < mi.y || a[i].y == mi.y && a[i].x < mi.x) mi = a[i];
    }
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i++) d[i] = a[i + 1] - a[i];
  }
} A, B, C;
const double pi2 = 2 * acos(-1.);
double New(double x) { return x > -1e-9 ? x : pi2 + x; }
int cmp1(const data &a, const data &b) {
  return New(atan2(a.y, a.x)) < New(atan2(b.y, b.x));
}
void merge() {
  cnt = A.n;
  for (int i = 1; i <= A.n; i++) Q[i] = A.d[i];
  for (int i = 1; i <= B.n; i++) Q[cnt + i] = B.d[i];
  cnt += B.n;
  for (int i = 1; i <= C.n; i++) Q[cnt + i] = C.d[i];
  cnt += C.n;
  sort(Q + 1, Q + cnt + 1, cmp1);
  S[1] = (data){A.mi.x + B.mi.x + C.mi.x, A.mi.y + B.mi.y + C.mi.y};
  for (int i = 1; i < cnt; i++) S[i + 1] = S[i] + Q[i];
}
int cmp2(const data &a, const data &b) {
  long long t = (a - O) * (b - O);
  return t < 0 || t == 0 && a.x < b.x;
}
void Get_Pol() {
  int uL = 1, uR = 1, dL = 1, dR = 1;
  for (int i = 2; i <= cnt; i++) {
    if (S[i].x < S[uL].x || S[i].x == S[uL].x && S[i].y > S[uL].y) uL = i;
    if (S[i].x < S[dL].x || S[i].x == S[dL].x && S[i].y < S[dL].y) dL = i;
    if (S[i].x > S[uR].x || S[i].x == S[uR].x && S[i].y > S[uR].y) uR = i;
    if (S[i].x > S[dR].x || S[i].x == S[dR].x && S[i].y < S[dR].y) dR = i;
  }
  int k = uL;
  while (true) {
    U[++_U] = S[k];
    if (k == uR) break;
    if (!(--k)) k = cnt;
  }
  k = dL;
  while (true) {
    D[++_D] = S[k];
    if (k == dR) break;
    if ((++k) > cnt) k = 1;
  }
}
int Query(const data &a) {
  if (a.x < U[1].x || a.x > U[_U].x) return 0;
  int t = lower_bound(U + 1, U + _U + 1, a) - U;
  if (U[t].x == a.x && a.y > U[t].y) return 0;
  if (U[t].x != a.x && (U[t - 1] - a) * (U[t] - a) > 0) return 0;
  t = lower_bound(D + 1, D + _D + 1, a) - D;
  if (D[t].x == a.x && a.y < D[t].y) return 0;
  if (D[t].x != a.x && (D[t - 1] - a) * (D[t] - a) < 0) return 0;
  return 1;
}
int main() {
  A.read();
  B.read();
  C.read();
  merge();
  Get_Pol();
  scanf("%d", &T);
  while (T--)
    scanf("%d%d", &x, &y), puts(Query((data){x * 3, y * 3}) ? "YES" : "NO");
}
