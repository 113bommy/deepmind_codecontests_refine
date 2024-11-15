#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto v : vec) os << v << ", ";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ", ";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ", ";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ", ";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ", ";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ", ";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << "(" << pa.first << ", " << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << "{";
  for (auto v : mp) os << v.first << ": " << v.second << ", ";
  os << "}";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) {
  os << "{";
  for (auto v : mp) os << v.first << ": " << v.second << ", ";
  os << "}";
  return os;
}
template <typename T>
void ndarray(vector<T> &vec, int len) {
  vec.resize(len);
}
template <typename T, typename... Args>
void ndarray(vector<T> &vec, int len, Args... args) {
  vec.resize(len);
  for (auto &v : vec) ndarray(v, args...);
}
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (q < m) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int len, shows, target;
    cin >> len >> shows >> target;
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
      cin >> arr[i];
    }
    map<int, int> m;
    for (int i = 0; i < target; i++) m[arr[i]]++;
    int small = m.size();
    for (int i = 1; i <= len - target; i++) {
      if (m[arr[i - 1]] == 1) {
        m.erase(arr[i - 1]);
      } else {
        m[arr[i - 1]] -= 1;
      }
      m[arr[i + target - 1]]++;
      if (m.size() < small) small = m.size();
    }
    cout << small << endl;
  }
}
