#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  cout << "+------------------------+" << endl;
  if (k == 0) {
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
    cout << "|#.......................|" << endl;
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    cout << "+------------------------+" << endl;
  } else if (k == 1) {
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
    cout << "|#.......................|" << endl;
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    cout << "+------------------------+" << endl;
  } else if (k == 2) {
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
    cout << "|#.......................|" << endl;
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    cout << "+------------------------+" << endl;
  } else if (k == 3) {
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
    cout << "|O.......................|" << endl;
    cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    cout << "+------------------------+" << endl;
  } else if (k == 4) {
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
    cout << "|O.......................|" << endl;
    cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    cout << "+------------------------+" << endl;
  } else {
    int n = k - 4;
    int m = n / 3;
    int rem = n % 3;
    for (int i = 0; i < 4; i++) {
      if (i == 2) {
        cout << "|O.......................|" << endl;
        continue;
      } else {
        int a = 0;
        cout << "|O.";
        for (int j = 0; j < m; j++) {
          cout << "O.";
        }
        if (i < rem) {
          a = 1;
          cout << "O.";
        }
        for (int j = 0; j < 10 - m - a; j++) {
          cout << "#.";
        }
        if (i == 0)
          cout << "|D|)";
        else if (i == 3)
          cout << "|.|)";
        else
          cout << "|.|";
        cout << endl;
      }
    }
    cout << "+------------------------+" << endl;
  }
  return 0;
}
