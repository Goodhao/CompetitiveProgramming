#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5*1e5+10;
int n;
string _s;
vector<string> s;
int f(string a,string b) {
	set<int> aa,bb;
	for (int i=0;i<(int)a.size();i++) aa.insert(a[i]);
	for (int i=0;i<(int)b.size();i++) bb.insert(b[i]);
	if (aa!=bb) return 0;
	int ans=2;
	string c="",d="";
	for (int l=0;l<(int)a.size();l++) if (ans!=1) {
		for (int r=0;r<(int)b.size();r++) if (ans!=1) {
			d=a.substr(l,r-l+1);
			sort(d.begin(),d.end());
			c=a.substr(0,l)+d+a.substr(r+1,(int)a.size()-1-(r+1)+1);
			if (c==b) ans=1;
		}
	}
	swap(a,b);
	for (int l=0;l<(int)a.size();l++) if (ans!=1) {
		for (int r=0;r<(int)b.size();r++) if (ans!=1) {
			d=a.substr(l,r-l+1);
			sort(d.begin(),d.end());
			c=a.substr(0,l)+d+a.substr(r+1,(int)a.size()-1-(r+1)+1);
			if (c==b) ans=1;
		}
	}
	return ans;
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>_s;
		s.push_back(_s);
	}
	ll ans=0;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			ans+=f(s[i],s[j]);
			cout<<i<<" "<<j<<" "<<f(s[i],s[j])<<endl;
		} 
	}
	cout<<ans<<endl;
	return 0;
}