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
const int N=150+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
int a[N];
int b[N];
// b[i]=j表示将颜色i替换成j 
bool used[N];
void ask(int l,int r,int x) {
	int len=r-l+1+1;
	printf("%d ",len);
	REP(i,l,r) printf("%d ",i);
	printf("%d\n",x);
	fflush(stdout);
}
int count(int l,int r) {
	memset(used,0,sizeof used);
	int res=0;
	REP(i,l,r) if (!used[a[i]]) {
		used[a[i]]=1;
		res++;
	}
	return res;
}
void solve(int l,int r) {
	if (l==r) {
		a[l]=1;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	int ans,tot,now;
	memset(b,0,sizeof b);
	now=count(l,mid);
	REP(i,mid+1,r) if (!b[a[i]]) {
		ask(l,mid,i);
		scanf("%d",&ans);
		tot=count(l,mid);
		if (ans==tot+1) {
			b[a[i]]=++now;
		} else if (l==mid) {
			b[a[i]]=a[l];
		} else {
			int L=l,M=0,R=mid;
			while (L<=R) {
				if (L==R) {
					b[a[i]]=a[L];
					break;
				}
				M=(L+R)/2;
				ask(L,M,i);
				scanf("%d",&ans);
				tot=count(L,M);
				if (ans==tot+1) {
					L=M+1;
				} else {
					R=M;
				}
			}
		}
	}
	REP(i,mid+1,r) a[i]=b[a[i]];
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    solve(1,n);
    printf("%d ",0);
    FOR(i,n) printf("%d ",a[i]);
    fflush(stdout);
	return 0;
}
