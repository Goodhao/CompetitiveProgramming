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
struct edge {
	int to,nxt;
} e[2*N];
int head[N];
int tot;
int d[N];
int cnt;
int leaves[N];
void insert(int x,int y) {
	e[++tot].to=y,e[tot].nxt=head[x],head[x]=tot;
	e[++tot].to=x,e[tot].nxt=head[y],head[y]=tot;
}
void dfs(int x,int fa) {
	int y;
	bool leaf=1;
	for (int i=head[x];i;i=e[i].nxt) {
		y=e[i].to;
		if (y!=fa) {
			dfs(y,x);
			leaf=0;
		}
	}
	cnt+=leaf;
	if (leaf) leaves[cnt]=x;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int x,y;
    FOR(i,n-1) {
    	scanf("%d %d",&x,&y);
    	++d[x],++d[y];
    	insert(x,y);
	}
	int root=0;
	FOR(i,n) if (d[i]!=1) {
		dfs(i,0);
		root=i;
		break;
	}
	int ans=(cnt-1)/2+1;
	printf("%d\n",ans);
	if (cnt%2) {
		for (int i=1;i<=cnt/2;i++) {
			printf("%d %d\n",leaves[i],leaves[i+cnt/2+1]);
		}
		printf("%d %d\n",leaves[cnt/2+1],root);
	} else {
		for (int i=1;i<=cnt/2;i++) {
			printf("%d %d\n",leaves[i],leaves[i+cnt/2]);
		}
	}
	return 0;
}
