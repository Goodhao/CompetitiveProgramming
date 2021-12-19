#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=5*1e5+10;
int n;
int a[N];
vector<int> v;
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) a[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;k++) {
				int t[3];
				int &x=t[0],&y=t[1],&z=t[2];
				x=abs(a[i]-a[j]);
				y=abs(a[i]-a[k]);
				z=abs(a[j]-a[k]);
				sort(t,t+3);
				v.push_back(t[1]);
			}
	sort(v.begin(),v.end());
	for (auto x : v) cout<<x<<" ";
	return 0;
}
