#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long int mod = 1000000007;
const long long int inf = 2.19e15 + 1;
const long double pai = 3.141592653589793238462643383279502884197;
const long double eps = 1e-10;
template <class T, class U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T, class U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
long long int gcd(long long int a, long long int b) {
  if (a % b == 0) {
    return b;
  } else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  return a / gcd(a, b) * b;
}
template <class T>
void SO(T& ve) {
  sort(ve.begin(), ve.end());
}
template <class T>
void REV(T& ve) {
  reverse(ve.begin(), ve.end());
}
template <class T>
long long int LBI(const vector<T>& ar, T in) {
  return lower_bound(ar.begin(), ar.end(), in) - ar.begin();
}
template <class T>
long long int UBI(const vector<T>& ar, T in) {
  return upper_bound(ar.begin(), ar.end(), in) - ar.begin();
}
int main(void) {
  int i, j, n, m, Q, dme = 0;
  cin >> n >> m >> Q;
  static int ue[524288] = {};
  static int st[524288];
  static bool fl[524288] = {};
  for (i = 1; i < 524288; i++) {
    st[i] = mod;
  }
  set<pair<int, int>> ues;
  set<pair<int, int>> sts;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    bool aaa = a % 2;
    a /= 2;
    b /= 2;
    b += 2;
    int ns = 0;
    if (aaa) {
      if (ues.count(make_pair(a, b))) {
        ues.erase(make_pair(a, b));
      } else {
        ues.insert(make_pair(a, b));
      }
      auto itr = ues.lower_bound(make_pair(a, mod));
      if (itr != ues.begin()) {
        itr--;
        ns = itr->second;
      } else {
        ns = 0;
      }
      int bas = 262144 + a;
      if (fl[bas]) {
        fl[bas] = 0;
        dme--;
      }
      ue[bas] = ns;
      if (st[bas] <= ue[bas]) {
        fl[bas] = 1;
        dme++;
      }
      bas /= 2;
      while (bas > 0) {
        if (fl[bas]) {
          fl[bas] = 0;
          dme--;
        }
        ue[bas] = max(ue[bas + bas], ue[bas + bas + 1]);
        if (st[bas + bas] <= ue[bas + bas + 1]) {
          fl[bas] = 1;
          dme++;
        }
        bas /= 2;
      }
    } else {
      if (sts.count(make_pair(a, b))) {
        sts.erase(make_pair(a, b));
      } else {
        sts.insert(make_pair(a, b));
      }
      auto itr = sts.lower_bound(make_pair(a, -mod));
      if (itr != sts.end()) {
        ns = itr->second;
      } else {
        ns = mod;
      }
      int bas = 262144 + a;
      if (fl[bas]) {
        dme--;
      }
      st[bas] = ns;
      if (st[bas] <= ue[bas]) {
        fl[bas] = 1;
        dme++;
      }
      bas /= 2;
      while (bas > 0) {
        if (fl[bas]) {
          fl[bas] = 0;
          dme--;
        }
        st[bas] = min(st[bas + bas], st[bas + bas + 1]);
        if (st[bas + bas] <= ue[bas + bas + 1]) {
          fl[bas] = 1;
          dme++;
        }
        bas /= 2;
      }
    }
    cout << (dme ? "No" : "Yes") << endl;
  }
  return 0;
}
