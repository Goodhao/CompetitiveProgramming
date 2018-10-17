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
const int N=300000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n,m;
int a[N];
int tot;
int prime[N];
bool del[N];
int cnt[N][25];
int ans=inf;
int cc;
int sum;
void get(int x) {
	REP(i,2,x) {
		if (!del[i]) prime[++tot]=i;
		for (ll j=(ll)i*i;j<=(ll)x;j+=(ll)i) {
			del[j]=1;
		}
	}
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,n) m=max(m,a[i]);
    m=sqrt(m);
    m=max(m,10);
    get(m);
	FOR(i,tot) FOR(j,n) {
		cc=0;
		while (a[j]%prime[i]==0) {
			a[j]/=prime[i];
			cc++;
		}
		if (cc) {
			cnt[prime[i]][cc]++;
			cnt[prime[i]][0]++;
			// cnt[..][0]¸ºÔð´æsum cnt[..][i] 
		}
	}
	//FOR(i,n) cout<<a[i]<<endl;
	sort(a+1,a+1+n);
	int pos=0,len;
	FOR(i,n) if (i==n||a[i]!=a[i+1]) {
		if (a[i]!=1) {
			len=i-pos;
			if (n!=len) ans=min(ans,n-len);
			//cout<<n-len<<endl;
		}
		pos=i;
	}
	FOR(i,tot) if (cnt[prime[i]][0]&&cnt[prime[i]][0]!=n) {
		ans=min(ans,n-cnt[prime[i]][0]);
		//cout<<n-cnt[prime[i]][0]<<endl;
	}
	FOR(i,tot) {
		sum=cnt[prime[i]][0];
		if (sum!=n) continue;
		FOR(j,24) {
			if (cnt[prime[i]][j]) {
				if (sum!=cnt[prime[i]][j]) {
					ans=min(ans,cnt[prime[i]][j]);
				}
				break;
			}
		}
	}
	if (ans>=n) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
