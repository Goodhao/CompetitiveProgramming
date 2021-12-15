#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5*1e5+10;
int T;
int n,m;
ll v[N],t[N];
bool vis[N];
vector<int> g[N];
vector<pair<int,int>> e;
int color[N];
void dfs(int x,int c) {
	vis[x]=1;
	color[x]=c;
	for (auto y : g[x]) {
		if (!vis[y]) {
			dfs(y,~c);
		}
	}
}
int main() {
	cin>>T;
	while (T--) {
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>v[i];
		for (int i=1;i<=n;i++) cin>>t[i];
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n;i++) color[i]=0,vis[i]=0;
		e.clear();
		for (int i=1;i<=m;i++) {
			int x,y;
			cin>>x>>y;
			e.push_back(make_pair(x,y));
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		bool check=0;
		ll ts=0,vs=0;
		for (int i=1;i<=n;i++) ts+=t[i],vs+=v[i];
		if ((ts-vs)%2) {
			cout<<"NO"<<endl;
			check=1;
		}
		if (!check) for (auto ee : e) {
			int x = ee.first, y = ee.second;
			if (color[x]==color[y]) {
				// non-bipartite
				cout<<"YES"<<endl;
				check=1;
				break;
			}
		}
		if (!check) {
			ll s1=0,s2=0;
			for (int i=1;i<=n;i++) {
				if (color[i]==0) s1+=t[i]-v[i];
				else s2+=t[i]-v[i];
			}
			if (s1==s2) {
				cout<<"YES"<<endl;
				check=1;
			} else {
				cout<<"NO"<<endl;
				check=1;
			}
		}
	}
	return 0;
}