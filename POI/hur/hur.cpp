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
const int N=250000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
int a[N];
int b[N];
ll sum;
struct node {
	int id,val;
	bool operator<(node a) const {
		return val<a.val;
	}
};
priority_queue<node> pq;
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,n) {
    	scanf("%d",&a[i]);
	}
	FOR(i,n) {
		scanf("%d",&b[i]);
		sum+=a[i];
		if (sum>=b[i]) {
			sum-=b[i];
			pq.push(node{i,b[i]});
		} else {
			if (!pq.empty()) {
				node t=pq.top();
				if (t.val>b[i]) {
					sum+=t.val;
					pq.pop();
					sum-=b[i];
					pq.push(node{i,b[i]});
				}
			}
		}
	}
	printf("%d\n",(int)pq.size());
	int cnt=0;
	while (!pq.empty()) {
		node t=pq.top();
		a[++cnt]=t.id;
		pq.pop();
	}
	sort(a+1,a+1+cnt);
	FOR(i,cnt) printf("%d ",a[i]);
	return 0;
}
