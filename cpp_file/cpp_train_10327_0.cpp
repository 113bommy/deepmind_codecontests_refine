#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int dp[100089];
bool cmp(int a, int b) { return a > b; }
int main() {
  string c, d;
  int a;
  cin >> a;
  while (a--) {
    int n, flag = 0;
    cin >> n;
    cin >> c >> d;
    vector<int> df;
    for (int i = 0; i < n; i++) {
      if (c[i] != d[i]) df.push_back(i);
      if (df.size() > 2) {
        flag = 1;
        break;
      }
    }
    if (!flag && df.size() == 2) {
      if (c[df[0]] != c[df[1]] || d[df[0]] != d[df[1]]) flag = 1;
    }
    if (df.size() != 2) flag = 1;
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
