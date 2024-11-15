#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  for (auto e : v) {
    s << e << " ";
  }
  return s;
}
int main(int argc, char const* argv[]) {
  bool trace = false;
  int count;
  cin >> count;
  vector<int> vi;
  for (int i = 0; i < count; ++i) {
    int num;
    cin >> num;
    vi.push_back(num);
  }
  int actions_count = 0;
  bool list_view = true;
  bool delayed_out = false;
  for (int i = 0; i < vi.size(); ++i) {
    if (trace) cout << "i: " << i << ", vi[i]: " << vi[i] << endl;
    if (!vi[i]) {
      if (!list_view) delayed_out = true;
      continue;
    }
    if (delayed_out) {
      if (trace) cout << "delayed out" << endl;
      actions_count++;
      list_view = true;
      delayed_out = false;
    }
    if (list_view) {
      list_view = false;
      actions_count++;
      if (trace) cout << "in" << endl;
      if (i < vi.size() && vi[i + 1]) {
        actions_count++;
        if (trace) cout << "left" << endl;
      }
    } else {
      if (i < vi.size() && vi[i + 1]) {
        actions_count++;
        if (trace) cout << "left" << endl;
      }
    }
  }
  cout << actions_count << endl;
  return 0;
}
