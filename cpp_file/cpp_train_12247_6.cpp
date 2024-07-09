#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, p, x, m, tmp, d;
int a[N], b[N];
string s;
void dfs(int v) {
  if (a[v] != 0) {
    tmp++;
    x = a[v];
    dfs(a[v]);
  }
}
int main() {
  cin >> n >> d;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      for (int j = i + d; j > i; j--) {
        if (s[j] == '1') {
          a[i] = j;
          break;
        }
      }
    }
  }
  dfs(0);
  if (x != n - 1) tmp = -1;
  cout << tmp;
  return 0;
}
