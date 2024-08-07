#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int C3(int n) { return n * (n - 1) * (n - 2) / 6; }
map<int, int> mp;
int n;
int st[N], tri[N], res[N];
int num[N] = {0, 3, 5, 1, 2, 3, 4, 5, 10, 100};
int getsum() {
  int res = 0;
  for (int i = 1; i <= n; i++) res += C3(num[i]);
  return res;
}
int gettrip() {
  int res = 0;
  for (int i = 1; i <= n - 2; i++) res += num[i] * num[i + 1] * num[i + 2];
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i <= 103; i++) mp[C3(i) - C3(i - 1)] = i;
  cin >> n;
  cin >> st[n + 1] >> tri[n + 1];
  for (int i = n; i >= 1; i--) {
    cout << "+ " << (i >= 4 ? i - 1 : (i == 2 ? 2 : 1)) << endl;
    fflush(stdout);
    cin >> st[i] >> tri[i];
  }
  for (int i = 1; i <= n; i++) {
    st[i] -= st[i + 1], tri[i] -= tri[i + 1];
  }
  res[1] = mp[st[1]] - 2;
  res[3] = (tri[1] - tri[3]) - 1;
  res[2] = tri[3] / (res[3] + 1);
  res[4] = (tri[2] - (res[1] + 1) * (res[3] + 1)) / (res[3] + 1) - 1;
  for (int i = 3; i <= n - 2; i++) {
    res[i + 2] = (tri[i + 1] - res[i - 2] * res[i - 1] -
                  (res[i - 1] + (i == 2)) * (res[i + 1] + 1)) /
                     (res[i + 1] + 1) -
                 (i + 2 != n);
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
  cout << endl;
  fflush(stdout);
}
