#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if ((n - 2) % 2 == 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
}
