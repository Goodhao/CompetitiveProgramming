#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i=1;i<=n;i++)
#define REP(i,a,b) for (int i=a;i<=b;i++)
 
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define mp make_pair
 
typedef long long ll;

const int inf=0x3f3f3f3f;
const ll linf=1e18;
const int N=2000+10;
const double eps=1e-5;
const int mo=1e9+7;

ll n;
ll k;
string s;
ll l,r,mid,d;
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(0)); 
	cin>>n>>k;
    if (n==1) {
    	cout<<1<<" "<<1<<endl;
    	fflush(stdout);
    	return 0;
	}
	if (n<=100) {
		while (1) {
			ll t=rand()%n+1;
			cout<<t<<" "<<t<<endl;
	    	fflush(stdout);
	    	cin>>s;
	    	if (s[0]=='Y') return 0;
    	}
	}
    l=1,r=n,d=1;
    while (1) {
    	if (r-l+1<=4*k+1) {
    		ll t=l+rand()%(r-l+1);
    		cout<<t<<" "<<t<<endl;
    		fflush(stdout);
    		cin>>s;
    		if (s[0]=='Y') {
    			return 0;
			}
			l=max(l-k,d);
			r=min(r+k,n);
		} else {
			mid=(l+r)>>1;
			cout<<l<<" "<<mid<<endl;
			fflush(stdout);
			cin>>s;
			if (s[0]=='Y') {
				l=max(l-k,d);
				r=min(mid+k,n);
			} else {
				l=max(mid+1-k,d);
				r=min(r+k,n);
			}
		}
	}
    return 0;	
}
