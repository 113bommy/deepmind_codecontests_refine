#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[110][26];
int main() {
  int i, j, k;
  scanf("%d", &n);
  printf("? 1 %d\n", n);
  string s;
  for (i = 1; i <= (1 + n) * n / 2; i++) {
    cin >> s;
    for (auto c : s) cnt[s.length()][c - 'a']++;
  }
  if (n == 1) cout << "! " << s << endl;
  printf("? 2 %d\n", n);
  for (i = 1; i <= (n - 1) * n / 2; i++) {
    cin >> s;
    for (auto c : s) cnt[s.length()][c - 'a']--;
  }
  string ans = "";
  for (i = 1; i <= n; i++) {
    for (j = 0; j < 26; j++) {
      if (cnt[i][j]) {
        ans += 'a' + j;
        break;
      }
    }
    for (k = i + 1; k <= n; k++) cnt[k][j]--;
  }
  cout << "! " << ans << endl;
  return 0;
}
