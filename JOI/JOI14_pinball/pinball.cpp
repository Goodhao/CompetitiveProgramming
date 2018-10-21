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

int m,n;
struct node {
	int l,r,m,w;
} b[N];
int tot;
struct data {
	int val;
	int id;
	int t;
} a[3*N];
int cnt;
ll seg[12*N];
ll ld[N],rd[N];
void build(int k,int l,int r) {
	if (l==r) {
		seg[k]=linf;
		return;
	}
	seg[k]=linf;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void update(int k,int l,int r,int x,ll v) {
	if (l==r) {
		seg[k]=min(seg[k],v);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) update(k<<1,l,mid,x,v);
	else update(k<<1|1,mid+1,r,x,v);
	seg[k]=min(seg[k<<1],seg[k<<1|1]);
}
ll query(int k,int L,int R,int l,int r) {
	if (L==l&&R==r) {
		return seg[k];
	}
	int mid=(L+R)>>1;
	if (r<=mid) {
		return query(k<<1,L,mid,l,r);
	} else if (l>mid) {
		return query(k<<1|1,mid+1,R,l,r);
	} else {
		return min(query(k<<1,L,mid,l,mid),query(k<<1|1,mid+1,R,mid+1,r));
	}
}
bool cmp(data x,data y) {
	return x.val<y.val;
} 
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d",&m,&n);
    a[++tot]=data{1,0,0};
    a[++tot]=data{n,0,0};
    FOR(i,m) {
    	scanf("%d %d %d %d",&b[i].l,&b[i].r,&b[i].m,&b[i].w);
    	a[++tot]=data{b[i].l,i,1};
		a[++tot]=data{b[i].m,i,2};
		a[++tot]=data{b[i].r,i,3};	
	}
	sort(a+1,a+1+tot,cmp);
	FOR(i,tot) {
		if (i==1||a[i].val!=a[i-1].val) {
			++cnt;
		}
		int id=a[i].id;
		if (id==0) continue;
		int t=a[i].t;
		if (t==1) {
			b[id].l=cnt;
		} else if (t==2) {
			b[id].m=cnt;
		} else {
			b[id].r=cnt;
		}
	}
	memset(ld,0x3f,sizeof ld);
	memset(rd,0x3f,sizeof rd);
	build(1,1,cnt);
	FOR(i,m) {
		int l=b[i].l,r=b[i].r;
		ll t=query(1,1,cnt,l,r);
		if (t!=linf) {
			ld[i]=t+b[i].w;
			update(1,1,cnt,b[i].m,t+b[i].w);
		}
		if (b[i].l==1) {
			ld[i]=min(ld[i],1LL*b[i].w);
			update(1,1,cnt,b[i].m,b[i].w);
		}
	}
	build(1,1,cnt);
	FOR(i,m) {
		int l=b[i].l,r=b[i].r;
		ll t=query(1,1,cnt,l,r);
		if (t!=linf) {
			rd[i]=t+b[i].w;
			update(1,1,cnt,b[i].m,t+b[i].w);
		}
		if (b[i].r==cnt) {
			rd[i]=min(rd[i],1LL*b[i].w);
			update(1,1,cnt,b[i].m,b[i].w);
		}
	}
	ll ans=linf;
	FOR(i,m) if (ld[i]!=linf&&rd[i]!=linf) {
		if (b[i].l!=1||b[i].r!=cnt) {
			ans=min(ans,ld[i]+rd[i]-b[i].w);
		}
		else ans=min(ans,1LL*b[i].w);
		
	}
	//FOR(i,m) cout<<ld[i]<<" "<<rd[i]<<endl;
	if (ans!=linf) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}
