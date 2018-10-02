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

int n;
int a[N];
int bin[100];
int ans=inf;
int gcd(int a,int b) {
	if (b==0) return a;
	return gcd(b,a%b);
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    bin[0]=1;
    FOR(i,n) bin[i]=bin[i-1]*2;
    int cnt,d;
    d=a[1];
    REP(i,2,n) d=gcd(d,a[i]);
    int dd=d;
    for (int i=0;i<bin[n];i++) {
    	cnt=0;
    	d=-1;
    	for (int j=0;j<n;j++) {
    		if (i&bin[j]) {
    			if (d==-1) d=a[j+1];
    			else {
    				d=gcd(d,a[j+1]);
				}
				++cnt;
			}
		}
		if (d<=dd) continue;
		ans=min(ans,n-cnt);
	}
	if (ans==inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
