#include <bits/stdc++.h>
using namespace std;
int n;
int ans[1001];
string st;
int main() {
  cin >> n;
  cin >> st;
  for (int i = 0; i < n; i++) ans[i] = 1;
  for (int i = 1; i < n; i++)
    if (st[i - 1] != 'L') ans[i] = ans[i - 1] + st[i - 1] == 'R';
  for (int i = n - 2; i >= 0; i--)
    if (st[i] != 'R')
      if (ans[i] < ans[i + 1] + st[i] == 'L')
        ans[i] = ans[i + 1] + st[i] == 'L';
  cout << ans[0];
  for (int i = 1; i < n; i++) cout << " " << ans[i];
  cout << endl;
}
