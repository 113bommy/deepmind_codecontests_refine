#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> v;
  for (int i = 2; i <= 61; i++) {
    for (int j = 0; j < i - 1; j++) {
      v.push_back((1LL << i) - 1 - (1LL << j));
    }
  }
  sort(v.begin(), v.end());
  long long a, b;
  scanf("%I64d%I64d", &a, &b);
  printf("%d\n", lower_bound(v.begin(), v.end(), b + 1) -
                     lower_bound(v.begin(), v.end(), a));
}
