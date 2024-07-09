#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int INF = 1000000000;
long double sum[26][5107], MAX[26], one[26][5107];
int cnt[26][26][5107];
long double charUsed[26];
long double result = 0;
string str;
int n;
int d[5005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> str;
  n = str.size();
  for (int i = 0; i < n; i++) d[i] = str[i] - 'a';
  for (int i = 0; i < n; i++) {
    charUsed[d[i]]++;
    for (int j = 0; j < i; j++) cnt[d[i]][d[j]][n - i + j]++;
    for (int j = i; j < n; j++) cnt[d[i]][d[j]][j - i]++;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 26; k++) {
        one[i][j] += int(cnt[i][k][j] == 1);
        sum[i][j] += cnt[i][k][j];
      }
      MAX[i] = max(MAX[i], one[i][j] / sum[i][j]);
    }
  }
  for (int i = 0; i < 26; i++) result += charUsed[i] / n * MAX[i];
  cout.precision(6);
  cout << fixed << result << "\n";
  return 0;
}
