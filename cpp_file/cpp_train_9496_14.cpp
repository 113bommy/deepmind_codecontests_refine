#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2100;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int t, n, m, k, a[101];
char str[101];
map<string, int> mp;
int main() {
  cin >> n;
  cout << "? 1 " << n << endl;
  for (int i = 0; i < (n + 1) * n / 2; i++) {
    cin >> str;
    sort(str, str + strlen(str));
    mp[str]++;
  }
  if (n == 1) {
    cout << "! " << str << endl;
    return 0;
  }
  cout << "? 2 " << n << endl;
  for (int i = 0; i < (n - 1) * n / 2; i++) {
    cin >> str;
    sort(str, str + strlen(str));
    if (mp[str] == 1) {
      mp.erase(str);
    } else {
      mp[str]--;
    }
  }
  int x;
  for (auto tmp : mp) {
    x = tmp.first.size();
    for (int i = 0; i < x; i++) {
      a[x] += (int)tmp.first[i];
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << char(a[i] - a[i - 1]);
  }
  cout << endl;
  return 0;
}
