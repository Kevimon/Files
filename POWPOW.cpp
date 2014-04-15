#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

#define REP(i,a,b) 	for(int i=a;i<(int)b;i++)
#define FOR(it,A)	for(typeof A.begin() it=A.begin();it!=A.end();it++)
#define all(x) 		(x).begin(),(x).end()
#define pb 			push_back
#define clr(x,y)	memset(x,y,sizeof x)
#define oo 			(1<<30)
#define inf 		(1LL<<40)
#define bit(x)		__builtin_popcount(x)
#define mp			make_pair
#define fst			first
#define snd			second
#define maxN		100005
#define mod			1000000007

typedef long long     ll;
typedef vector<int>   vi;
typedef pair<int,int> pii;
typedef long double   ld;

ll inv(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x = 1; y = 0;
		return a;
	}
	ll x1,y1;
	ll g = inv(b,a%b,x1,y1);
	x = y1;
	y = x1 - (a/b)*y1 ;
	return g;
}

ll fast(ll b,ll e,ll m){
	ll ans = 1;
	while(e){
		if(e&1) ans = (ans*b)%m;
		b = (b*b)%m; 
		e>>=1;
	}
	return ans;
}

ll C[100004];
const ll N = (mod - 1 )/2;
int main(){
	int cases;
	scanf("%d",&cases);
	C[1] = 1;
	ll x,y;

	for(ll i=2; i < 100004; i++){
		C[i] = ((2*i-1) * 2 * C[i-1])%N;
		inv(i,N,x,y);
		C[i] = (C[i] * x )%N;
	}
	REP(ii,0,cases){
		ll a,b,n;
		scanf("%lld %lld %lld",&a,&b,&n);
		ll exp = C[n] * 2;
		ll exp1 = (fast(exp,b,mod-1) + mod-1)%(mod-1);
		printf("%lld\n",(fast(a,exp1,mod) + mod)%mod);
	}
	
    return 0;
}





