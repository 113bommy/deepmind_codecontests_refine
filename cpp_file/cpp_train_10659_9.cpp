#include <bits/stdc++.h>
using namespace std;
int a[200000];
int dp[20000];
vector<int> v[200000];
int main() {
  int n, k, i, cur;
  cin >> n >> k;
  vector<int> st;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0)
      st.push_back(i);
    else
      v[a[i]].push_back(i);
  }
  int loc = 0;
  vector<int> aa;
  for (i = 0; i < st.size(); i++) {
    int cnt = 1;
    cur = st[i];
    int fl = 0;
    if (cur == k) {
      fl = 1;
      loc = 1;
    }
    while (v[cur].size() > 0) {
      cnt++;
      cur = v[cur][0];
      if (cur == k) {
        loc = cnt;
        fl = 1;
      }
    }
    if (fl == 0) aa.push_back(cnt);
  }
  sort(aa.begin(), aa.end());
  dp[0] = 1;
  int j;
  for (i = aa.size() - 1; i >= 0; i--) {
    for (j = 1000; j >= 0; j--) {
      dp[j + aa[i]] += dp[j];
    }
  }
  for (i = 0; i <= 1000; i++) {
    if (dp[i] > 0 && i + loc <= n) cout << i + loc << endl;
  }
  return 0;
}
