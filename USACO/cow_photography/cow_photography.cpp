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
const int N=20000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
int a[N];
struct node {
	int id,val;
} b[N];
int p[N][6];
int v[N];
int t[N];
bool cmp(node a,node b) {
	return a.val<b.val;
}
bool cmp2(node a,node b) {
	return a.id<b.id;
}
bool LESS(int x,int y) {
	int cnt=0;
	FOR(i,5) if (p[x][i]<p[y][i]) ++cnt;
	return cnt>=3;
}
void change(int a[],int n) {
	b[0].id=0,b[0].val=0;
	FOR(i,n) b[i].id=i,b[i].val=a[i];
	sort(b+1,b+1+n,cmp);
	int cnt=-1;
	int pos=0;
	FOR(i,n) {
		if (i==1||b[i].val!=b[i-1].val) {
			++cnt;
			REP(j,pos,i-1) {
				b[j].val=cnt;
			}
			pos=i;
		}
		if (i==n) {
			++cnt;
			REP(j,pos,i) {
				b[j].val=cnt;
			}
		}
	}
	sort(b+1,b+1+n,cmp2);
	FOR(i,n) v[b[i].val]=a[i],a[i]=b[i].val;
}
void merge_sort(int l,int r) {
	if (l==r) return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i=l,j=mid+1;
	int p=l;
	while (i<=mid||j<=r) {
		if (j>r||i<=mid&&LESS(a[i],a[j])) {
			t[p++]=a[i];
			i++;
		}
		if (i>mid||j<=r&&LESS(a[j],a[i])) {
			t[p++]=a[j];
			j++;
		}
	}
	REP(i,l,r) a[i]=t[i];
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(j,5) {
    	FOR(i,n) {
    		scanf("%d",&a[i]);
		}
		change(a,n);
		//FOR(i,n) cout<<a[i]<<endl;
		FOR(i,n) p[a[i]][j]=i;
	}
	FOR(i,n) a[i]=i;
	merge_sort(1,n);
	FOR(i,n) {
		printf("%d\n",v[a[i]]);
	}
	return 0;
}
