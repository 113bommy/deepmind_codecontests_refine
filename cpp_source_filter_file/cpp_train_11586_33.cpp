#include <bits/stdc++.h>
using namespace std;
const int MAXL = 107;
int a[MAXL];
char s[MAXL];
int n, m, k, cnt;
bool gmove, rmove;
int main() {
  scanf("%d %d %d\n", &n, &m, &k);
  k++;
  cnt = 0;
  gmove = rmove = false;
  for (int i = 0; i < n; i++) {
    gets(s);
    int l = -1, r = -1, c = 0;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'G')
        l = j;
      else if (s[j] == 'R')
        r = j;
      else
        c++;
    }
    if (l != -1 && r != -1) {
      cnt++;
      int x = abs(l - r) - 1;
      for (int j = 0; x; j++) {
        (a[j] += (x % k)) %= k;
        x /= k;
      }
    } else {
      if (c == 0) continue;
      if (l != -1) gmove = true;
      if (r != -1) rmove = true;
    }
  }
  if (cnt == 0) {
    if (gmove && !rmove)
      puts("First");
    else if (!gmove)
      puts("Second");
    else
      puts("Draw");
    return 0;
  }
  bool win = false;
  for (int i = 0; i < MAXL; i++)
    if (a[i]) {
      win = true;
      break;
    }
  if (win && !rmove)
    puts("First");
  else if (!win && !gmove)
    puts("Second");
  else
    puts("Draw");
  return 0;
}
