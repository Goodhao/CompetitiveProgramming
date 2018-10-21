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
const int N=200000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n,x;
int a[N];
int f[N],g[N];
int seg[4*N];
int ans;
struct node {
	int id,val;
} b[N];
bool cmp(node a,node b) {
	return a.val<b.val;
}
void build(int k,int l,int r) {
	if (l==r) {
		seg[k]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	seg[k]=max(seg[k<<1],seg[k<<1|1]);
}
void change(int k,int l,int r,int x,int v) {
	if (l==r) {
		seg[k]=v;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) change(k<<1,l,mid,x,v);
	else change(k<<1|1,mid+1,r,x,v);
	seg[k]=max(seg[k<<1],seg[k<<1|1]); 
}
int query(int k,int L,int R,int l,int r) {
	if (l==L&&r==R) {
		return seg[k];
	}
	int mid=(L+R)>>1;
	if (r<=mid) return query(k<<1,L,mid,l,r);
	else if (l>mid) return query(k<<1|1,mid+1,R,l,r);
	else return max(query(k<<1,L,mid,l,mid),query(k<<1|1,mid+1,R,mid+1,r));
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d",&n,&x);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,n) {
    	b[i].id=i;
    	b[i].val=a[i];
	}
	sort(b+1,b+1+n,cmp);
	int res,id;
	int p=1;
	build(1,1,n);
	FOR(i,n) {
		while (p<=n&&b[p].val<b[i].val) {
			change(1,1,n,b[p].id,f[b[p].id]);
			p++;
		}
		id=b[i].id;
		res=query(1,1,n,1,id);
		f[id]=res+1;
	}
	p=n;
	build(1,1,n);
	for (int i=n;i>=1;i--) {
		while (p>=1&&b[p].val>b[i].val) {
			change(1,1,n,b[p].id,g[b[p].id]);
			p--;
		}
		id=b[i].id;
		res=query(1,1,n,id,n);
		g[id]=res+1;
	}
	/*
	FOR(i,n) {
		cout<<f[i]<<" "<<g[i]<<endl;
	}
	*/
	FOR(i,n) ans=max(ans,f[i]);
	p=1;
	build(1,1,n);
	FOR(i,n) {
		while (p<=n&&b[p].val<b[i].val+x) {
			change(1,1,n,b[p].id,f[b[p].id]);
			p++;
		}
		id=b[i].id;
		res=query(1,1,n,1,id);
		ans=max(ans,res+g[id]);
	}
	p=n;
	build(1,1,n);
	for (int i=n;i>=1;i--) {
		while (p>=1&&b[p].val>b[i].val-x) {
			change(1,1,n,b[p].id,g[b[p].id]);
			p--;
		}
		id=b[i].id;
		res=query(1,1,n,id,n);
		ans=max(ans,res+f[id]);
	}
	cout<<ans<<endl;
	return 0;
}
