#include <bits/stdc++.h>
using namespace std;
map<int, int> xha, yha;
map<pair<int, int>, int> yox;
int main() {
  ios_base::sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ans += (xha[a]++) + (yha[b]++) - (yox[make_pair(a, b)]++);
  }
  cout << ans << endl;
}
