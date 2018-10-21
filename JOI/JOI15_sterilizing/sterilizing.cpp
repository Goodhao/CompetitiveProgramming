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
int tag[4*N];
queue<ll> seg[4*N];
void down(int k,int l,int r) {
	int cnt=tag[k];
	while ((int)seg[k].size()&&cnt>0) {
		seg[k].pop();
		cnt--;
	}
	if (l==r) {
		tag[k]=0;
		return;
	}
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
ll get(queue<ll> &a) {
	if (a.size()) return a.front();
	else return 0;
}
void update(int k,int l,int r) {
	while (seg[k].size()) {
		seg[k].pop();
	}
	if (l==r) return;
	queue<ll> a=seg[k<<1],b=seg[k<<1|1];
	if ((int)a.size()<(int)b.size()) swap(a,b);
	while (a.size()) {
		seg[k].push(get(a)+get(b));
		a.pop();
		if (b.size()) {
			b.pop();	
		}
	}
}
void change(int k,int l,int r,int x,int v) {
	if (l==r) {
		tag[k]=0;
		while (seg[k].size()) seg[k].pop();
		while (v) {
			seg[k].push(v);
			v/=KK;
			if (KK==1) break;
		}
	} else {
		down(k,l,r);
		int mid=(l+r)>>1;
		if (x<=mid) {
			change(k<<1,l,mid,x,v);
			down(k<<1|1,mid+1,r);
		} else {
			change(k<<1|1,mid+1,r,x,v);
			down(k<<1,l,mid);
		}
		update(k,l,r);
	}
}
void spray(int k,int L,int R,int l,int r) {
	down(k,L,R);
	if (l==L&&r==R) {
		if (seg[k].size()) seg[k].pop();
		if (l!=r) {
			tag[k<<1]++;
			tag[k<<1|1]++;
		}
		return;
	}
	int mid=(L+R)>>1;
	if (r<=mid) {
		spray(k<<1,L,mid,l,r);
		down(k<<1|1,mid+1,R);
		update(k,L,R);
	} else if (l>mid) {
		spray(k<<1|1,mid+1,R,l,r);
		down(k<<1,L,mid);
		update(k,L,R);
	} else {
		spray(k<<1,L,mid,l,mid);
		spray(k<<1|1,mid+1,R,mid+1,r);
		update(k,L,R);
	}
}
ll query(int k,int L,int R,int l,int r) {
	down(k,L,R);
	if (l==L&&r==R) {
		return get(seg[k]);
	} else {
		int mid=(L+R)>>1;
		if (r<=mid) {
			return query(k<<1,L,mid,l,r);
		} else if (l>mid) {
			return query(k<<1|1,mid+1,R,l,r);
		} else {
			return query(k<<1,L,mid,l,mid)+query(k<<1|1,mid+1,R,mid+1,r);
		}
	}
}
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
    	change(1,1,n,i,t);
	}
	/*
	FOR(i,7) {
		queue<ll> q=seg[i];
		while (q.size()) {
			cout<<q.front()<<" ";
			q.pop();
		}
		cout<<endl;
	}*/
	
	int s,l,r;
	FOR(i,q) {
		scanf("%d %d %d",&s,&l,&r);
		if (s==1) {
			change(1,1,n,l,r);
		} else if (s==2) {
			if (KK==1) continue;
			spray(1,1,n,l,r); 
		} else {
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
	return 0;
}
