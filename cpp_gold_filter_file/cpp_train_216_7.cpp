#include <bits/stdc++.h>
using namespace std;
char s1[50], s2[50], s3[50];
struct P {
  int v, s;
};
map<string, P> mp[3];
int a[3][200];
char s[100];
int main() {
  int i, j, k, m, n;
  int tt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int atk, def, res, si;
    scanf("%s%s", s1, s2);
    scanf("%d%d%d%d", &atk, &def, &res, &si);
    if (s2[0] == 'w') {
      mp[0][s1].v = atk;
      mp[0][s1].s = si;
    } else if (s2[0] == 'a') {
      mp[1][s1].v = def;
      mp[1][s1].s = si;
    } else {
      mp[2][s1].v = res;
      mp[2][s1].s = si;
    }
    tt += si;
  }
  scanf("%d", &k);
  vector<pair<int, string> > v[3], v2[3];
  for (i = 0; i < k; i++) {
    int val;
    scanf("%s%s%d%s", s1, s2, &val, s3);
    if (s2[0] == 'g') {
      v[0].push_back(make_pair(val, s3));
      v2[0].push_back(make_pair(val, s1));
    } else if (s2[0] == 's') {
      v[1].push_back(make_pair(val, s3));
      v2[1].push_back(make_pair(val, s1));
    } else {
      v[2].push_back(make_pair(val, s3));
      v2[2].push_back(make_pair(val, s1));
    }
  }
  if (k == tt) {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < v[i].size(); j++) {
        if (mp[i].count(v[i][j].second))
          mp[i][v[i][j].second].v += v[i][j].first;
      }
      map<string, P>::iterator it2 = mp[i].begin();
      for (map<string, P>::iterator it = mp[i].begin(); it != mp[i].end(); it++)
        if (it->second.v > it2->second.v) it2 = it;
      vector<string> ans;
      for (int l = 0; l < 3; l++) {
        for (j = 0; j < v[l].size(); j++) {
          if (it2->first == v[l][j].second) ans.push_back(v2[l][j].second);
        }
      }
      printf("%s %d", it2->first.c_str(), ans.size());
      for (j = 0; j < ans.size(); j++) printf(" %s", ans[j].c_str());
      puts("");
    }
  } else {
    vector<string> ans[3];
    string name[3];
    set<string> st;
    for (i = 0; i < 3; i++) {
      sort(v2[i].begin(), v2[i].end());
      map<string, P>::iterator it2 = mp[i].begin();
      for (map<string, P>::iterator it = mp[i].begin(); it != mp[i].end();
           it++) {
        int t = 0;
        for (j = v2[i].size() - 1; j >= 0 && t < it->second.s; j--, t++) {
          it->second.v += v2[i][j].first;
        }
        if (it->second.v > it2->second.v) it2 = it;
      }
      name[i] = it2->first;
      for (j = v2[i].size() - 1; j >= 0 && ans[i].size() < it2->second.s; j--) {
        ans[i].push_back(v2[i][j].second);
        st.insert(v2[i][j].second);
      }
    }
    for (i = 0; i < 3; i++)
      for (j = 0; j < v2[i].size(); j++)
        if (!st.count(v2[i][j].second)) {
          for (int l = 0; l < 3; l++)
            if (ans[l].size() < mp[l][name[l]].s) {
              ans[l].push_back(v2[i][j].second);
              st.insert(v2[i][j].second);
              break;
            }
        }
    for (i = 0; i < 3; i++) {
      printf("%s %d", name[i].c_str(), ans[i].size());
      for (j = 0; j < ans[i].size(); j++) printf(" %s", ans[i][j].c_str());
      puts("");
    }
  }
  scanf("%*d");
}
