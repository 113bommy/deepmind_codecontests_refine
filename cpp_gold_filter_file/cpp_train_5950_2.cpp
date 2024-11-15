#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
  bool operator<(const node &A) const {
    if (x == A.x) return y < A.y;
    return x < A.x;
  }
} a[100005], b[100005], Q[100005];
int n, N;
bool cmp(node &A, node &B, node &C) {
  return (A.y - B.y) * (B.x - C.x) >= (B.y - C.y) * (A.x - B.x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1);
  int now = 1;
  while (now <= n) {
    while (now + 1 <= n && a[now + 1].x == a[now].x) now++;
    b[++N] = a[now];
    b[N].y -= b[N].x * b[N].x;
    now++;
  }
  now = 0;
  for (int i = 1; i <= N; ++i) {
    while (now > 1 && cmp(b[i], Q[now], Q[now - 1])) now--;
    Q[++now] = b[i];
  }
  printf("%d\n", now - 1);
}
