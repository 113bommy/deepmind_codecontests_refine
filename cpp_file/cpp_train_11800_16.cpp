#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> s;
void RS(string &s) {
  s = "";
  char c = getchar();
  while (!((c >= 'a') && (c <= 'z'))) c = getchar();
  while ((c >= 'a') && (c <= 'z')) {
    s += c;
    c = getchar();
  }
}
void Load() {
  scanf("%d%d", &n, &k);
  int i;
  for (i = 0; i < n; i++) {
    string cs;
    RS(cs);
    s.push_back(cs);
  }
}
int nv;
int fst[1100000];
int nxt[1100000];
int cnt[1100000];
char byc[1100000];
char isen[1100000];
int GetGo(int v, char c) {
  int i;
  for (i = fst[v]; i != -1; i = nxt[i]) {
    if (byc[i] == c) return i;
  }
  return -1;
}
int nver;
int first[4100];
int ncnt[4100];
vector<int> it_is_next;
vector<int> lens;
int sumcnt[4100];
void AddEdge(int v1, int v2, int len) {
  it_is_next.push_back(first[v1]);
  lens.push_back(len);
  first[v1] = v2;
}
void Dfs(int v, int pv, int clen) {
  int nchld = 0;
  int i;
  for (i = fst[v]; i != -1; i = nxt[i]) {
    nchld++;
  }
  if (nchld == 1 && isen[v] == 0) {
    Dfs(fst[v], pv, clen + 1);
  } else {
    int lver = pv;
    if (clen != 0) {
      AddEdge(pv, nver, clen);
      ncnt[nver] = cnt[v];
      lver = nver;
      nver++;
    }
    for (i = fst[v]; i != -1; i = nxt[i]) {
      Dfs(i, lver, 1);
    }
  }
}
int res[4100][4100];
int Count(int v, int k) {
  if (res[v][k] != -1) return res[v][k];
  if (it_is_next[v] == -1) {
    if (k > ncnt[v]) k = ncnt[v];
    res[v][k] = lens[v] * (k * (k - 1) / 2);
    if (first[v] != -1) {
      res[v][k] += Count(first[v], k);
    }
    return res[v][k];
  }
  int i;
  res[v][k] = 0;
  for (i = 0; i <= k; i++) {
    if (i <= ncnt[v] && (k - i <= sumcnt[it_is_next[v]])) {
      int cur = Count(it_is_next[v], k - i) + lens[v] * (i * (i - 1) / 2);
      if (first[v] != -1) {
        cur += Count(first[v], i);
      }
      if (cur > res[v][k]) res[v][k] = cur;
    }
  }
  return res[v][k];
}
void Solve() {
  nv = 1;
  memset(fst, 0xFF, sizeof(fst));
  int i, j;
  for (i = 0; i < n; i++) {
    int cv = 0;
    cnt[cv]++;
    for (j = 0; j < s[i].length(); j++) {
      int t = GetGo(cv, s[i][j]);
      if (t == -1) {
        nxt[nv] = fst[cv];
        byc[nv] = s[i][j];
        fst[cv] = nv;
        nv++;
        t = nv - 1;
      }
      cv = t;
      cnt[cv]++;
    }
    isen[cv] = 1;
  }
  memset(first, 0xFF, sizeof(first));
  ncnt[0] = cnt[0];
  nver = 1;
  lens.push_back(0);
  it_is_next.push_back(-1);
  Dfs(0, 0, 0);
  for (i = 0; i < nver; i++) {
    vector<int> cur;
    for (j = first[i]; j != -1; j = it_is_next[j]) {
      cur.push_back(j);
    }
    if (cur.size() == 0) continue;
    sumcnt[cur.back()] = ncnt[cur.back()];
    for (j = ((int)cur.size()) - 2; j >= 0; j--) {
      sumcnt[cur[j]] = ncnt[cur[j]] + sumcnt[cur[j + 1]];
    }
  }
  memset(res, 0xFF, sizeof(res));
  cout << Count(0, k);
}
int main() {
  Load();
  Solve();
  return 0;
}
