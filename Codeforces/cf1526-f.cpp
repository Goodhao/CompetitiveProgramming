#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=5*1e5+10;
const int inf=0x3f3f3f3f;
int T;
int n;
int x,y;
//int arr[N];
int Q(int a,int b,int c) {
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	cout.flush();
	int res=0;
	/*
	int t[3];
	t[0]=abs(arr[a]-arr[b]);
	t[1]=abs(arr[a]-arr[c]);
	t[2]=abs(arr[b]-arr[c]);
	sort(t,t+3);
	res=t[1];
	*/
	cin>>res;
	return res;
}
vector<pair<int,int>> v;
vector<int> p;
vector<int> ans;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>T;
	while (T--) {
		cin>>n;
		//for (int i=1;i<=n;i++) cin>>arr[i];
		p.clear();
		ans.clear();
		v.clear();
		for (int i=1;i<=13;i++) {
			for (int j=i+1;j<=13;j++) {
				for (int k=j+1;k<=13;k++) {
					if (Q(i,j,k)<n/6) {
						x=i,y=j;
					}
				}
			}
		}
		int a=0,b=0;
		for (int i=1;i<=n;i++) if (i!=x&&i!=y) {
			v.push_back(make_pair(Q(i,x,y),i));
		}
		sort(v.begin(),v.end());
		int m=v.size();
		int max_val=v[m-1].first;
		int max_val2=0;
		a=v[m-1].second;
		for (int i=m-1;i>=0;i--)
			if (v[i].first!=max_val) {
				max_val2=v[i].first;
				break;
			}
		vector<int> bb;
		for (int i=m-1;i>=0;i--) {
			if (v[i].first==max_val2) {
				bb.push_back(v[i].second);
			}
		}
		if ((int)bb.size()==1) b=bb[0];
		else if ((int)bb.size()>1) {
			if (Q(bb[0],a,x)+Q(bb[0],a,y)<Q(bb[1],a,x)+Q(bb[1],a,y)) {
				b=bb[0];
			} else b=bb[1];
		}
		ans.resize(n+1);
		ans[1]=a,ans[2]=b;
		for (int i=1;i<=n;i++) if (i!=a&&i!=b) {
			ans[2+Q(i,a,b)]=i;
		}
		p.resize(n+1);
		for (int i=1;i<=n;i++) {
			p[ans[i]]=i;
		}
		cout<<"! ";
		if (p[1]<p[2]) {
			for (int i=1;i<=n;i++) cout<<p[i]<<" ";
		} else {
			for (int i=1;i<=n;i++) cout<<(n+1)-p[i]<<" ";
		}
		cout<<endl;
		cout.flush();
		cin>>n;
	}
	return 0;
}