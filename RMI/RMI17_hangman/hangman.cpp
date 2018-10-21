#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i=1;i<=n;i++)
#define REP(i,a,b) for (int i=a;i<=b;i++)
 
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define mp make_pair
#define sz(x) ((int)(x).size())
 
typedef long long ll;

const int inf=0x3f3f3f3f;
const ll linf=1e18;
const int N=30000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n,k;
string s[N];
int c[N];
int ha[N][175];
int ans[N];
map<int,int> m;
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d",&n,&k);
    FOR(i,n) {
    	cin>>s[i];
	}
	int cnt;
	if (n<=k) {
		FOR(i,n) FOR(j,n) if (i!=j) {
			cnt=0;
			for (int p=0;p<k;p++) {
				if (s[i][p]!=s[j][p]) {
					++cnt;
				}
			}
			if (cnt<=2) ans[i]=1;
		}
	} else {
		c[0]=1;
		FOR(i,k) c[i]=c[i-1]*26,c[i]%=mo;
		FOR(i,n) for (int j=0;j<k;j++) {
			if (j==0) ha[i][j]=(ll)c[j]*(s[i][j]-'a')%mo;
			else ha[i][j]=ha[i][j-1]+(ll)c[j]*(s[i][j]-'a')%mo,ha[i][j]%=mo;
		}
		int res;
		REP(i,0,k-1) REP(j,0,k-1) {
			if (i!=j) {
				FOR(x,n) {
					res=(ll)ha[x][k-1]-c[i]*(s[x][i]-'a')-c[j]*(s[x][j]-'a');
					res%=mo;
					res=(res+mo)%mo;
					m[res]++;
				} 
			}
		}
		REP(i,0,k-1) REP(j,0,k-1) {
			if (i!=j) {
				FOR(x,n) {
					res=(ll)ha[x][k-1]-c[i]*(s[x][i]-'a')-c[j]*(s[x][j]-'a');
					res%=mo;
					res=(res+mo)%mo;
					if (m.count(res)&&m[res]>=2) {
						ans[x]=1;
					}
				} 
			}
		}
		REP(i,0,k-1) REP(j,0,k-1) {
			if (i!=j) {
				FOR(x,n) {
					res=(ll)ha[x][k-1]-c[i]*(s[x][i]-'a')-c[j]*(s[x][j]-'a');
					res%=mo;
					res=(res+mo)%mo;
					m[res]--;
				} 
			}
		}
	}
	FOR(i,n) cout<<ans[i];
	return 0;
}
