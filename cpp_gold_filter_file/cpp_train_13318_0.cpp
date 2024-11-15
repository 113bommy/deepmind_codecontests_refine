#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int a[100000];

int main(){
	int n, m; cin >> n >> m;
	int ans = 0;
	rep(i, m) cin >> a[i];
	rep(i, m - 1) ans = max(ans, (a[i + 1] - a[i]) / 2);
	ans = max(ans, a[0] - 1);
	ans = max(ans, n - a[m - 1]);
	cout << ans << endl;
	return 0;
}