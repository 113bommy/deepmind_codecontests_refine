#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int s[2] = {0, 0};
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char e;
    cin >> e;
    s[(e + i) % 2]++;
  }
  printf("%d\n", s[0] > s[1] ? s[1] : s[0]);
  return 0;
}
