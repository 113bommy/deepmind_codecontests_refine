#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, rank, sol = 1e9, initial_v[N];
pair<int, pair<int, int> > v[N];
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a > b;
}
bool poz_cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.second.second < b.second.second;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second.first;
    v[i].second.second = i;
    initial_v[i] = v[i].first;
  }
  sort(v, v + n, cmp);
  int lim = 1 << n;
  for (int i = 0; i < lim; ++i) {
    sort(v, v + n, poz_cmp);
    int wins = 0, effort = 0;
    for (int j = 0; j < n; ++j) {
      v[j].first = initial_v[j];
      if ((1 << j) & i) {
        wins++;
        effort += v[j].second.first;
      } else
        v[j].first++;
    }
    sort(v, v + n, cmp);
    int rank = n;
    while (rank && wins > v[rank - 1].first) rank--;
    for (int j = 0; j < n; ++j)
      if (wins == v[j].first && (1 << v[j].second.second) & i) rank--;
    if (rank < k) sol = min(sol, effort);
  }
  if (sol == 1e9)
    cout << -1;
  else
    cout << sol;
  return 0;
}
