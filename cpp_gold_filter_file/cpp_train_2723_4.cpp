#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
struct mod_int {
  int val;
  mod_int(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static int mod_inv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  mod_int &operator+=(const mod_int &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  mod_int &operator-=(const mod_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  mod_int &operator*=(const mod_int &other) {
    val = (uint64_t)val * other.val % MOD;
    return *this;
  }
  mod_int &operator/=(const mod_int &other) { return *this *= other.inv(); }
  friend mod_int operator+(const mod_int &a, const mod_int &b) {
    return mod_int(a) += b;
  }
  friend mod_int operator-(const mod_int &a, const mod_int &b) {
    return mod_int(a) -= b;
  }
  friend mod_int operator*(const mod_int &a, const mod_int &b) {
    return mod_int(a) *= b;
  }
  friend mod_int operator/(const mod_int &a, const mod_int &b) {
    return mod_int(a) /= b;
  }
  mod_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  mod_int operator++(int) {
    mod_int before = *this;
    ++*this;
    return before;
  }
  mod_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  mod_int operator--(int) {
    mod_int before = *this;
    --*this;
    return before;
  }
  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const mod_int &other) const { return val == other.val; }
  bool operator!=(const mod_int &other) const { return val != other.val; }
  mod_int inv() const { return mod_inv(val); }
  mod_int pow(long long p) const {
    assert(p >= 0);
    mod_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
};
vector<mod_int> factorial, inv_factorial;
vector<mod_int> inv;
void prepare_factorials(int max) {
  inv.assign(max + 1, 1);
  for (int p = 2; p * p <= MOD; p++) assert(MOD % p != 0);
  for (int i = 2; i <= max; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i);
  factorial.resize(max + 1);
  inv_factorial.resize(max + 1);
  factorial[0] = inv_factorial[0] = 1;
  for (int i = 1; i <= max; i++) {
    factorial[i] = i * factorial[i - 1];
    inv_factorial[i] = inv[i] * inv_factorial[i - 1];
  }
}
mod_int choose(int n, int r) {
  assert(0 <= r && r <= n);
  return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}
int N, M;
int L, DL;
vector<int> likes;
vector<int> weights;
vector<mod_int> probability;
map<int, mod_int> save[2];
mod_int solve(int like, int weight) {
  if (save[like].find(weight) != save[like].end()) return save[like][weight];
  mod_int answer = 0;
  if (like) {
    for (int up = 0; up <= M; up++) {
      if (probability[2 * up] == 0) continue;
      mod_int starter = probability[2 * up];
      mod_int other = 1;
      for (int i = 0; i < up; i++) {
        starter /= mod_int(L + i);
        other *= mod_int(L - weight + i);
      }
      for (int u = 0; u <= up; u++) {
        if (u > 0) other /= mod_int(L - weight + up - u);
        mod_int product = starter * choose(up, u) * (weight + u);
        if (L == weight) {
          if (u < up) product = 0;
        } else {
          product *= other;
        }
        answer += product;
        starter *= mod_int(weight + u);
      }
    }
  } else {
    for (int down = 0; down <= M; down++) {
      if (probability[2 * (M - down)] == 0) continue;
      mod_int starter = probability[2 * (M - down)];
      mod_int other = 1;
      for (int i = 0; i < down; i++) {
        starter /= mod_int(DL - i);
        other *= mod_int(DL - weight - i);
      }
      for (int d = 0; d <= min(down, weight); d++) {
        if (d > 0) other /= mod_int(DL - weight + down - d);
        mod_int product = starter * choose(down, d) * (weight - d);
        if (DL == weight) {
          if (d < down) product = 0;
        } else {
          product *= other;
        }
        answer += product;
        starter *= mod_int(weight - d);
      }
    }
  }
  return save[like][weight] = answer;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  prepare_factorials(N + M + 100);
  cin >> N >> M;
  likes.resize(N);
  weights.resize(N);
  for (int &like : likes) cin >> like;
  for (int &weight : weights) cin >> weight;
  L = DL = 0;
  for (int i = 0; i < N; i++)
    if (likes[i])
      L += weights[i];
    else
      DL += weights[i];
  probability.assign(2 * M + 1, 0);
  probability[M] = 1;
  for (int iter = 0; iter < M; iter++) {
    vector<mod_int> new_probability(2 * M + 1, 0);
    for (int i = -M; i <= M; i++) {
      if ((i + iter) % 2 != 0 || abs(i) > iter) continue;
      int up = (iter + i) / 2, down = (iter - i) / 2;
      if (down > DL) continue;
      mod_int like_probability = mod_int(L + up) / mod_int(L + DL + i);
      mod_int dislike_probability = mod_int(1) - like_probability;
      new_probability[M + i + 1] += probability[M + i] * like_probability;
      new_probability[M + i - 1] += probability[M + i] * dislike_probability;
    }
    swap(probability, new_probability);
  }
  for (int i = 0; i < N; i++) {
    mod_int answer = mod_int(weights[i]) * solve(likes[i], 1);
    cout << (int)answer << '\n';
  }
}
