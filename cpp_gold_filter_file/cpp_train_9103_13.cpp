#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
void open() {
  freopen("goal.in", "r", stdin);
  freopen("goal.out", "w", stdout);
}
class Gauss {
 public:
  int a[MAXN], b[MAXN], n;
  vector<pair<int, int> > ops[2];
  void work() {
    cin >> n;
    bool fail = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) scanf("%d", b + i);
    elimination(a, ops[0]);
    elimination(b, ops[1]);
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) break;
      int k = 1 << 30;
      while (!(a[i] & k)) k >>= 1;
      for (int j = 1; j <= min(n, 31); ++j)
        if ((a[j] ^ b[j]) & k) opera(a, j, i, ops[0]);
    }
    for (int i = 1; i <= n; ++i)
      if (a[i] != b[i]) fail = 1;
    if (fail)
      cout << -1 << endl;
    else {
      cout << ops[0].size() + ops[1].size() << endl;
      for (int i = 0; i < ops[0].size(); ++i)
        printf("%d %d\n", ops[0][i].first, ops[0][i].second);
      for (int i = ops[1].size() - 1; i >= 0; --i)
        printf("%d %d\n", ops[1][i].first, ops[1][i].second);
    }
  }

 private:
  void opera(int *x, int i, int j, vector<pair<int, int> > &g) {
    x[i] ^= x[j];
    g.push_back(make_pair(i, j));
  }
  void swap(int *x, int i, int j, vector<pair<int, int> > &g) {
    x[i] ^= x[j];
    x[j] ^= x[i];
    x[i] ^= x[j];
    g.push_back(make_pair(i, j));
    g.push_back(make_pair(j, i));
    g.push_back(make_pair(i, j));
  }
  void elimination(int *x, vector<pair<int, int> > &g) {
    int r = 1;
    for (int i = 30; i >= 0; --i) {
      for (int j = r; j <= n; ++j)
        if (x[j] & (1 << i)) {
          if (j != r) {
            swap(x, r, j, g);
          }
          for (int k = 1; k <= n; ++k) {
            if (k != r && (x[k] & (1 << i))) opera(x, k, r, g);
          }
          ++r;
          break;
        }
    }
  }
} newton;
int main() { newton.work(); }
