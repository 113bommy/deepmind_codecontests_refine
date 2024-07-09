#include <bits/stdc++.h>
using namespace std;
int a[200200], b[200200];
pair<int, int> p[200200];
set<int> s[200200];
int vst[200200];
int id[200200], L[200200], R[200200], val[200200];
int q[200200];
int fir[200200], last[200200];
int mxx[200200][18];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), s[a[i]].insert(i);
  for (int i = 0; i < m; i++) scanf("%d %d", &p[i].first, &p[i].second);
  int M = 327, runs = 0, ok = 0;
  if (m == 0) p[m++] = pair<int, int>(1, a[1]), ok = 1;
  for (int i = 0; i < m; i += M) {
    int ed = min(m, i + M);
    for (int j = 1; j <= n; j++) b[j] = a[j];
    runs++;
    int nn = 0;
    for (int j = i; j < ed; j++) {
      vst[b[p[j].first]] = runs;
      q[nn++] = b[p[j].first];
      vst[b[p[j].first] = p[j].second] = runs;
      q[nn++] = p[j].second;
    }
    int cur = 0, pre = 0, now = 0, mx;
    for (int i = 1; i <= n; i++) {
      if (now < i) {
        val[cur] = mx;
        R[cur] = now;
        mx = 0;
        L[++cur] = now = i;
      }
      id[i] = cur;
      if (vst[a[i]] != runs) {
        mx = max(mx, (int)s[a[i]].size());
        now = max(now, *s[a[i]].rbegin());
      }
    }
    val[cur] = mx, R[cur] = now;
    for (int i = 1; i <= cur; i++) mxx[i][0] = val[i];
    for (int j = 1; j < 18; j++) {
      for (int i = 1; i <= cur; i++) {
        mxx[i][j] = max(mxx[i][j - 1], mxx[min(i + (1 << j - 1), cur)][j - 1]);
      }
    }
    for (int i = 2; i <= cur; i++) val[i] += val[i - 1];
    sort(q, q + nn);
    nn = unique(q, q + nn) - q;
    for (int i = 0; i < nn; i++) {
      if (s[q[i]].empty())
        fir[q[i]] = last[q[i]] = 0;
      else
        fir[q[i]] = *s[q[i]].begin(), last[q[i]] = *s[q[i]].rbegin();
    }
    if (i == 0) {
      int sum = 0;
      sort(q, q + nn, [&](int a, int b) { return fir[a] < fir[b]; });
      int pre = 0;
      for (int i = 0, j = 0; i < nn; i = j) {
        if (fir[q[i]] == 0) {
          j++;
          continue;
        }
        int now = last[q[i]], mx = 0;
        while (1) {
          while (j < nn && now >= fir[q[j]])
            now = max(now, last[q[j]]), mx = max(mx, (int)s[q[j]].size()), j++;
          if (now == R[id[now]]) break;
          now = R[id[now]];
        }
        int st = fir[q[i]];
        sum += val[id[st] - 1] - val[pre];
        int l = 31 - __builtin_clz(id[now] - id[st] + 1);
        sum += max(mx, max(mxx[id[st]][l], mxx[id[now] - (1 << l) + 1][l]));
        pre = id[now];
      }
      sum += val[cur] - val[pre];
      printf("%d\n", n - sum);
    }
    if (ok) return 0;
    for (int j = i; j < ed; j++) {
      s[a[p[j].first]].erase(p[j].first);
      if (s[a[p[j].first]].empty())
        fir[a[p[j].first]] = last[a[p[j].first]] = 0;
      else
        fir[a[p[j].first]] = *s[a[p[j].first]].begin(),
        last[a[p[j].first]] = *s[a[p[j].first]].rbegin();
      a[p[j].first] = p[j].second;
      s[p[j].second].insert(p[j].first);
      fir[a[p[j].first]] = *s[a[p[j].first]].begin(),
      last[a[p[j].first]] = *s[a[p[j].first]].rbegin();
      int sum = 0;
      sort(q, q + nn, [&](int a, int b) { return fir[a] < fir[b]; });
      int pre = 0;
      for (int i = 0, j = 0; i < nn; i = j) {
        if (fir[q[i]] == 0) {
          j++;
          continue;
        }
        int now = last[q[i]], mx = 0;
        while (1) {
          while (j < nn && now >= fir[q[j]])
            now = max(now, last[q[j]]), mx = max(mx, (int)s[q[j]].size()), j++;
          if (now == R[id[now]]) break;
          now = R[id[now]];
        }
        int st = fir[q[i]];
        sum += val[id[st] - 1] - val[pre];
        int l = 31 - __builtin_clz(id[now] - id[st] + 1);
        sum += max(mx, max(mxx[id[st]][l], mxx[id[now] - (1 << l) + 1][l]));
        pre = id[now];
      }
      sum += val[cur] - val[pre];
      printf("%d\n", n - sum);
    }
  }
  return 0;
}
