#include <bits/stdc++.h>
using namespace std;
int arr[110][110];
int main() {
  string f, m, s;
  cin >> f >> m >> s;
  if (f == "paper" && m == "rock" && s == m)
    cout << "F" << endl;
  else if (f == "rock" && m == "scissors" && s == m)
    cout << "F" << endl;
  else if (f == "scissors" && m == "paper" && s == m)
    cout << "F" << endl;
  else if (m == "paper" && f == "rock" && s == f)
    cout << "M" << endl;
  else if (m == "rock" && f == "scissors" && s == f)
    cout << "M" << endl;
  else if (m == "scissors" && f == "paper" && s == f)
    cout << "M" << endl;
  else if (s == "paper" && m == "rock" && f == m)
    cout << "S" << endl;
  else if (s == "rock" && m == "scissors" && f == m)
    cout << "S" << endl;
  else if (s == "scissors" && m == "paper" && f == m)
    cout << "S" << endl;
  else
    cout << "?" << endl;
}
