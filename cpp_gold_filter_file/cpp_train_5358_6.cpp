#include <bits/stdc++.h>
int i, A, B, N;
int main() {
  scanf("%d", &A);
  scanf("%d", &B);
  N = A + B + 1;
  for (i = 1; i <= A; i++) printf("%d ", i);
  printf("%d ", N);
  for (i = 1; i <= B; i++) printf("%d ", N - i);
  return 0;
}
