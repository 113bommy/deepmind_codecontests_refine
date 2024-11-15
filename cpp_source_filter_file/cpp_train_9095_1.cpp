#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, javad = 20;
int n, m;
bitset<N> ex, must;
vector<int> v;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, x; i < n; i++) scanf("%d", &x), must[x] = 1;
  for (int i = 1; i <= m; i++) {
    int l = min((int)v.size(), javad);
    for (int j = 0; j < l && v[j] + v[j] <= i; j++)
      if (ex[i - v[j]]) {
        ex[i] = 1;
        break;
      }
    if (!ex[i]) {
      int s = upper_bound(v.begin(), v.end(), i / 2) - v.begin() - 1,
          l = max(javad, s - javad);
      for (int j = s; j > l; j--)
        if (ex[i - v[j]]) {
          ex[i] = 1;
          break;
        }
    }
    if (!must[i] && ex[i]) {
      printf("NO\n");
      return 0;
    }
    if (must[i] && !ex[i]) ex[i] = 1, v.push_back(i);
  }
  printf("YES\n%d\n", (int)v.size());
  for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
  printf("\n");
  return 0;
}
