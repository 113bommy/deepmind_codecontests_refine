#include <bits/stdc++.h>
using namespace std;
const int pre[] = {0, 1, 0, 1, 2};
int N, K, A, res;
int grundy(int a) {
  if (K % 2 == 0) {
    if (a == 1) return 1;
    if (a == 2) return 2;
    return (a % 2) ^ 1;
  } else {
    if (a < 5) return pre[a];
    if (a % 2 == 1) return 0;
    return (grundy(a / 2) == 1 ? 2 : 1);
  }
}
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A;
    res ^= grundy(A);
  }
  cout << (res ? "Kevin" : "Nicky") << '\n';
}
