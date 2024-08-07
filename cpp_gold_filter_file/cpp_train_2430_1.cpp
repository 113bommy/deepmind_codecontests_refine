#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
string B, N;
long long b, pw[10], C;
int main() {
  ios::sync_with_stdio(false);
  cin >> B >> N >> C;
  int it = N.size();
  for (int i = N.size() - 1; i >= 0; i--) {
    N[i]--;
    if (N[i] < '0')
      N[i] = '9';
    else
      break;
  }
  b = 0;
  for (int i = 0; i < B.size(); i++) b = (b * 10 + B[i] - '0') % C;
  pw[0] = 1;
  for (int i = 1; i < 10; i++) pw[i] = pw[i - 1] * b % C;
  long long ans = 1;
  for (int i = 0; i < N.size(); i++) {
    ans = ans * ans % C;
    long long tmp = ans;
    ans = ans * ans % C;
    ans = ans * ans % C;
    ans = ans * tmp % C;
    ans = ans * pw[N[i] - '0'] % C;
  }
  ans = ans * (b - 1 + C) % C;
  if (ans == 0)
    cout << C << endl;
  else
    cout << ans << endl;
  return 0;
}
