#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 1) n++;
  printf("%d\n", (n / 2) - 1);
  return 0;
}
