#include <bits/stdc++.h>
using namespace std;
int n, s, x, y, i, cnt, mem;
int tab[3][100001];
char znak;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for (int a = 1; a <= n; a++) {
    cin >> znak >> x >> y;
    if (znak == 'B')
      i = 1;
    else
      i = 2;
    tab[i][x] += y;
  }
  for (int a = 1; a <= 100000; a++) {
    if (tab[2][a] && cnt < s) {
      mem = a;
      cnt++;
    }
  }
  for (; mem >= 1; mem--) {
    if (tab[2][mem]) cout << "S " << mem << " " << tab[2][mem] << endl;
  }
  cnt = 0;
  for (int a = 100000; a >= 1; a--) {
    if (tab[1][a] && cnt < s) {
      cout << "B " << a << " " << tab[1][a] << endl;
      cnt++;
    }
  }
}
