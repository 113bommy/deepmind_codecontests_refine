#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1700;
const int OFFSET = 50;
const int PADDING = 6;
const int MARGIN = 8;
const int MIN_SUN = 500;
const int MIN_RAY = 9;
bool ok1[OFFSET][OFFSET], ok2[OFFSET][OFFSET];
template <int DIS>
pair<int, pair<int, int> > floodfill(int x, int y, const int z,
                                     const char s[MAXN][MAXN],
                                     int tag[MAXN][MAXN]) {
  pair<int, pair<int, int> > ret;
  queue<pair<int, int> > q;
  tag[x][y] = z;
  q.push({x, y});
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    ++ret.first;
    ret.second.first += x;
    ret.second.second += y;
    for (int xx = x - DIS; xx <= x + DIS; ++xx) {
      for (int yy = y - DIS; yy <= y + DIS; ++yy) {
        if (s[xx][yy] == '1' && tag[xx][yy] == -1) {
          tag[xx][yy] = z;
          q.push({xx, yy});
        }
      }
    }
  }
  ret.second.first /= ret.first;
  ret.second.second /= ret.first;
  return ret;
}
char s1[MAXN][MAXN], s2[MAXN][MAXN];
int tag1[MAXN][MAXN], tag2[MAXN][MAXN];
int main() {
  int h, w;
  map<int, int> sun, ray;
  vector<pair<int, int> > center;
  for (int i = 0; i < (int)(OFFSET); ++i)
    for (int j = 0; j < (int)(OFFSET); ++j) {
      ok1[i][j] = i * i + j * j <= PADDING * PADDING;
      ok2[i][j] = i * i + j * j <= MARGIN * MARGIN;
    }
  memset(tag1, 0xff, sizeof(tag1));
  memset(tag2, 0xff, sizeof(tag2));
  scanf("%d%d", &h, &w);
  for (int i = 0; i < (int)(h); ++i) {
    for (int j = 0; j < (int)(w); ++j) {
      scanf(" %c", &s1[OFFSET + i][OFFSET + j]);
    }
  }
  for (int i = 0; i < (int)(h); ++i) {
    for (int j = 0; j < (int)(w); ++j) {
      if (s1[OFFSET + i][OFFSET + j] == '1' &&
          tag1[OFFSET + i][OFFSET + j] == -1) {
        int id = center.size();
        auto tmp = floodfill<1>(OFFSET + i, OFFSET + j, id, s1, tag1);
        sun[id] = tmp.first;
        center.push_back(tmp.second);
        if (sun[id] >= MIN_SUN) {
          ray[id];
        } else if (sun[id] > 1) {
          fprintf(stderr, "ignore (%d, %d) size = %d\n", i, j, tmp.first);
        }
      }
    }
  }
  for (int i = 0; i < (int)(h); ++i) {
    for (int j = 0; j < (int)(w); ++j) {
      s2[OFFSET + i][OFFSET + j] = '1';
      for (int xx = i - PADDING; xx <= i + PADDING; ++xx) {
        for (int yy = j - PADDING; yy <= j + PADDING; ++yy) {
          if (!ok1[abs(i - xx)][abs(j - yy)]) {
            continue;
          }
          if (s1[OFFSET + xx][OFFSET + yy] != '1') {
            s2[OFFSET + i][OFFSET + j] = '0';
            goto NEXT;
          }
        }
      }
    NEXT:
      continue;
    }
  }
  for (int i = 0; i < (int)center.size(); ++i) {
    if (sun[i] < MIN_SUN) {
      continue;
    }
    auto tmp = floodfill<2>(center[i].first, center[i].second, i, s2, tag2);
    fprintf(stderr, "sun[%d] (%d, %d) %d => %d\n", i, center[i].first,
            center[i].second, sun[i], tmp.first);
  }
  for (int i = 0; i < (int)(h); ++i) {
    for (int j = 0; j < (int)(w); ++j) {
      if (tag2[OFFSET + i][OFFSET + j] != -1) {
        for (int xx = i - MARGIN; xx <= i + MARGIN; ++xx) {
          for (int yy = j - MARGIN; yy <= j + MARGIN; ++yy) {
            if (!ok2[abs(i - xx)][abs(j - yy)]) {
              continue;
            }
            s1[OFFSET + xx][OFFSET + yy] = '0';
          }
        }
      }
    }
  }
  memset(tag2, 0xff, sizeof(tag2));
  for (int i = 0; i < (int)(h); ++i) {
    for (int j = 0; j < (int)(w); ++j) {
      if (s1[OFFSET + i][OFFSET + j] == '1' &&
          tag1[OFFSET + i][OFFSET + j] != -1 &&
          tag2[OFFSET + i][OFFSET + j] == -1) {
        auto tmp = floodfill<2>(OFFSET + i, OFFSET + j, 0, s1, tag2);
        if (tmp.first >= MIN_RAY) {
          fprintf(stderr, "ray[%d] (%d, %d) => %d\n",
                  tag1[OFFSET + i][OFFSET + j], i, j, tmp.first);
          ++ray[tag1[OFFSET + i][OFFSET + j]];
        } else if (tmp.first > 1) {
          fprintf(stderr, "IGNORE_RAY[%d] (%d, %d) => %d\n",
                  tag1[OFFSET + i][OFFSET + j], i, j, tmp.first);
        }
      }
    }
  }
  vector<int> ans;
  for (auto i : ray) {
    ans.push_back(i.second);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}
