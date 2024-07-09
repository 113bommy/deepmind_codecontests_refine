#include <bits/stdc++.h>
using namespace std;
long long toint(vector<int> d, int k) {
  long long ans = 0;
  for (int i = 0, _ = d.size(); i < _; i++) {
    ans += d[i] * (int(pow(10, k - i - 1)));
  }
  return ans;
}
long long solve(vector<int> adj[], int n, int k) {
  long long ans = INT_MAX;
  vector<int> order;
  for (int i = 0, _ = k; i < _; i++) order.push_back(i);
  do {
    vector<int> temp[n];
    for (int i = 0, _ = n; i < _; i++)
      for (int j = 0, _ = k; j < _; j++) temp[i].push_back(adj[i][order[j]]);
    long long b[n];
    for (int i = 0, _ = n; i < _; i++) b[i] = toint(temp[i], k);
    sort(b, b + n);
    ans = min(ans, b[n - 1] - b[0]);
  } while (next_permutation(order.begin(), order.end()));
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  vector<int> adj[n];
  for (int i = 0, _ = n; i < _; i++) {
    cin >> s;
    for (int j = 0, _ = k; j < _; j++) {
      adj[i].push_back(s[j] - '0');
    }
  }
  cout << solve(adj, n, k);
  return 0;
}
