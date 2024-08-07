#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
const int MAXV = 2 * MAXN;
int BIT[MAXV + 10];
set<int> S[MAXV + 10];
int l[MAXN + 5], r[MAXN + 5];
vector<int> cc;
int getId(int value) {
  return upper_bound(cc.begin(), cc.end(), value) - cc.begin();
}
set<int> actives;
void update(int pos, int id, int sign) {
  pos = getId(pos);
  if (sign == 1)
    actives.insert(id);
  else
    actives.erase(id);
  while (pos <= MAXV + 1) {
    BIT[pos] += sign;
    pos += (pos & -pos);
  }
}
int query(int pos) {
  int ans = 0;
  while (pos) {
    ans += BIT[pos];
    pos -= (pos & -pos);
  }
  return ans;
}
vector<int> getIds(int upto, int k, int last) {
  vector<int> answer;
  for (set<int>::iterator it = actives.begin(); it != actives.end(); it++) {
    int v = *it;
    if (answer.size() == k - 1) break;
    if (l[v] <= cc[upto] && v != last) {
      answer.push_back(v);
    }
  }
  answer.push_back(last);
  return answer;
}
bool ok(int mid, int k) { return query(mid) >= k; }
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int> > events;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    cc.push_back(l[i]);
    cc.push_back(r[i]);
    events.push_back(make_pair(l[i], -i));
    events.push_back(make_pair(r[i], i));
  }
  sort(cc.begin(), cc.end());
  cc.erase(unique(cc.begin(), cc.end()), cc.end());
  sort(events.begin(), events.end());
  int ans = 0;
  vector<int> ids;
  int active = 0;
  for (int i = 1; i <= k; i++) ids.push_back(i);
  for (int i = 0; i < events.size(); i++) {
    int id = events[i].second;
    int t = events[i].first;
    if (id < 0) {
      active++;
      update(t, -id, 1);
    } else {
      if (active < k) {
        update(l[id], id, -1);
        active--;
        continue;
      }
      active--;
      int lo = getId(l[id]), hi = MAXV;
      while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (ok(mid, k))
          hi = mid - 1;
        else
          lo = mid;
      }
      if (!ok(lo, k)) lo++;
      int cur = t - cc[lo - 1] + 1;
      if (cur > ans) {
        ans = cur;
      }
      update(l[id], id, -1);
    }
  }
  for (int i = 0; i < events.size() && ans > 0; i++) {
    int id = events[i].second;
    int t = events[i].first;
    if (id < 0) {
      active++;
      update(t, -id, 1);
    } else {
      if (active < k) {
        update(l[id], id, -1);
        active--;
        continue;
      }
      active--;
      int lo = getId(l[id]), hi = MAXV;
      while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (ok(mid, k))
          hi = mid - 1;
        else
          lo = mid;
      }
      if (!ok(lo, k)) lo++;
      int cur = t - cc[lo - 1] + 1;
      if (cur == ans) {
        ids = getIds(lo, k, id);
        break;
      }
      update(l[id], id, -1);
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < ids.size(); i++) {
    if (i) printf(" ");
    printf("%d", ids[i]);
  }
  return 0;
}
