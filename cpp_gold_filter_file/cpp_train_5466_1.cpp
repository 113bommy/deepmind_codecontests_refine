#include <bits/stdc++.h>
using namespace std;
string s[10000];
int u[10000];
int main() {
  ios::sync_with_stdio(false);
  int n, c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    c += s[i].size();
  }
  c += n / 2;
  char d;
  cin >> d;
  sort(s, s + n);
  int l = c / (n / 2);
  vector<string> res;
  for (int i = 0; i < n; i++)
    if (!u[i])
      for (int j = i + 1; j < n; j++)
        if (!u[j] && s[j].size() == (l - s[i].size() - 1)) {
          string x = s[i] + d + s[j], y = s[j] + d + s[i];
          if (x < y)
            res.push_back(x);
          else
            res.push_back(y);
          u[i] = u[j] = 1;
          break;
        }
  sort(res.begin(), res.end());
  for (unsigned int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
