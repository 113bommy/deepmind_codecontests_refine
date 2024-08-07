#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1 << 18;
const int Maxm = 1 << 10;
int A[Maxn], St[Maxn], Fn[Maxn], Time, n, m, q;
vector<int> G[Maxn];
bitset<Maxm> F, R;
struct Node {
  bitset<Maxm> B;
  int lazy;
  Node() {
    lazy = 0;
    B[0] = 1;
  }
} Seg[Maxn << 2];
void Add(int id, int val) {
  val %= m;
  Seg[id].lazy += val;
  Seg[id].lazy %= m;
  Seg[id].B = (Seg[id].B << val) | (Seg[id].B >> (m - val));
}
void Shift(int id) {
  if (!Seg[id].lazy) return;
  Add((id << 1), Seg[id].lazy);
  Add(((id << 1) | 1), Seg[id].lazy);
  Seg[id].lazy = 0;
}
void Change(int l, int r, int x, int id = 1, int b = 0, int e = n) {
  if (r <= b || e <= l) return;
  if (l <= b && e <= r) {
    Add(id, x);
    return;
  }
  Shift(id);
  Change(l, r, x, (id << 1), b, ((b + e) >> 1));
  Change(l, r, x, ((id << 1) | 1), ((b + e) >> 1), e);
  Seg[id].B = Seg[(id << 1)].B | Seg[((id << 1) | 1)].B;
}
void Get(int l, int r, int id = 1, int b = 0, int e = n) {
  if (r <= b || e <= l) return;
  if (l <= b && e <= r) {
    F |= Seg[id].B;
    return;
  }
  Shift(id);
  Get(l, r, (id << 1), b, ((b + e) >> 1));
  Get(l, r, ((id << 1) | 1), ((b + e) >> 1), e);
}
void DFS(int v = 1, int par = 0) {
  St[v] = Time++;
  for (auto u : G[v])
    if (u ^ par) DFS(u, v);
  Fn[v] = Time;
}
bool Prime(int x) {
  for (int i = 2; i < x; i++)
    if (x % i == 0) return false;
  return true;
}
void Pre() {
  for (int i = 2; i < m; i++) R[i] = Prime(i);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 0, v, u; i < n - 1; i++) {
    cin >> v >> u;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  DFS();
  Pre();
  for (int i = 1; i <= n; i++) Change(St[i], St[i] + 1, A[i] % m);
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, x;
      cin >> v >> x;
      Change(St[v], Fn[v], x % m);
    } else {
      int v;
      cin >> v;
      F.reset();
      Get(St[v], Fn[v]);
      cout << (F & R).count() << '\n';
    }
  }
}
