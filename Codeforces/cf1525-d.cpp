#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5000+10;
const int inf=0x3f3f3f3f;
int n,m;
int a[N];
int pos[N];
ll f[N][N];
ll ans;
int cost(int x,int id) {
	return abs(x-pos[id]);
}
int main() {
	//freopen("in.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		if (a[i]) {
			pos[++m]=i;
		}
	}
	for (int i=1;i<=n+1;i++) {
		for (int j=0;j<=n+1;j++) {
			f[i][j]=inf;
		}
	}
	f[n+1][m]=0;
	for (int i=n;i>=1;i--) {
		if (a[i]) {
			for (int j=0;j<=n;j++) {
				f[i][j]=f[i+1][j];
			}
		} else {
			for (int j=0;j<=n;j++) {
				f[i][j]=min(cost(i,j+1)+f[i+1][j+1],f[i+1][j]);
			}
		}
	}
	ans=f[1][0];
	cout<<ans<<endl;
	return 0;
}
