#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5000+10;
int n,m;
int a[N];
unordered_map<ll,unordered_map<ll,ll>> f,g;
//map<ll,map<ll,ll>> f;
int pos[N],len[N],lenl[N],lenr[N];
const int inf=0x3f3f3f3f;
int cost(int a,int b) {
	return b*b+(a-b)*(a-b);
}
void update(ll &x,ll y) {
	x=min(x,y);
}
ll solve(int a[],unordered_map<ll,unordered_map<ll,ll>> &f) {
	fill(pos,pos+1+n,0);
	fill(len,len+1+n,0);
	fill(lenl,lenl+1+n,0);
	fill(lenr,lenr+1+n,0);
	f.clear();
	int cur=0;
	m=0;
	for (int i=1;i<=n;i++) {
		if (a[i]) {
			if (i==1||a[i-1]==0) {
				pos[++m]=i;
				len[m]=1;
				lenl[m]=cur;
			} else {
				len[m]++;
			}
			cur=0;
		} else {
			++cur;
		}
	}
	if (m==0) {
		return 0;
	}
	for (int i=1;i<=m-1;i++) {
		lenr[i]=pos[i+1]-pos[i]-len[i];
	}
	lenr[m]=n+1-pos[m]-len[m];
	// keep f[m+1][>=0]=0, f[m+1][<0]=inf
	for (int i=-n;i<=-1;i++) f[m+1][i]=inf;
	for (int i=m;i>=1;i--) {
		for (int j=-n;j<=lenl[i];j++) {
			f[i][j]=inf;
			if (j<0) {
				int k=len[i];
				if (lenr[i]-k-abs(j)>=-n) update(f[i][j],2*k*abs(j)+cost(len[i],k)+f[i+1][lenr[i]-k-abs(j)]);
			} else for (int k=max(0,len[i]-j);k<=len[i];k++) {
				if (lenr[i]-k>=-n) update(f[i][j],cost(len[i],k)+f[i+1][lenr[i]-k]);
			}
		}
	}
	return f[1][lenl[1]];
}
int main() {
	//freopen("in.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	ll ans=inf;
	for (int i=1;i<=n/2;i++) swap(a[i],a[n+1-i]);
	
	for (int i=1;i<=m;i++) {
		for (int lencut=0;lencut<=lenr[i];i++) {
			
		}
	}
	return 0;
}
