#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%d\n", ((a & b) | (c | d)) ^ ((c & b) | (a | d)));
  return 0;
}
