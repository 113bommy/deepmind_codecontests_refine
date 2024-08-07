#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, hBit = 7;
int n, m, k, p[maxn][hBit];
char line[maxn];
void binary(int n, int* bin) {
  for (int i = 0; n > 0; i++, n >>= 1) bin[i] = n & 1;
}
int main() {
  cin >> n >> m >> k;
  int inf1 = 0, inf2 = 0;
  for (int i = 0, t1, t2; i < n; i++) {
    cin >> line;
    t1 = t2 = -1;
    int hasSpace = 0;
    for (int j = 0; j < m; j++)
      if (line[j] == 'G')
        t1 = j;
      else if (line[j] == 'R')
        t2 = j;
      else
        hasSpace = 1;
    if (t1 >= 0 && t2 == -1 && hasSpace) inf1 = 1;
    if (t1 == -1 && t2 >= 0 && hasSpace) inf2 = 1;
    if (t1 >= 0 && t2 >= 0) binary(abs(t1 - t2) - 1, p[i]);
  }
  if (inf1 || inf2) {
    if (inf1 && inf2) {
      cout << "Draw" << endl;
    } else if (inf1) {
      cout << "First" << endl;
    } else if (inf2) {
      cout << "Second" << endl;
    }
  } else {
    bool f = 0;
    for (int j = 0; j < hBit; j++) {
      int s = 0;
      for (int i = 0; i < n; i++) s += p[i][j];
      if (s % (k + 1) != 0) {
        f = 1;
        break;
      }
    }
    if (f)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
}
