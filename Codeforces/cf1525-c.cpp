#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5*1e5+10;
const ll M=998244353;
int T;
int n;
ll bound;
vector<int> ans;
struct node {
	int id;
	int pos;
	char dir;
}; 
vector<node> a,s;
int m;
bool cmp(node x,node y) {
	return x.pos<y.pos;
}
int main() {
	cin>>T;
	while (T--) {
		cin>>n>>bound;
		m=0;
		s.clear();
		s.resize(n+1);
		ans.clear();
		ans.resize(n+1);
		a.clear();
		a.resize(n+1);
		for (int i=1;i<=n;i++) a[i].id=i;
		for (int i=1;i<=n;i++) cin>>a[i].pos;
		for (int i=1;i<=n;i++) cin>>a[i].dir;

		sort(a.begin()+1,a.end(),cmp);

		for (int i=1;i<=n;i++) if (a[i].pos%2) {
			s[++m]=a[i];
			if (m>=2) {
				int x=s[m-1].pos,y=s[m].pos;
				int idx=s[m-1].id,idy=s[m].id;
				if (s[m-1].dir=='R'&&s[m].dir=='L') {
                    // (y - x) / 2
                    ans[idx]=ans[idy]=(y-x)/2;
                    m-=2;
                }
			}
		}
		// 所有相邻的R L都被消除
		// 只剩下L L L ... R R R
		int h=1,t=m;
		while (t-h>=1) {
            int x=s[t-1].pos,y=s[t].pos;
            int idx=s[t-1].id,idy=s[t].id;
            if (s[t-1].dir=='R'&&s[t].dir=='R') {
                // bound - y + (y - x) / 2 = bound - (x + y) / 2
                ans[idx]=ans[idy]=bound-(x+y)/2;
                t-=2;
            } else break;
        }
        while (t-h>=1) {
            int x=s[h].pos,y=s[h+1].pos;
            int idx=s[h].id,idy=s[h+1].id;
            if (s[h].dir=='L'&&s[h+1].dir=='L') {
                // x + (y - x) / 2 = (x + y) / 2
                ans[idx]=ans[idy]=(x+y)/2;
                h+=2;
            } else break;
        }
        if (t-h>=1) {
        	// 此时只有两个元素
        	int x=s[h].pos,y=s[t].pos;
            int idx=s[h].id,idy=s[t].id;
            if (x<bound-y) {
            	int t=x;
            	y+=x,x=0;
            	// 转为全R的情况
            	ans[idx]=ans[idy]=t+bound-(x+y)/2;
            } else {
            	int t=bound-y;
            	x-=bound-y,y=bound;
            	// 转为全L的情况
            	ans[idx]=ans[idy]=t+(x+y)/2;
            }
        } else for (int i=h;i<=t;i++) ans[s[i].id]=-1;
		s.clear();

		m=0;
		for (int i=1;i<=n;i++) if (a[i].pos%2==0) {
			s[++m]=a[i];
			if (m>=2) {
				int x=s[m-1].pos,y=s[m].pos;
				int idx=s[m-1].id,idy=s[m].id;
				if (s[m-1].dir=='R'&&s[m].dir=='L') {
                    // (y - x) / 2
                    ans[idx]=ans[idy]=(y-x)/2;
                    m-=2;
                }
			}
		}
		// 所有相邻的R L都被消除
		// 只剩下L L L ... R R R
		h=1,t=m;
		while (t-h>=1) {
            int x=s[t-1].pos,y=s[t].pos;
            int idx=s[t-1].id,idy=s[t].id;
            if (s[t-1].dir=='R'&&s[t].dir=='R') {
                // bound - y + (y - x) / 2 = bound - (x + y) / 2
                ans[idx]=ans[idy]=bound-(x+y)/2;
                t-=2;
            } else break;
        }
        while (t-h>=1) {
            int x=s[h].pos,y=s[h+1].pos;
            int idx=s[h].id,idy=s[h+1].id;
            if (s[h].dir=='L'&&s[h+1].dir=='L') {
                // x + (y - x) / 2 = (x + y) / 2
                ans[idx]=ans[idy]=(x+y)/2;
                h+=2;
            } else break;
        }
        if (t-h>=1) {
        	// 此时只有两个元素
        	int x=s[h].pos,y=s[t].pos;
            int idx=s[h].id,idy=s[t].id;
            if (x<bound-y) {
            	int t=x;
            	y+=x,x=0;
            	// 转为全R的情况
            	ans[idx]=ans[idy]=t+bound-(x+y)/2;
            } else {
            	int t=bound-y;
            	x-=bound-y,y=bound;
            	// 转为全L的情况
            	ans[idx]=ans[idy]=t+(x+y)/2;
            }
        } else for (int i=h;i<=t;i++) ans[s[i].id]=-1;
		s.clear();

		for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
