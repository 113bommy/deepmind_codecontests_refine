#include <bits/stdc++.h>
int knt[5], n, i;
char A[58000];
int main() {
  scanf("%s", A);
  n = strlen(A);
  for (i = 0; i < n; i++) {
    if (isupper(A[i])) knt[1] = 1;
    if (islower(A[i])) knt[2] = 1;
    if (A[i] >= '0' && A[i] <= '9') knt[3] = 1;
  }
  if (knt[1] + knt[2] + knt[3] == 3)
    puts("Correct");
  else
    puts("Too weak");
}
