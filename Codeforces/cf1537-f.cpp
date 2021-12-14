#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5*1e5+10;
int T;
int n,m;
ll v[N],t[N];
int fa[N],d[N];
vector<int> g[N];
void dfs(int x,int f) {
	fa[x]=f;
	for (auto y : g[x]) {
		if (y!=f) {
			d[x]++;
			dfs(y,x);
		}
	}
}
int main() {
	cin>>T;
	while (T--) {
		cin>>n>>m;
		for (int i=1;i<=n;i++) d[i]=0;
		for (int i=1;i<=n;i++) cin>>v[i];
		for (int i=1;i<=n;i++) cin>>t[i];
		for (int i=1;i<=m;i++) {
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (m>=n) {
			if (n==2) {
				if (t[1]-t[2]==v[1]-v[2]) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			} else cout<<"YES"<<endl;
		} else {
			// m=n-1
			bool ok=0;
			dfs(1,0);
			queue<int> q;
			for (int i=1;i<=n;i++) if (d[i]==0) q.push(i);
			while (!q.empty()) {
				int u=q.front();
				q.pop();
				ll dd=t[u]-v[u];
				if (u==1) {
					// root
					if (dd==0) {
						ok=1;
					}
					break;
				}
				v[u]+=dd;
				v[fa[u]]+=dd;
				if (--d[fa[u]]==0) q.push(fa[u]);
			}
			if (ok) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}