#include <bits/stdc++.h>
long long sum, n;
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    std::cin >> a;
    sum += a * i;
  }
  std::cout << sum << std::endl;
}
