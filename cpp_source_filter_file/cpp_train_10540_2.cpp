#include <bits/stdc++.h>
char sr[100010];
char TAB[][3] = {"00", "01", "10", "11"};
int main() {
  int n;
  scanf("%s", sr);
  n = strlen(sr);
  int cnt[3] = {0};
  int ok[4] = {0};
  for (int i = 0; i < n; i++) {
    if (sr[i] == '?')
      cnt[2]++;
    else
      cnt[sr[i] - '0']++;
  }
  int d = cnt[1] - cnt[0];
  int l = d - cnt[2], r = d + cnt[2];
  if (l <= -1) ok[0] = 1;
  if (r >= 2) ok[3] = 1;
  if (l <= 1 && r >= 0) {
    if (sr[n - 1] == '1' || (sr[n - 1] == '?' && l != 1)) {
      ok[1] = 1;
    }
    if (sr[n - 1] == '0' || (sr[n - 1] == '?' && r != 0)) {
      ok[2] = 1;
    }
  }
  for (int i = 0; i < 4; i++)
    if (ok[i]) printf("%s\n", TAB[i]);
  return 0;
}
