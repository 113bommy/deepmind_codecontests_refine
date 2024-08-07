#include <bits/stdc++.h>
using namespace std;
int finished[200010];
const int INF = 1e9;
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i <= 200000; i++) finished[i] = INF;
  vector<tuple<int, int, int>> foo;
  vector<tuple<int, int, int>> events;
  for (int i = 0; i < n; i++) {
    int l, r, cost;
    cin >> l >> r >> cost;
    foo.push_back({l, r, cost});
    events.push_back({l, -1, foo.size() - 1});
    events.push_back({r, 1, foo.size() - 1});
  }
  sort(events.begin(), events.end());
  int ans = INF;
  for (auto &evt : events) {
    auto &voucher = foo[get<2>(evt)];
    int dur = get<1>(voucher) - get<0>(voucher) + 1;
    int cost = get<2>(voucher);
    if (x - dur < 0) continue;
    if (get<1>(evt) == -1) {
      if (finished[x - dur] != INF) {
        ans = min(finished[x - dur] + cost, ans);
      }
    } else {
      finished[dur] = min(finished[dur], cost);
    }
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
