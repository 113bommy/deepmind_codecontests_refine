#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char ch[n + 5][n + 5];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> ch[i][j];
  for (int i = 0; i < n; i++) {
    int coun = 0;
    for (int j = 0; j < n; j++) {
      if (ch[i][j + 1] == 'o') coun++;
      if (ch[i + 1][j] == 'o') coun++;
      if (ch[i][j - 1] == 'o') coun++;
      if (ch[i - 1][j] == 'o') coun++;
      if (coun % 2 != 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
