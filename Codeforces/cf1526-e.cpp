#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=5*1e5+10;
const ll M=998244353;
int n,k;
int a[N],pos[N];
ll fac[N];
ll bpow(ll a,ll b) {
	ll res=1;
	while (b>0) {
		if (b&1) {
			res*=a;
			res%=M;
		}
		a=a*a%M;
		b>>=1;
	}
	return res;
}
int main() {
	cin>>n>>k;
	for (int i=0;i<=n-1;i++) cin>>a[i];
	for (int i=0;i<=n-1;i++) pos[a[i]]=i;
	pos[n]=-1;
	int cnt=1;
	for (int i=1;i<=n-1;i++) {
		if (pos[a[i-1]+1]>pos[a[i]+1]) {
			cnt++;
		}
	}
	if (cnt>k) {
		cout<<0<<endl;
		return 0;
	}
	fac[0]=1;
	for (int i=1;i<=n+k-cnt;i++) {
		fac[i]=fac[i-1]*i%M;
	}
	cout<<fac[n+k-cnt]*bpow(fac[k-cnt],M-2)%M*bpow(fac[n],M-2)%M<<endl;
	return 0;
}
