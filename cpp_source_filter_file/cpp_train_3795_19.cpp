#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c = n - 2;
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = n / 2; j >= i + 1; j--) {
      cout << "*";
    }
    for (int j = 1; j <= i * 2 + 1; j++) {
      cout << "D";
    }
    for (int j = n / 2; j >= i + 1; j--) {
      cout << "*";
    }
    cout;
  }
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    for (int j = 1; j <= c; j++) {
      cout << "D";
    }
    c = c - 2;
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}
