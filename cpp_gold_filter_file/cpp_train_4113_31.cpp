#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int> > gr;
int fl[10005];
int main() {
  int n;
  scanf("%d", &n);
  int i, j, x, y;
  for (i = 2; i <= 2 * n; i++)
    for (j = 1; j < i; j++) {
      scanf("%d", &x);
      gr[-x] = make_pair(i, j);
    }
  map<int, pair<int, int> >::iterator I;
  for (I = gr.begin(); I != gr.end(); I++) {
    pair<int, int> cur = I->second;
    x = cur.first;
    y = cur.second;
    if (fl[x] == 0 && fl[y] == 0) {
      fl[x] = y;
      fl[y] = x;
    }
  }
  for (i = 1; i <= 2 * n; i++) printf("%d ", fl[i]);
  return 0;
}
