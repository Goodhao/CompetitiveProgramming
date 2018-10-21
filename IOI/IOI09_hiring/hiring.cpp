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
const int N=500000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
ll w;
struct node {
	int id,s,q;
	bool operator<(node b) const {
		return s*b.q<b.s*q;
	}
} a[N];
ll b[N];
priority_queue<int> pq;
struct cmp2 {
	bool operator()(const node a,const node b) const {
		return a.q<b.q;
	}
};
priority_queue<node,vector<node>,cmp2> worker;
ll sum;
int ans;
node p[N];
bool cmp(node a,node b) {
	return a.id<b.id;
}
bool check(int x) {
	FOR(i,n) {
		if (b[i]!=-1) {
			if (w*a[i].q>=a[i].s*b[i]) return 1;
		}
	}
	return 0;
}
void solve() {
	int l=0,r=n;
	int mid;
	ll qsum=0;
	while (l<=r) {
		mid=(l+r)>>1;
		while (pq.size()) pq.pop();
		qsum=0;
		FOR(i,n) {
			pq.push(a[i].q);
			qsum+=a[i].q;
			if (pq.size()>mid) {
				qsum-=pq.top();
				pq.pop();
			}
			if (pq.size()==mid) {
				b[i]=qsum;
			} else b[i]=-1;
		}
		if (check(mid)) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
}
void copy() {
	int cnt=0;
	while (worker.size()) {
		p[++cnt]=worker.top();
		worker.pop();
	}
	FOR(i,cnt) worker.push(p[i]);
}
void get() {
	double answ=w;
	ll sum=0;
	FOR(i,n) {
		sum+=a[i].q;
		worker.push(a[i]);
		if (worker.size()>ans) {
			node t=worker.top();
			sum-=t.q;
			worker.pop();
		}
		if (worker.size()<ans) continue;
		double res=(double)a[i].s*sum/a[i].q;
		if (res<=answ) {
			answ=res;
			copy();
		}
	}
}
int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %lld",&n,&w);
    FOR(i,n) {
    	scanf("%d %d",&a[i].s,&a[i].q);
    	a[i].id=i;
    	sum+=a[i].q;
	}
	sort(a+1,a+1+n);
	solve();
	get();
	sort(p+1,p+1+ans,cmp);
	cout<<ans<<endl;
	FOR(i,ans) cout<<p[i].id<<endl;
	return 0;
}
