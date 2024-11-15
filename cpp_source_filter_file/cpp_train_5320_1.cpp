#include <bits/stdc++.h>
using namespace std;
const int N = 15000005;
int a[N];
bool pr[N];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int G = v[0];
  for (int i = 1; i < n; i++) G = gcd(G, v[i]);
  for (int i = 0; i < n; i++) v[i] /= G;
  for (int i = 0; i < n; i++) a[v[i]]++;
  int ans = n;
  for (int i = 2; i < N; i++) {
    int del = 0;
    if (pr[i]) continue;
    for (int j = i; j < N / 2; j += i) {
      del += a[j];
      if (j != i) pr[j] = true;
    }
    if (n - del < ans) {
      ans = n - del;
    }
  }
  if (ans == n)
    cout << -1;
  else
    cout << ans;
}
