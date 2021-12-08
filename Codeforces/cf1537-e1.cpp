#include <bits/stdc++.h>
using namespace std;

const int N=5000+10;
int n,k;
set<string> st;
int main() {
	cin>>n>>k;
	string s,t="";
	cin>>s;
	for (int i=0;i<n;i++) {
		t="";
		for (int j=0;j<=i;j++) t+=s[j];
		while ((int)t.size()<k) t=t+t;
		t=t.substr(0,k);
		st.insert(t);
	}
	cout<<*st.begin()<<endl;
	return 0;
}