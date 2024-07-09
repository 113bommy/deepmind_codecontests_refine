#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<string> fi[N], se[N];
int vis[30];
map<string, int> cnt;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "? 1 1" << endl;
    string s;
    cin >> s;
    cout << "! " << s << endl;
    return 0;
  }
  cout << "? 1 " << n << endl;
  for (int i = 0; i < n * (n + 1) / 2; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    fi[s.length()].push_back(s);
    if (s.length() == n) {
      for (int j = 0; j < s.length(); ++j) vis[s[j] - 'a']++;
    }
  }
  cout << "? 2 " << n << endl;
  for (int i = 0; i < (n - 1) * n / 2; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    se[s.length()].push_back(s);
    if (s.length() == n - 1) {
      for (int j = 0; j < n - 1; ++j) vis[s[j] - 'a']--;
    }
  }
  string ans;
  for (int i = 0; i < 26; ++i)
    if (vis[i]) ans += 'a' + i;
  for (int len = 2; len <= n; ++len) {
    cnt.clear();
    for (auto x : se[len]) cnt[x]--;
    int flag = 0;
    for (auto x : fi[len]) {
      if (++cnt[x] == 1) {
        memset(vis, 0, sizeof(vis));
        for (auto c : ans) vis[c - 'a']--;
        for (auto c : x)
          if (++vis[c - 'a'] == 1) {
            ans += c;
            flag = 1;
            break;
          }
        if (flag) break;
      }
    }
  }
  cout << "! " << ans << endl;
  return 0;
}
