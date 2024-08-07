#include <bits/stdc++.h>
using namespace std;
struct line {
  int l, r, pos, len;
} X[100005], Y[100005];
int n, cnt1, cnt2, R;
void Max(int &a, int b) {
  if (a < b) a = b;
}
template <class T>
inline void read(T &x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T &x, T &y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T &x, T &y, T &z) {
  read(x);
  read(y);
  read(z);
}
bool cmp(line x, line y) { return x.len > y.len; }
int main() {
  read(cnt2, cnt1);
  for (int i = 1; i <= cnt2; ++i) {
    int x, y, le;
    scanf("%d%d%d", &x, &y, &le);
    Y[i].pos = x;
    Y[i].l = y;
    Y[i].r = y + le;
    Y[i].len = le;
  }
  for (int i = 1; i <= cnt1; ++i) {
    int x, y, le;
    scanf("%d%d%d", &x, &y, &le);
    X[i].pos = y;
    X[i].l = x;
    X[i].r = x + le;
    X[i].len = le;
  }
  sort(X + 1, X + cnt1 + 1, cmp);
  sort(Y + 1, Y + cnt2 + 1, cmp);
  cnt1 = min(7000, cnt1), cnt2 = min(7000, cnt2);
  for (int i = 1; i <= cnt1; ++i)
    for (int j = 1; j <= cnt2; ++j) {
      if (X[i].l >= Y[j].pos || X[i].r <= Y[j].pos) continue;
      if (Y[j].l >= X[i].pos || Y[j].r <= X[i].pos) continue;
      int tmp1 = min(Y[j].pos - X[i].l, X[i].r - Y[j].pos),
          tmp2 = min(X[i].pos - Y[j].l, Y[j].r - X[i].pos);
      Max(R, min(tmp1, tmp2));
    }
  printf("%d\n", R);
  return 0;
}
