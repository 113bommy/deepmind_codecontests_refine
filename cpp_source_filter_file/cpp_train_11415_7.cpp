#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 33;
  vector<long long int> v1;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= x; j++) {
      long long int r = 1;
      bool flag = true;
      long long int endpt = 2000000000;
      for (int k = 0; k < i; k++) {
        r *= 2;
        if (r > endpt) flag = false;
        if (flag == false) break;
      }
      for (int k = 0; k < j; k++) {
        r *= 3;
        if (r > endpt) flag = false;
        if (flag == false) break;
      }
      if (flag) v1.push_back(r);
    }
  }
  sort(v1.begin(), v1.end());
  long long int a, b;
  cin >> a >> b;
  int index1 = -1;
  int index2 = -1;
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] >= a) {
      index1 = i;
      break;
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] > b) {
      index2 = i - 1;
      break;
    }
  }
  int n = v1.size();
  if (index2 == -1 && index1 > 0)
    cout << n - index1 << endl;
  else if (index1 == -1)
    cout << "0";
  else
    cout << index2 - index1 + 1 << endl;
}
