#include <bits/stdc++.h>
using namespace std;
int chk(int len, int k, string &s) {
  for (int i = 0; i < s.size(); i++) {
    --k;
    int last = min((int)s.size() - 1, i + len - 1);
    if (last != s.size() - 1)
      while (last >= i && s[last] != '-') --last;
    if (last < i || k < 0) return 0;
    i = last;
  }
  return k >= 0;
}
int main() {
  string s;
  int k;
  cin >> k;
  getchar();
  getline(cin, s);
  for (auto &ch : s)
    if (ch == ' ') ch = '-';
  int l = 1, r = s.size() - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (chk(mid, k, s))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  cout << ans << endl;
}
