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
const int Q=300000+10; 
const double eps=1e-5;
const int mo=1e9+7;

int m,n;
struct edge {
	int to,nxt,cap;
} e[2*N];
int head[N];
int cnt;
bool vis[N];
int d[N];
queue<int> q;
int s,t;
void insert(int x,int y,int w) {
	e[++cnt].to=y,e[cnt].cap=w,e[cnt].nxt=head[x],head[x]=cnt;
	e[++cnt].to=x,e[cnt].cap=0,e[cnt].nxt=head[y],head[y]=cnt;
}
int dfs(int v,int t,int f) {
	if (v==t) return f;
	vis[v]=1;
	int y;
	for (int i=head[v];i;i=e[i].nxt) {
		y=e[i].to;
		if (!vis[y]&&d[y]==d[v]+1) {
			int ff=min(f,e[i].cap);
			if (ff) {
				int res=dfs(y,t,ff);
				if (res) {
					e[i].cap-=res;
					int j;
					if (i%2) j=i+1;
					else j=i-1;
					e[j].cap+=res;
					vis[v]=0;
					return res;
				}
			}
		}
	}
	vis[v]=0;
	return 0;
}
bool bfs(int s,int t) {
	memset(d,0x3f,sizeof d);
	d[s]=0;
	q.push(s);
	int x,y;
	while (q.size()) {
		x=q.front();q.pop();
		for (int i=head[x];i;i=e[i].nxt) {
			if (e[i].cap==0) continue;
			y=e[i].to;
			if (d[y]==inf) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	if (d[t]==inf) return 0;
	else return 1;
}
int max_flow() {
	int res=0,f;
	while (bfs(s,t)) {
		for (;;) {
			f=dfs(s,t,inf);
			if (!f) break;
			res+=f;
		}
	}
	return res;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d %d %d",&n,&m,&s,&t);
    int x,y,w;
    FOR(i,m) {
    	scanf("%d %d %d",&x,&y,&w);
    	insert(x,y,w);
	}
	cout<<max_flow()<<endl;
	return 0;
}
