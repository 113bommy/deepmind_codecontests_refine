#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char s[10], t[10];
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  a[0] = 0;
  bool no = false;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    int l = strlen(s);
    int id = find(s, s + l, '?') - s;
    while (id < l) {
      for (int d = !id; d < 10; ++d) {
        strcpy(t, s);
        t[id] = d + '0';
        for (int j = id + 1; t[j]; ++j) {
          if (t[j] == '?') t[j] = '9';
        }
        int q;
        sscanf(t, "%d", &q);
        if (q > a[i - 1]) {
          s[id] = d + '0';
          break;
        }
      }
      int nid = find(s, s + l, '?') - s;
      if (nid == id) break;
      id = nid;
    }
    if (find(s, s + l, '?') - s < n) {
      no = true;
      break;
    }
    sscanf(s, "%d", a + i);
    if (a[i] <= a[i - 1]) {
      no = true;
      break;
    }
  }
  if (no)
    puts("NO");
  else {
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d\n", a[i]);
  }
  return 0;
}
