#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000")
const int INF = (1e9 + 7);
const long long INFll = (1e18 + 7);
const int N = 300;
const int NM = 100000;
using namespace std;
int n, l[605], r[605];
vector<int> ok, ok2;
string s = "", s2 = "";
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  ok.push_back(1);
  for (int i = n - 1; i >= 0; i--) {
    bool flag = false;
    for (int j = 0; j < ok.size(); j++) {
      if (ok[j] >= l[i] && ok[j] <= r[i]) {
        int ff = ok[j];
        flag = true;
        ok2.push_back(1);
        for (int q = j; q < ok.size(); q++) {
          ok2.push_back(ok[q] + 2);
        }
        ok = ok2;
        ok2.clear();
        s2 = "(";
        for (int q = 0; q < ff - 1; q++) {
          s2.push_back(s[q]);
        }
        s2.push_back(')');
        for (int q = ff - 1; q < s.size(); q++) {
          s2.push_back(s[q]);
        }
        s = s2;
        s2.clear();
        break;
      }
    }
    if (!flag) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  cout << s << '\n';
  return 0;
}
