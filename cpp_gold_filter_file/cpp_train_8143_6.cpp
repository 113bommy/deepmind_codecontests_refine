#include <bits/stdc++.h>
int main() {
  char p[101];
  scanf("%s", p);
  int size(0);
  for (size_t i = 0; p[i] != 0; ++i) {
    size *= 16;
    switch (p[i]) {
      case '>':
        size += 8;
        break;
      case '<':
        size += 9;
        break;
      case '+':
        size += 10;
        break;
      case '-':
        size += 11;
        break;
      case '.':
        size += 12;
        break;
      case ',':
        size += 13;
        break;
      case '[':
        size += 14;
        break;
      case ']':
        size += 15;
        break;
      default:
        break;
    }
    size %= 1000003;
  }
  printf("%d\n", size);
  return 0;
}
