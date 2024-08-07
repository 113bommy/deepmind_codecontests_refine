#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 100 * 10 + 123;
vector<int> c[maxN];
long long a[maxN];
long long dfs(int node, int parent) {
  if (a[node] == 0) return 0;
  vector<long long> x;
  for (int i = 0; i < (((int)c[node].size())); i++) {
    if (c[node][i] == parent) continue;
    x.push_back(dfs(c[node][i], node));
  }
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());
  int counter = 0;
  a[node]--;
  int val = 1;
  if (parent == -1) {
    val = 0;
    a[node]++;
  }
  for (int i = 0; i < min((long long)x.size(), a[node]); i++) {
    if (x[i] != 0) {
      counter++;
      val += x[i] + 1;
    }
  }
  a[node] -= counter;
  for (int i = 0; i < (((int)c[node].size())); i++) {
    if (c[node][i] == parent) continue;
    long long y = min(a[node], a[c[node][i]]);
    val += 2 * y;
    a[node] -= y;
  }
  return val;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    c[x].push_back(y);
    c[y].push_back(x);
  }
  int s;
  cin >> s;
  s--;
  cout << dfs(s, -1) << endl;
}
