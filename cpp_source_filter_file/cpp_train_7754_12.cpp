#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & n - 1)
    puts("YES");
  else
    puts("NO");
  return 0;
}
