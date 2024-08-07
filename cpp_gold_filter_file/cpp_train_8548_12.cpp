#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
int n, k;
string s, t;
ll cnt[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  cin >> s >> t;
  int i = 0;
  while (i < n && s[i] == t[i]) {
    cnt[i]++;
    i++;
  }
  int stop = maxn;
  for (int j = i; j < n; j++) {
    cnt[j]++;
    if (j + 1 < n && s[j + 1] == 'a') {
      for (int k = j + 1; k < min(n, j + 35); k++) {
        cnt[k] += 1LL << (k - (j + 1));
      }
      stop = min(stop, j + 36);
    }
  }
  for (int j = i; j < n; j++) {
    cnt[j]++;
    if (j + 1 < n && t[j + 1] == 'b') {
      for (int k = j + 1; k < min(n, j + 35); k++) {
        cnt[k] += 1LL << (k - (j + 1));
      }
      stop = min(stop, j + 36);
    }
  }
  for (int i = stop; i < n; i++) {
    cnt[i] += 1LL << 32;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min((ll)k, cnt[i]);
  }
  cout << ans << '\n';
}
