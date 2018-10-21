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

ll n,m;
ll xx,yy;
ll x[2],y[2];
ll bin[40];
char word[10];
bool ok(ll x,ll y) {
	return 1<=x&&x<=n&&1<=y&&y<=n;
}
bool examine(ll x,ll y) {
	printf("examine %lld %lld\n",x,y);
	fflush(stdout);
	scanf("%s",&word);
	if (word[0]=='t') return 1;
	else return 0;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%lld",&n);
	scanf("%lld %lld",&xx,&yy);
	bin[0]=1;
	FOR(i,32) bin[i]=bin[i-1]*2;
	ll len=0,D=0;
	int f=0;
	
	len=0,D=0,f=0;
	for (int i=0;i<32;i++) {
		len+=bin[i];
		if (!ok(xx,yy+len)||!examine(xx,yy+len)) {
			D=len;
			ll l=0,r=D;
			ll mid=0;
			ll ans=0;
			while (l<=r) {
				mid=(l+r)/2;
				if (!ok(xx,yy+mid)||!examine(xx,yy+mid)) {
					r=mid-1;
				} else {
					ans=mid;
					l=mid+1;
				} 
			}
			y[1]=yy+ans;
			break;
		} 
	}
	len=0,D=0,f=0;
	for (int i=0;i<32;i++) {
		len+=bin[i];
		if (!ok(xx,yy-len)||!examine(xx,yy-len)) {
			D=len;
			ll l=0,r=D;
			ll mid=0;
			ll ans=0;
			while (l<=r) {
				mid=(l+r)/2;
				if (!ok(xx,yy-mid)||!examine(xx,yy-mid)) {
					r=mid-1;
				} else {
					ans=mid;
					l=mid+1;
				} 
			}
			y[0]=yy-ans;
			break;
		} 
	}
	len=0,D=0,f=0;
	for (int i=0;i<32;i++) {
		len+=bin[i];
		if (!ok(xx+len,yy)||!examine(xx+len,yy)) {
			D=len;
			ll l=0,r=D;
			ll mid=0;
			ll ans=0;
			while (l<=r) {
				mid=(l+r)/2;
				if (!ok(xx+mid,yy)||!examine(xx+mid,yy)) {
					r=mid-1;
				} else {
					ans=mid;
					l=mid+1;
				} 
			}
			x[1]=xx+ans;
			break;
		} 
	}
	m=y[1]-y[0]+1;
	x[0]=y[0]+x[1]-y[1];
	xx=x[0]+m/2,yy=y[0]+m/2;
	
	/*
	cout<<x[0]<<" "<<x[1]<<" "<<y[0]<<" "<<y[1]<<endl;
	cout<<xx<<" "<<yy<<" "<<m<<endl;
	*/
	
	ll l,r,mid,ans;
	
	l=0,r=n/(2*m);
	mid=0;
	ans=0;
	while (l<=r) {
		mid=(l+r)/2;
		if (!ok(xx,yy+2*m*mid)||!examine(xx,yy+2*m*mid)) {
			r=mid-1;
		} else {
			ans=mid;
			l=mid+1;
		}
		y[1]=yy+2*m*ans;
	}
	l=0,r=n/(2*m);
	mid=0;
	ans=0;
	while (l<=r) {
		mid=(l+r)/2;
		if (!ok(xx,yy-2*m*mid)||!examine(xx,yy-2*m*mid)) {
			r=mid-1;
		} else {
			ans=mid;
			l=mid+1;
		}
		y[0]=yy-2*m*ans;
	}
	l=0,r=n/(2*m);
	mid=0;
	ans=0;
	while (l<=r) {
		mid=(l+r)/2;
		if (!ok(xx+2*m*mid,yy)||!examine(xx+2*m*mid,yy)) {
			r=mid-1;
		} else {
			ans=mid;
			l=mid+1;
		}
		x[1]=xx+2*m*ans;
	}
	l=0,r=n/(2*m);
	mid=0;
	ans=0;
	while (l<=r) {
		mid=(l+r)/2;
		if (!ok(xx-2*m*mid,yy)||!examine(xx-2*m*mid,yy)) {
			r=mid-1;
		} else {
			ans=mid;
			l=mid+1;
		}
		x[0]=xx-2*m*ans;
	}
	xx=x[0]+x[1],xx/=2;
	yy=y[0]+y[1],yy/=2;
	cout<<"solution "<<xx<<" "<<yy<<endl;
	return 0;
}
