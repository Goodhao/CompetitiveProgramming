#include <bits/stdc++.h>
using namespace std;

const int N=5000+10;
int n,k;
int main() {
	cin>>n>>k;
	string s,t="";
	cin>>s;
	bool ok=0;
	while (1) {
		n=s.size();
		for (int i=0;i<n;i++) {
			if (i==n-1) {
				t=s;
				ok=1;
				break;
			} else if (s[i+1]>s[0]) {
				t="";
				for (int j=0;j<=i;j++) t+=s[j];
				break;
			} else if (s[i+1]==s[0]) {
				bool ok2=1;
				for (int k=i+1;k<=n-1;k++) {
					if (s[k]<s[k-i-1]) {
						ok2=0;
						break;
					} else if (s[k]>s[k-i-1]) {
						ok2=1;
						break;
					}
				}
				if (ok2) {
					t="";
					for (int j=0;j<=i;j++) t+=s[j];
					break;
				}
			}
		}
		s=t;
		if (ok) {
			break;
		}
	}
	while ((int)s.size()<k) s=s+s;
	for (int i=0;i<k;i++) cout<<s[i];
	return 0;
}