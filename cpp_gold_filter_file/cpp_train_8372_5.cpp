#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int p(char c) {
  if (c >= 'a' && c <= 'z') return 1;
  if (c >= 'A' && c <= 'Z') return 1;
  return 0;
}
int main() {
  scanf("%s", a);
  int n = strlen(a);
  long long m = 0;
  for (int i = 0; i < n; i++) {
    long long x = 0, y = 0;
    if (a[i] == '@') {
      for (int j = i - 1; j >= 0; j--) {
        if (a[j] == '@' || a[j] == '.') break;
        if (p(a[j])) x++;
      }
      for (int j = i + 1; j < n; j++) {
        if (a[j] == '@' || a[j] == '_') {
          i = j - 1;
          break;
        }
        if (a[j] == '.') {
          if (j - i == 1) break;
          for (j++; j < n; j++) {
            if (!p(a[j])) break;
            y++;
          }
          i = j - 1;
          break;
        }
      }
    }
    m += x * y;
  }
  printf("%lld\n", m);
  return 0;
}
