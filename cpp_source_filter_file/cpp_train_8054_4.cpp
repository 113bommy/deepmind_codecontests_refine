#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 77, Mod = 1000000007;
vector<pair<int, int> > V[3];
inline void PreCompute() {
  V[0].push_back(make_pair(1, 2));
  V[1].push_back(make_pair(3, 3));
  V[2].push_back(make_pair(4, 4));
  V[1].push_back(make_pair(5, 6));
  V[2].push_back(make_pair(7, 8));
  V[0].push_back(make_pair(9, 12));
  V[1].push_back(make_pair(13, 14));
  V[2].push_back(make_pair(15, 18));
  V[0].push_back(make_pair(19, 26));
  V[1].push_back(make_pair(27, 38));
  V[2].push_back(make_pair(39, 39));
  V[0].push_back(make_pair(40, 56));
  V[2].push_back(make_pair(57, 57));
  V[1].push_back(make_pair(58, 80));
  V[2].push_back(make_pair(81, 84));
  V[0].push_back(make_pair(85, 119));
  V[2].push_back(make_pair(120, 120));
  V[1].push_back(make_pair(121, 173));
  V[2].push_back(make_pair(174, 178));
  V[0].push_back(make_pair(179, 254));
  V[2].push_back(make_pair(255, 259));
  V[1].push_back(make_pair(260, 362));
  V[2].push_back(make_pair(363, 381));
  V[0].push_back(make_pair(382, 536));
  V[2].push_back(make_pair(537, 543));
  V[1].push_back(make_pair(544, 779));
  V[2].push_back(make_pair(780, 804));
  V[0].push_back(make_pair(805, 1145));
  V[2].push_back(make_pair(1146, 1168));
  V[1].push_back(make_pair(1169, 1631));
  V[2].push_back(make_pair(1632, 1717));
  V[0].push_back(make_pair(1718, 2414));
  V[2].push_back(make_pair(2415, 2446));
  V[1].push_back(make_pair(2447, 3506));
  V[2].push_back(make_pair(3507, 3621));
  V[0].push_back(make_pair(3622, 5153));
  V[2].push_back(make_pair(5154, 5259));
  V[1].push_back(make_pair(5260, 7340));
  V[2].push_back(make_pair(7341, 7729));
  V[0].push_back(make_pair(7730, 10865));
  V[2].push_back(make_pair(10866, 11010));
  V[1].push_back(make_pair(11011, 15779));
  V[2].push_back(make_pair(15780, 16297));
  V[0].push_back(make_pair(16298, 23189));
  V[2].push_back(make_pair(23190, 23668));
  V[1].push_back(make_pair(23669, 33032));
  V[2].push_back(make_pair(33033, 34783));
  V[0].push_back(make_pair(34784, 48893));
  V[2].push_back(make_pair(48894, 49548));
  V[1].push_back(make_pair(49549, 71006));
  V[2].push_back(make_pair(71007, 73339));
  V[0].push_back(make_pair(73340, 104351));
  V[2].push_back(make_pair(104352, 106509));
  V[1].push_back(make_pair(106510, 148646));
  V[2].push_back(make_pair(148647, 156526));
  V[0].push_back(make_pair(156527, 220019));
  V[2].push_back(make_pair(220020, 222969));
  V[1].push_back(make_pair(222970, 319529));
  V[2].push_back(make_pair(319530, 330028));
  V[0].push_back(make_pair(330029, 469580));
  V[2].push_back(make_pair(469581, 479293));
  V[1].push_back(make_pair(479294, 668909));
  V[2].push_back(make_pair(668910, 704370));
  V[0].push_back(make_pair(704371, 990086));
  V[2].push_back(make_pair(990087, 1003363));
  V[1].push_back(make_pair(1003364, 1437881));
  V[2].push_back(make_pair(1437882, 1485129));
  V[0].push_back(make_pair(1485130, 2113112));
  V[2].push_back(make_pair(2113113, 2156821));
  V[1].push_back(make_pair(2156822, 3010091));
  V[2].push_back(make_pair(3010092, 3169668));
  V[0].push_back(make_pair(3169669, 4455389));
  V[2].push_back(make_pair(4455390, 4515136));
  V[1].push_back(make_pair(4515137, 6470465));
  V[2].push_back(make_pair(6470466, 6683083));
  V[0].push_back(make_pair(6683084, 9509006));
  V[2].push_back(make_pair(9509007, 9705697));
  V[1].push_back(make_pair(9705698, 13545410));
  V[2].push_back(make_pair(13545411, 14263509));
  V[0].push_back(make_pair(14263510, 20049251));
  V[2].push_back(make_pair(20049252, 20318115));
  V[1].push_back(make_pair(20318116, 29117093));
  V[2].push_back(make_pair(29117094, 30073876));
  V[0].push_back(make_pair(30073877, 42790529));
  V[2].push_back(make_pair(42790530, 43675639));
  V[1].push_back(make_pair(43675640, 60954347));
  V[2].push_back(make_pair(60954348, 64185793));
  V[0].push_back(make_pair(64185794, 90221630));
  V[2].push_back(make_pair(90221631, 91431520));
  V[1].push_back(make_pair(91431521, 131026919));
  V[2].push_back(make_pair(131026920, 135332445));
  V[0].push_back(make_pair(135332446, 192557381));
  V[2].push_back(make_pair(192557382, 196540378));
  V[1].push_back(make_pair(196540379, 274294562));
  V[2].push_back(make_pair(274294563, 288836071));
  V[0].push_back(make_pair(288836072, 405997337));
  V[2].push_back(make_pair(405997338, 411441843));
  V[1].push_back(make_pair(411441844, 589621136));
  V[2].push_back(make_pair(589621137, 608996005));
  V[0].push_back(make_pair(608996006, 866508215));
  V[2].push_back(make_pair(866508216, 884431704));
  V[1].push_back(make_pair(884431705, 1000000000));
}
int n, p;
int F[3], dp[N][4];
inline long long Get(int l, int r) {
  long long res = (r - l + 1) * 1ll * p;
  --l;
  --r;
  res -= (l + r) * 1ll * (r - l + 1) / 2;
  return res;
}
int main() {
  PreCompute();
  scanf("%d %d", &n, &p);
  --p;
  for (int k = 0; k < 3; ++k)
    for (auto x : V[k])
      if (p >= x.first) F[k] = (F[k] + Get(x.first, min(p, x.second))) % Mod;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 4; ++j)
      for (int s = 0; s < 4; ++s)
        dp[i][j] = (dp[i][j] + dp[i - 1][j ^ s] * 1ll * F[s]) % Mod;
  printf("%d\n", ((dp[n][1] + dp[n][2]) % Mod + dp[n][3]) % Mod);
  return 0;
}
