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
const ll mo=36028797018963913;

int T;
int n,k;
ll c[N];
ll ha[N];
bool ans[N];
ll res[N];
unordered_map<ll,ll> m;
long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   	T=readInt();
	c[0]=1;
	FOR(i,30000) c[i]=c[i-1]*29%mo;
    while (T--) {
	    n=readInt();
	    k=readInt();
	    FOR(i,n) ans[i]=0;
	    char s[n+1][k];
	    FOR(i,n) {
	    	for (int j = 0; j < k; j++) {
				s[i][j] = getchar();
			}
			getchar();
		}
		
		if (n<=k) {
			int cnt=0;
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
			memset(ha,0,sizeof ha);
			FOR(i,n) for (int j=0;j<k;j++) {
				ha[i]=(ha[i]+c[j]*(s[i][j]-'a'+1)%mo)%mo;
			}
			REP(i,0,k-1) REP(j,i+1,k-1) {
				m.clear();
				FOR(x,n) {
					res[x]=ha[x];
					res[x]=(res[x]-c[i]*(s[x][i]-'a'+1)%mo+mo)%mo;
					res[x]=(res[x]-c[j]*(s[x][j]-'a'+1)%mo+mo)%mo;
					m[res[x]]++;
				}
				FOR(x,n) {
					if (m[res[x]]>=2) {
						ans[x]=1;
					}
				}
			}
		}
		FOR(i,n) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
