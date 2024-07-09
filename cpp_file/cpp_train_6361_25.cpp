#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  Solution(int _n) : N(_n) {}
  void guess(long long n, int k) {
    long long l = 1;
    long long r = n;
    int M = min(4LL * k, n);
    mt19937_64 gen(clock());
    string ans;
    for (int i = 0; i < N; ++i) {
      if (r - l + 1 <= M) {
        uniform_int_distribution<long long> dist(l, r);
        long long p = dist(gen);
        cout << p << " " << p << endl;
        fflush(stdout);
        cin >> ans;
        if (ans[0] == 'y' || ans[0] == 'Y') {
          return;
        }
      } else {
        long long m = l + (r - l) / 2;
        cout << l << " " << m << endl;
        fflush(stdout);
        cin >> ans;
        if (ans[0] == 'y' || ans[0] == 'Y') {
          r = m;
        } else {
          l = m + 1;
        }
      }
      l = max(1LL, l - k);
      r = min(n, r + k);
    }
  }

 private:
  int N;
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  int k;
  long long p;
  cin >> n >> k;
  Solution sol(4500);
  sol.guess(n, k);
  return 0;
}
