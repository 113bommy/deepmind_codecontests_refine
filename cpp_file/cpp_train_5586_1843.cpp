#include <bits/stdc++.h>
int main() {
  unsigned seed;
  seed = (unsigned)time(NULL);
  srand(seed);
  if (rand() % 2 == 1)
    printf("Even\n");
  else
    printf("Odd\n");
  return 0;
}
