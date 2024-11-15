#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000010;
int n;
int a[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i + n] = a[i];
  }
  long long cur = 0;
  priority_queue<int, vector<int>, greater<int> > Q;
  long long cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < i) {
      cur += i - a[i];
      cnt++;
      Q.push(i - a[i]);
    } else {
      cur += a[i] - i;
    }
  }
  long long ans = cur, pos = n;
  for (int i = n + 1; i < n + n; ++i) {
    cur = cur - cnt + (n - cnt);
    cur -= a[i - n];
    while (!Q.empty() && Q.top() == i - n) {
      --cnt;
      Q.pop();
    }
    if (a[i] < n) {
      cur += n - a[i];
      cnt++;
      Q.push(i - a[i]);
    } else {
      cur += a[i] - n;
    }
    if (cur < ans) {
      ans = cur;
      pos = i;
    }
  }
  if (pos == n)
    pos = 0;
  else
    pos = n - (pos - n);
  cout << ans << " " << pos << endl;
  return 0;
}
