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
const int N=300000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
ll w;
struct node {
	int s,q;
} a[N];
bool cmp(node a,node b) {
	return a.q<b.q;
}
int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(0));
    mt19937 gr(rand());
    
    n=gr()%6+1;
    cout<<n<<endl;
    FOR(i,n) {
    	a[i].s=rand()%20+1,
    	a[i].q=rand()%20+1;
	}
	sort(a+1,a+1+n,cmp);
	FOR(i,n) {
		cout<<a[i].q<<" "<<a[i].s<<endl;
	}
	return 0;
}
