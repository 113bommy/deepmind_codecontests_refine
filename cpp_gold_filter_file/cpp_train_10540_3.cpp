#include <bits/stdc++.h>
using namespace std;
char s[110000];
int main() {
  while (gets(s)) {
    int N = strlen(s), a = 0, b = 0, i;
    for (i = 0; s[i]; i++) {
      if (s[i] == '1') ++a;
      if (s[i] == '0') ++b;
    }
    if (a <= (N - 1) / 2) puts("00");
    if (s[N - 1] == '1' && b <= N / 2 && a <= (N + 1) / 2 ||
        s[N - 1] == '?' && b <= N / 2 && a <= (N + 1) / 2 - 1)
      puts("01");
    if (s[N - 1] == '0' && b <= N / 2 && a <= (N + 1) / 2 ||
        s[N - 1] == '?' && b <= N / 2 - 1 && a <= (N + 1) / 2)
      puts("10");
    if (b <= (N - 2) / 2) puts("11");
  }
}
