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
const int N=3000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
int f;
struct node {
	int id;
	int a,b,c,d;
	bool operator<(node x) const {
		if (!f) return c>x.c;
		else return d>x.d;
	} 
} m[N];
priority_queue<node> pq;
int ans[N][2];
bool cmp(node x,node y) {
	if (x.a==y.a) return x.c<y.c;
	return x.a<y.a;
} 
bool cmp2(node x,node y) {
	if (x.b==y.b) return x.d<y.d;
	return x.b<y.b;
} 
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,n) {
    	node &t=m[i];
    	scanf("%d %d %d %d",&t.a,&t.b,&t.c,&t.d);
    	t.id=i;
	}
	sort(m+1,m+1+n,cmp);
	node t;
	int p=1;
	FOR(i,n) {
		while (p<=n&&m[p].a==i) {
			pq.push(m[p++]);
		}
		if (!pq.empty()) {
			t=pq.top();
			if (t.c<i) {
				printf("NIE\n");
				return 0;
			}
			ans[t.id][0]=i;
			pq.pop();
			
		} else {
			printf("NIE\n");
			return 0;
		}
	}
	sort(m+1,m+1+n,cmp2);
	p=1;
	f=1;
	FOR(i,n) {
		while (p<=n&&m[p].b==i) {
			pq.push(m[p++]);
		}
		if (!pq.empty()) {
			t=pq.top();
			if (t.d<i) {
				printf("NIE\n");
				return 0;
			}
			ans[t.id][1]=i;
			pq.pop();
			
		} else {
			printf("NIE\n");
			return 0;
		}
	}
	FOR(i,n) {
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}
