#include <bits/stdc++.h>
using namespace std;
int main() {
  puts("2000");
  int n = 1000;
  for (int i = 1; i <= n; i++) printf("%d %d %d %d\n", i, 1, i, 2);
  for (int i = n; i >= 1; i--) printf("%d %d %d %d\n", i, 1, i, 2);
  return 0;
}
