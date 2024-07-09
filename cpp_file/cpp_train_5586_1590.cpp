#include <bits/stdc++.h>
int main() {
  srand((unsigned)time(0));
  int n;
  scanf("%d", &n);
  if (rand() % 2)
    puts("Odd");
  else
    puts("Even");
}
