#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long int MAX = 1e9 + 7;
void array_show(int *array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%d%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(long long int *array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%lld%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(vector<int> &vec_s, char middle = ' ') {
  for (int i = 0; i < vec_s.size(); i++)
    printf("%d%c", vec_s[i], (i != vec_s.size() - 1 ? middle : '\n'));
}
void array_show(vector<long long int> &vec_s, char middle = ' ') {
  for (int i = 0; i < vec_s.size(); i++)
    printf("%lld%c", vec_s[i], (i != vec_s.size() - 1 ? middle : '\n'));
}
int main() {
  int n, m;
  int i, j, k;
  int a, b, c;
  cin >> n;
  if (n <= 2) {
    cout << 1 << endl;
    return 0;
  }
  a = 4;
  for (i = 0; i < 1000; i++) {
    if (n < a)
      cout << 0 << endl;
    else if (n >= a && n <= a + 2)
      cout << 1 << endl;
    else {
      a = 2 * a + i % 2 + 1;
      continue;
    }
    return 0;
  }
}
