#include <bits/stdc++.h>
using namespace std;
char s[42];
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", s);
    int k = strlen(s + 4), year = atoi(s + 4), F = 0, tenPow = 10;
    for (int i = 1; i < k; i++) {
      F += tenPow;
      tenPow *= 10;
    }
    while (year < 1989 + F) year += tenPow;
    printf("%d\n", year);
  }
  return 0;
}
