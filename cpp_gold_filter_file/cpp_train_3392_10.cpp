#include <bits/stdc++.h>
using namespace std;
int n, k, init;
int cnt[50];
long long sz[100010];
long long add[100010];
vector<long long> more;
vector<long long> ans;
bool canAddToPacks(int str) {
  sort(more.begin(), more.end());
  int ptr = 0;
  init = max(str, init);
  for (int i = init; i < k && ptr < more.size(); i++) {
    if (2 * sz[i] > more[ptr] && add[i] == -1) {
      if (init == i) init++;
      add[i] = more[ptr++];
    }
  }
  return ptr == more.size();
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  int p = 0;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    while (num > (1LL << p)) p++;
    if (num == (1LL << p))
      cnt[p]++;
    else
      more.push_back(num);
  }
  for (int i = 0; i < 45; i++) {
    for (int j = 0; j < cnt[i] - cnt[i + 1]; j++) sz[k++] = (1LL << i);
    for (int j = 0; j < cnt[i + 1] - cnt[i]; j++) more.push_back(2LL << i);
    cnt[i + 1] = min(cnt[i + 1], cnt[i]);
  }
  memset(add, -1, sizeof add);
  int idx = 0;
  while (idx < k && canAddToPacks(idx)) {
    ans.push_back(k - idx);
    more.clear();
    if (add[idx] != -1) more.push_back(add[idx]);
    for (long long i = 1; i <= sz[idx]; i *= 2) more.push_back(i);
    idx++;
  }
  if (!ans.empty()) {
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << endl;
  } else
    cout << -1 << endl;
  return 0;
}
