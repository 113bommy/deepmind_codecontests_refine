#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s[41] = {
      " ",        "Washington", "Adams",     "Jefferson", "Madison",
      "Monroe",   "Adams",      "Jackson",   "Van Buren", "Harrison",
      "Tyler",    "Polk",       "Taylor",    "Fillmore",  "Pierce",
      "Buchanan", "Lincoln",    "Johnson",   "Grant",     "Hayes",
      "Garfield", "Arthur",     "Cleveland", "Harrison",  "Clevelan",
      "McKinley", "Roosevelt",  "Taft",      "Wilson",    "Harding",
      "Coolidge", "Hoover",     "Roosevelt", "Truman",    "Eisenhower",
      "Kennedy",  "Johnson",    "Nixon",     "Ford",      "Carter",
      "Reagan"};
  cout << s[n];
}
