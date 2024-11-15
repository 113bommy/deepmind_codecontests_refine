#include <bits/stdc++.h>
using namespace std;
void output(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x == 0) {
    putchar('0');
    return;
  }
  int a[20], num = 0;
  while (x) a[++num] = x % 10, x /= 10;
  while (num > 0) putchar('0' + a[num--]);
}
inline long long myInt() {
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  int flag = 1;
  if (c == '-') flag = -1, c = getchar();
  long long x = 0;
  while (isdigit(c)) {
    x = (x * 10) + (c - '0');
    c = getchar();
  }
  if (flag == -1) return -x;
  return x;
}
const int N = 50005;
struct NODE {
  int x1, y1, x2, y2;
  void div(int x) {
    x1 = (x1 + x - 1) / x;
    y1 = (y1 + x - 1) / x;
    x2 = x2 / x;
    y2 = y2 / x;
  }
};
struct Node {
  int L, R;
  int Len;
  int cover;
};
struct node {
  int x, y1, y2;
  bool bLeft;
  node() {}
  node(int _x, int _y1, int _y2, bool _bLeft) {
    x = _x;
    y1 = _y1;
    y2 = _y2;
    bLeft = _bLeft;
  }
};
node L[N * 2];
Node a[N << 4];
int y[N * 2];
int cmp(node a, node b) { return a.x < b.x; }
void insert(int t, int L, int R) {
  if (L > R) return;
  if (a[t].L == L && a[t].R == R) {
    a[t].Len = y[R + 1] - y[L];
    a[t].cover++;
    return;
  }
  int mid = (a[t].L + a[t].R) >> 1;
  if (R <= mid)
    insert(t * 2, L, R);
  else if (L > mid)
    insert(t * 2 + 1, L, R);
  else {
    insert(t * 2, L, mid);
    insert(t * 2 + 1, mid + 1, R);
  }
  if (a[t].cover == 0) a[t].Len = a[t * 2].Len + a[t * 2 + 1].Len;
}
void del(int t, int L, int R) {
  if (L > R) return;
  if (a[t].L == L && a[t].R == R) {
    a[t].cover--;
    if (a[t].cover == 0) {
      if (a[t].L == a[t].R)
        a[t].Len = 0;
      else
        a[t].Len = a[t * 2].Len + a[t * 2 + 1].Len;
    }
    return;
  }
  int mid = (a[t].L + a[t].R) >> 1;
  if (R <= mid)
    del(t * 2, L, R);
  else if (L > mid)
    del(t * 2 + 1, L, R);
  else {
    del(t * 2, L, mid);
    del(t * 2 + 1, mid + 1, R);
  }
  if (a[t].cover == 0) a[t].Len = a[t * 2].Len + a[t * 2 + 1].Len;
}
void build(int t, int L, int R) {
  a[t].L = L;
  a[t].R = R;
  a[t].cover = a[t].Len = 0;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(t * 2, L, mid);
  build(t * 2 + 1, mid + 1, R);
}
int find(int y[], int n, int val) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (val == y[mid]) return mid;
    if (val > y[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  if (val == y[0]) return 0;
  return n - 1;
}
long long cal_cross_area(NODE p[], int n) {
  if (!n) return 0;
  int i, k;
  int x1, y1, x2, y2;
  for (i = 0; i < n; i++) {
    x1 = p[i].x1;
    y1 = p[i].y1;
    x2 = p[i].x2 + 1;
    y2 = p[i].y2 + 1;
    y[i * 2] = y1;
    y[i * 2 + 1] = y2;
    L[i * 2] = node(x1, y1, y2, true);
    L[i * 2 + 1] = node(x2, y1, y2, false);
  }
  sort(y, y + 2 * n);
  sort(L, L + 2 * n, cmp);
  k = unique(y, y + 2 * n) - y;
  build(1, 0, k - 2);
  long long ans = 0;
  for (i = 0; i < 2 * n - 1; i++) {
    int left = find(y, k, L[i].y1);
    int right = find(y, k, L[i].y2);
    if (L[i].bLeft)
      insert(1, left, right - 1);
    else
      del(1, left, right - 1);
    ans += ((long long)a[1].Len) * (L[i + 1].x - L[i].x);
  }
  return ans;
}
NODE p[N];
NODE pp[N];
int ppNum;
int n, m, K;
void BAOLI() {
  int a[111][111];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < m; i++) {
    for (int x1 = p[i].x1; x1 <= p[i].x2; x1++) {
      for (int y1 = p[i].y1; y1 <= p[i].y2; y1++) {
        a[x1][y1] = 1;
      }
    }
  }
  for (int i = 1; i <= K; i <<= 1) {
    int cnt = 0;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        if (a[x][y] && x % i == 0 && y % i == 0) cnt++;
      }
    }
    printf("%d ", cnt);
  }
  puts("");
}
int main() {
  n = myInt();
  m = myInt();
  K = myInt();
  for (int i = 0; i < m; i++) {
    p[i].x1 = myInt();
    p[i].y1 = myInt();
    p[i].x2 = myInt();
    p[i].y2 = myInt();
  }
  long long cnt[33];
  int kk = 0;
  for (int i = 1; i <= K; i <<= 1, kk++) {
    ppNum = 0;
    for (int j = 0; j < m; j++) {
      if (p[j].x2 < i || p[j].y2 < i) continue;
      pp[ppNum] = p[j];
      pp[ppNum].div(i);
      if (pp[ppNum].x2 < pp[ppNum].x1) continue;
      if (pp[ppNum].y2 < pp[ppNum].y1) continue;
      ppNum++;
    }
    cnt[kk] = cal_cross_area(pp, ppNum);
  }
  cnt[kk++] = 0;
  for (int i = 0; i + 1 < kk; i++)
    if ((cnt[i] - cnt[i + 1]) & 1) {
      puts("Hamed");
      return 0;
    }
  puts("Malek");
}
