#include <complex>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const double EPS = 1e-12;
typedef complex<long double> P;
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

long long pow_binary_mod(long long x,long long y,long long M){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x%M;
		x=x*x%M;
	}
	return z;
}

int main(){
	int M=998244353;
	int N,x,y;
	scanf("%d",&N);
	vector<P>v(N);
	int r=pow_binary_mod(2,N,M);
	set<L>se;
	for(int i=0;i<N;i++)scanf("%d%d",&x,&y),v[i]={(double)x,(double)y};
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
		//if(se.find({i,j})!=se.end())continue;
		L l(v[i],v[j]);
		vector<int>x={i,j};
		for(int k=0;k<N;k++)if(k!=i&&k!=j&&intersectSP(l,v[k]))x.push_back(k);
		r=(r-pow_binary_mod(2,x.size()-2,M))%M;
		for(int a=0;a<x.size();a++)for(int b=a+1;b<x.size();b++){
			//se.emplace(x[a],x[b]);
		}
	}
	printf("%d\n",((r-N-1)%M+M)%M);
}