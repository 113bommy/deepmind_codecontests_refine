#include <bits/stdc++.h>
using namespace std;
int mod(int n) { return n % 4; }
int main() {
  vector<int> v(4);
  for (int i = 0; i < 4; i++) {
    cin >> v[i];
  }
  while (1) {
    if (v[0] == 1 && v[1] == 1 && v[2] == 1 && v[3] == 1) break;
    int max = 0;
    int pos = 0;
    for (int i = 0; i < 4; i++) {
      if (max < v[i]) {
        max = v[i];
        pos = i;
      }
    }
    bool flag = false;
    if (max % 2 == 0) {
      if (v[mod(pos + 1)] % 2 == 0) {
        v[pos] /= 2;
        v[mod(pos + 1)] /= 2;
        cout << "/" << pos + 1 << endl;
        flag = true;
      } else if (v[mod(pos - 1)] % 2 == 0) {
        v[pos] /= 2;
        v[mod(pos - 1)] /= 2;
        cout << "/" << mod(pos - 1) + 1 << endl;
        flag = true;
      }
    } else {
      if (v[mod(pos + 1)] % 2 == 1) {
        v[pos]++;
        v[mod(pos + 1)]++;
        cout << "+" << pos + 1 << endl;
        flag = true;
      }
      if (v[mod(pos - 1) % 2] == 1) {
        v[pos]++;
        v[mod(pos - 1)]++;
        cout << "+" << mod(pos - 1) + 1 << endl;
        flag = true;
      }
    }
    if (!flag) {
      v[pos]++;
      v[mod(pos - 1)]++;
      cout << "+" << mod(pos - 1) + 1 << endl;
    }
  }
  return 0;
}
