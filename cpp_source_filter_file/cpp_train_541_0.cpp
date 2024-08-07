#include <bits/stdc++.h>
using namespace std;
class TaskB {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    int k;
    in >> n >> k;
    vector<bool> interesting(1 << n);
    for (int i = 0; i < k; ++i) {
      int a;
      in >> a;
      interesting[a - 1] = true;
    }
    vector<vector<int>> dp(1 << (n - 1), vector<int>(4, -1));
    for (int i = 0; i < dp.size(); ++i) {
      int cnt = (interesting[2 * i] ? 1 : 0) + (interesting[2 * i + 1] ? 1 : 0);
      if (cnt == 0) {
        dp[i][0] = 0;
      } else if (cnt == 1) {
        dp[i][1] = 1;
        dp[i][2] = 1;
      } else {
        dp[i][3] = 1;
      }
    }
    vector<int> tmp(4);
    vector<int> tmp2(2);
    while (dp.size() > 1) {
      vector<vector<int>> ndp(dp.size() / 2, vector<int>(4, -1));
      for (int i = 0; i < ndp.size(); ++i) {
        for (int o1 = 0; o1 < 4; ++o1)
          if (dp[2 * i][o1] >= 0) {
            for (int o2 = 0; o2 < 4; ++o2)
              if (dp[2 * i + 1][o2] >= 0) {
                int base = dp[2 * i][o1] + dp[2 * i + 1][o2];
                fill(tmp.begin(), tmp.end(), -1);
                int cnt = ((o1 & 1) != 0 ? 1 : 0) + ((o2 & 1) != 0 ? 1 : 0);
                if (cnt == 0) {
                  tmp[0] = 0;
                } else if (cnt == 1) {
                  tmp[1] = 1;
                  tmp[2] = 1;
                } else {
                  tmp[3] = 1;
                }
                fill(tmp2.begin(), tmp2.end(), -1);
                cnt = ((o1 & 2) != 0 ? 1 : 0) + ((o2 & 2) != 0 ? 1 : 0);
                if (cnt == 0) {
                  tmp2[0] = 0;
                } else if (cnt == 1) {
                  tmp2[1] = 1;
                  tmp2[0] = 1;
                } else {
                  tmp2[1] = 1;
                }
                for (int t1 = 0; t1 < 4; ++t1)
                  if (tmp[t1] >= 0) {
                    for (int t2 = 0; t2 < 2; ++t2)
                      if (tmp2[t2] >= 0) {
                        int nbase = base + tmp[t1] + tmp2[t2];
                        cnt = ((t1 & 2) != 0 ? 1 : 0) + t2;
                        if (cnt == 0) {
                          ndp[i][(o1 & 1)] = max(ndp[i][(o1 & 1)], nbase);
                        } else if (cnt == 1) {
                          ndp[i][(o1 & 1)] = max(ndp[i][(o1 & 1)], nbase + 1);
                          ndp[i][(o1 & 1) + 2] =
                              max(ndp[i][(o1 & 1) + 2], nbase + 1);
                        } else {
                          ndp[i][(o1 & 1) + 2] =
                              max(ndp[i][(o1 & 1) + 2], nbase + 1);
                        }
                      }
                  }
              }
          }
      }
      dp.swap(ndp);
    }
    int res = 0;
    for (int i = 0; i < 4; ++i) {
      int cur = dp[0][i];
      if (i > 0) ++cur;
      res = max(res, cur);
    }
    out << res << "\n";
  }
  void solve(std::istream &in, std::ostream &out) {
    int nt;
    nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskB solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
