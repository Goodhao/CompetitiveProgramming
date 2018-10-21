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
const int N=10000+10;
const double eps=1e-5;
const int mo=1e9+7;

int n;
int a[N];
int b[N];
int bin[N];
bool move[N];
bool cmp(int a,int b) {
	return gr()%2;
}
int main() {
 
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(0));
    mt19937 gr(rand());
    
    n=gr()%7+1;
    cout<<n<<endl;
    FOR(i,n) a[i]=i;
    sort(a+1,a+1+n,cmp);
    bin[0]=1;
    FOR(i,n) bin[i]=bin[i-1]*2;
    FOR(j,5) {
    	FOR(i,n) b[i]=a[i];
    	bool flag=0;
    	int t=0;
    	while (1) {
    		int i=gr()%bin[n];
    		flag=0;
    		FOR(k,n) {
    			if (i&bin[k-1]) {
    				if (move[k]) {
    					flag=1;
    					break;
					}
				}
			}
			if (flag) continue;
			else {
				FOR(k,n) {
					if (i&bin[k-1]) {
    					move[k]=1;
					}
				}
				t=i;
				break;
			}
		}
    	FOR(i,n) {
    		
		}
	}
	return 0;
}
