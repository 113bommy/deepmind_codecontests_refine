#include <bits/stdc++.h>
char c[100];
char s[10][100];
int main() {
  while (gets(c) != NULL) {
    for (int i = 0; i < 10; i++) gets(s[i]);
    for (int i = 0; i < 80; i += 10)
      for (int j = 0; j < 10; j++)
        if (strncpy(c + i, s[j], 10) == 0) {
          printf("%d", j);
          break;
        }
    puts("");
  }
}
