#include <bits/stdc++.h>
using namespace std;
const int alpha = 26;
int main() {
  int cnt[alpha] = {0};
  bool last[alpha] = {0};
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int j = s[i] - 'a';
    if (cnt[j] == 0 || last[j] != i % 2) {
      cnt[j]++;
      last[j] = i % 2;
      ans = max(cnt[j], ans);
    }
  }
  cout << ans;
  return 0;
}
