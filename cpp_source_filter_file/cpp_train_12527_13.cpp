#include <bits/stdc++.h>
using namespace std;
char s[500005];
vector<int> p;
int main() {
  int ch;
  int i = 0;
  while ((ch = getchar()) != '\n') {
    s[i] = ch;
    if (s[i] == '.') p.push_back(i);
    i++;
  }
  int n = i;
  if (p.size() == 0) {
    cout << "NO\n";
    return 0;
  }
  if (p[0] == 0 || p[0] > 8) {
    cout << "NO\n";
    return 0;
  }
  if (p[p.size() - 1] == n - 1 || p[p.size() - 1] < n - 4) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < (int)p.size() - 1; i++)
    if (p[i + 1] - p[i] < 3 || p[i + 1] - p[i] > 11) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  for (int j = 0; j <= p[0]; j++) putchar(s[j]);
  i = 0;
  int k = p[0] + 1;
  while (i < (int)p.size() - 1) {
    int f = k + min(p[i + 1] - p[i] - 2, 3);
    for (; k < f; k++) putchar(s[k]);
    putchar('\n');
    for (; k <= p[i + 1]; k++) putchar(s[k]);
    i++;
  }
  for (; k < n; k++) putchar(s[k]);
  putchar('\n');
  return 0;
}
