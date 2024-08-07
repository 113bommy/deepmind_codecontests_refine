#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
string str;
int n, cnt[10] = {};
int main() {
  cin >> str;
  n = str.size();
  for (int i = 0; i < n; i++) cnt[str[i] - '0']++;
  string ans1, ans2;
  int out = 0;
  for (int digit = 1; digit < 10; digit++) {
    int cnt1[10], cnt2[10];
    for (int i = 0; i < 10; i++) cnt1[i] = cnt2[i] = cnt[i];
    string s1, s2;
    int sz = -1;
    if (cnt1[digit] > 0 && cnt2[10 - digit] > 0) {
      ++sz;
      s1.push_back('0' + digit);
      s2.push_back('0' + 10 - digit);
      cnt1[digit]--;
      cnt2[10 - digit]--;
      for (int i = 0; i < 10; i++) {
        int tmp = min(cnt1[i], cnt2[9 - i]);
        s1 += string(tmp, '0' + i);
        s2 += string(tmp, '0' + 9 - i);
        sz += tmp;
        cnt1[i] -= tmp;
        cnt2[9 - i] -= tmp;
      }
    }
    int tmp = min(cnt1[0], cnt2[0]);
    s1 = string(tmp, '0') + s1;
    s2 = string(tmp, '0') + s2;
    sz += tmp;
    cnt1[0] -= tmp;
    cnt2[0] -= tmp;
    for (int i = 0; i < 10; i++) {
      s1 += string(cnt1[i], '0' + i);
      s2 += string(cnt2[i], '0' + i);
    }
    if (out < sz) {
      out = sz;
      ans1 = s1;
      ans2 = s2;
    }
  }
  cerr << out << '\n';
  reverse(ans1.begin(), ans1.end());
  reverse(ans2.begin(), ans2.end());
  cout << ans1 << '\n';
  cout << ans2 << '\n';
  return 0;
}
