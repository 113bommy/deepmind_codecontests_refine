#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool f(long long a, long long b) {
  if (!a) return 0;
  return !(f(b % a, b) && (b / a % (a + 1) % 2));
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    if (a > b) a ^= b, b ^= a, a ^= b;
    puts(f(a, b) ? "First" : "Second");
  }
  return 0;
}
