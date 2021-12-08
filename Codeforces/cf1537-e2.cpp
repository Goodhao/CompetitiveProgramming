#include <bits/stdc++.h>
using namespace std;

const int N=5*1e5+10;
int n,k;
set<string> st;
int len[N],len2[N];
int main() {
	cin>>n>>k;
	string s,t="";
	cin>>s;

/*
	len[0]=0;
	for (int i=1;i<n;i++) {
		int t=len[i-1]+1-1;
		while (1) {
			if (s[t]==s[i]) {
				len[i]=len[i-1]+1;
				break;
			} else if (t==1) {
				len[i]=0;
				break;
			} else {
				t=len[t]+1-1;
			}
		}
	}

	for (int i=0;i<n;i++) {
		for (int l=i;l>0;l--) {
			if (s.substr(0,l)==s.substr(i-l+1,l)) {
				len2[i]=l;
				break;
			}
		}
	}
*/
/*
	for (int i=0;i<n;i++) {
		cout<<len[i] <<" "<<len2[i]<<endl;
	}

		return 0;
		*/
	t=s;
	for (int i=0;i<n-1;i++) {
		if (s[i+1]>s[0]) {
			t=s.substr(0,i+1);
			break;
		} else if (s[i+1]==s[0]) {
			if (len[n-1]==n-1-i) {
				t=s.substr(0,i+1);
				break;
			} else {
				for (int j=i+1;j<n;j++) {
					if (s[j]>s[j-i-1]) {
					} else if (s[j]<s[j-i-1]) {
						
					}
				}
			}
		}
	}
	while ((int)t.size()<k) t=t+t;
	t=t.substr(0,k);
	cout<<t<<endl;
	return 0;
}