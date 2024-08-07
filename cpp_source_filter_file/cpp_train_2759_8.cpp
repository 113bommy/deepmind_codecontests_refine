#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)5e6 + 3;
int n, k;
vector<int> decompose(const string &s, bool special = false) {
  vector<int> ret;
  for (int i = n - 1; i >= 0;) {
    int k = i;
    int j = i - 1;
    while (j >= 0 && s[j] >= s[k]) {
      if (s[j] > s[k])
        k = i;
      else
        k--;
      j--;
    }
    if (special) {
      if (j == -1)
        ret.push_back(i);
      else
        ret.clear();
    } else
      ret.push_back(i);
    while (i >= k) {
      i -= k - j;
      if (special && i >= k && j == -1) ret.push_back(i);
    }
  }
  return ret;
}
vector<int> z_function(string s) {
  vector<int> z(n << 1);
  s += s;
  reverse(s.begin(), s.begin() + n);
  int l = 0, r = 0;
  for (int i = 1; i < n << 1; i++) {
    if (i > r) {
      l = r = i;
      while (r < (n << 1) && s[r] == s[r - l]) r++;
      z[i] = r - l;
      r--;
    } else {
      if (i + z[i - l] - 1 < r)
        z[i] = z[i - l];
      else {
        l = i;
        while (r < (n << 1) && s[r] == s[r - l]) r++;
        z[i] = r - l;
        r--;
      }
    }
  }
  return z;
}
string solve(string s) {
  vector<int> z = z_function(s);
  int j = 0;
  char ci, cj;
  for (int i = 1; i + 1 < n; i++) {
    int k = j + 1;
    k = min(k + z[j + n + 1], i);
    cj = s[n - (k - j)];
    ci = s[k];
    if (ci != cj) {
      if (ci < cj) j = i;
      continue;
    }
    assert(k == i);
    k++;
    k = min(k + z[i - j], n - 1);
    cj = s[n - (k - j)];
    ci = s[n - (k - i)];
    if (ci != cj) {
      if (ci < cj) j = i;
      continue;
    }
    assert(k == n - 1);
  }
  reverse(s.begin() + j + 1, s.end());
  return s;
}
string solve2(string s) {
  s += s;
  int i = 0;
  while (i < n) {
    int k = i;
    int j = i + 1;
    while (j < (n << 1) && s[j] >= s[k]) {
      if (s[j] > s[k])
        k = i;
      else
        k++;
      j++;
    }
    if (k + 1 >= n) break;
    i = k + 1;
  }
  return s.substr(i, n);
}
string solve3(string s) {
  vector<int> a = decompose(s, true);
  reverse(a.begin(), a.end());
  vector<int>::iterator iter = a.begin() + 1;
  for (; iter != a.end(); iter++) {
    int i = *iter;
    int j = *(iter - 1);
    bool ok = true;
    for (int p = j + 1, q = i - j - i; p <= i; p++, q--)
      if (s[p] != s[q]) {
        if (s[p] < s[q]) ok = false;
        break;
      }
    if (!ok) break;
  }
  iter--;
  reverse(s.begin(), s.begin() + *iter + 1);
  return s;
}
void p(vector<int>::iterator iter) { fprintf(stderr, "iter: %d\n", *iter); }
void p(const vector<int> &v) {
  for (int i = 0, _i = (int)v.size(); i < _i; i++) fprintf(stderr, "%d ", v[i]);
  fprintf(stderr, "\n");
}
int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  n = (int)s.size();
  cin >> k;
  vector<int> split = decompose(s);
  string answer;
  int i = 0;
  bool lastSymmetry = false;
  while (k > 0 && !split.empty()) {
    int j = split.back() + 1;
    string t = s.substr(i, j - i);
    string t2 = t;
    reverse(t.begin(), t.end());
    bool symmetry = t2 == t;
    bool ok = false;
    if (lastSymmetry && symmetry)
      ok = true;
    else if (k > 2) {
      ok = true;
      k--;
    }
    if (!ok) break;
    split.pop_back();
    answer += t;
    i = j;
    lastSymmetry = symmetry;
  }
  s.erase(0, i);
  n = (int)s.size();
  if (n > 1) {
    string t = s;
    if (k == 2) t = min(t, solve(s));
    if (k == 2) t = min(t, solve3(s));
    reverse(s.begin(), s.end());
    t = min(t, s);
    if (k == 2) t = min(t, solve2(s));
    answer += t;
  } else
    answer += s;
  cout << answer << endl;
  return 0;
}
