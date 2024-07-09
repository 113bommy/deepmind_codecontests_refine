#include <bits/stdc++.h>
using namespace std;
int arr[25][25] = {0};
int m[6] = {0};
int f[6] = {0};
int n, k, t;
vector<int> v;
void sim(int a, int b, int nilai) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (m[i] == 0 && f[j] == 0 && i > a && arr[i][j] > 0) {
        m[i] = 1;
        f[j] = 1;
        v.push_back(nilai + arr[i][j]);
        sim(i, j, nilai + arr[i][j]);
        m[i] = 0;
        f[j] = 0;
      }
    }
  }
}
int main() {
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) arr[i][j] = -1;
  cin >> n >> k >> t;
  for (int i = 0; i < k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a][b] = c;
  }
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] > 0) {
        m[i] = 1;
        f[j] = 1;
        v.push_back(arr[i][j]);
        sim(i, j, arr[i][j]);
        m[i] = 0;
        f[j] = 0;
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v[min(t - 1, (int)v.size() - 1)] << endl;
  return 0;
}
