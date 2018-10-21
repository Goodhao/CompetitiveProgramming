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
const int N=100000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n,q,KK;
int a[N];
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d %d",&n,&q,&KK);
    int t;
    FOR(i,n) {
    	scanf("%d",&t);
    	a[i]=t;
	}
	
	int s,l,r;
	FOR(i,q) {
		scanf("%d %d %d",&s,&l,&r);
		if (s==1) {
			a[l]=r;
		} else if (s==2) {
			REP(i,l,r) {
				a[i]/=KK;
			}
		} else {
			ll sum=0;
			REP(i,l,r) sum+=a[i];
			cout<<sum<<endl;
		}
	}
	return 0;
}
