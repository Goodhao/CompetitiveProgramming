#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5*1e5+10;
int n,m;
string _s;
struct node {
	string s;
	int idx,idx_p,idx_s;
}
vector<node> s;
bool cmp(node &a,node &b) {
	return a.s<b.s;
}
bool cmp2(node a,node b) {
	reverse(a.s.begin(),a.s.end());
	reverse(b.s.begin(),b.s.end());
	return a.s<b.s;
}
int lcp(string &a,string &b) {
	for (int i=0;i<m;i++) {
		if (a[i]!=b[i]) {
			return i;
		}
	}
	return m;
}
int lcs(string &a,string &b) {
	for (int i=m-1;i>=0;i--) {
		if (a[i]!=b[i]) {
			return m-1-i;
		}
	}
	return m;
}
int f[N],g[N];
// f[i]=lcp(si,s(i+1))
// g[i]=lcs(si,s(i+1))
map<string,vector<int>> c;
ll _hash[5000][5000][2];
const int M1=998244353,M2=1e9+7;
ll inv[N];
ll _lcp[5000][5000],_lcs[5000][5000];
ll _pow[N][2];
bool cmp3(int x,int y) {
	return s[x].idx_p<s[y].idx_p;
}
bool cmp3(int x,int y) {
	return s[x].idx_s<s[y].idx_s;
}
inline int get_lcp(int x,int y) {
	if (x>y) swap(x,y);
	return _lcp[x][y];
}
inline int get_lcs(int x,int y) {
	if (x>y) swap(x,y);
	return _lcs[x][y];
}
int main() {
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>_s;
		s.push_back(node{_s,i,0,0});
	}
	m=s[0].s.size();
	sort(s.begin(),s.end(),cmp);
	for (int i=0;i<n;i++) s[i].idx_p=i;
	sort(s.begin(),s.end(),cmp2);
	for (int i=0;i<n;i++) s[i].idx_s=i;
	int bound=sqrt(2*1e5);
	if (n<=bound) {
		_pow[0][0]=_pow[0][1]=1;
		for (int i=1;i<m;i++) {
			_pow[i][0]=_pow[i-1][0]*26%M1;
			_pow[i][1]=_pow[i-1][1]*26%M2;
		}
		string t="";
		for (int i=0;i<n;i++) {
			t=s[i].s;
			sort(t.begin(),t.end());
			c[t].push_back(i);
			int id=s[i].idx;
			_hash[id][0][0]=s[i].s[0]-'a';
			_hash[id][0][1]=s[i].s[0]-'a';
			for (int j=1;j<m;j++) {
				_hash[id][j][0]=(_hash[id][j-1][0]*26+(s[i].s[j]-'a'))%M1;
				_hash[id][j][1]=(_hash[id][j-1][1]*26+(s[i].s[j]-'a'))%M2;
			}
		}
		for (auto mp : c) {
			auto &v = c.second;
			sort(v.begin(),v.end(),cmp3);
			for (int i=0;i<(int)v.size()-1;i++) {
				f[i]=lcp(s[v[i]].s,s[v[i+1]].s);
			}
			for (int i=0;i<(int)v.size()-1;i++) {
				for (int j=i+1;j<(int)v.size();j++) {
					if (j==i+1) _lcp[i][j]=f[i];
					else _lcp[i][j]=min(_lcp[i][j-1],f[j-1]);
				}
			}
			sort(v.begin(),v.end(),cmp4);
			for (int i=0;i<(int)v.size()-1;i++) {
				g[i]=lcs(s[v[i]].s,s[v[i+1]].s);
			}
			for (int i=0;i<(int)v.size()-1;i++) {
				for (int j=i+1;j<(int)v.size();j++) {
					if (j==i+1) _lcs[i][j]=g[i];
					else _lcs[i][j]=min(_lcs[i][j-1],g[j-1]);
				}
			}
			for (int i=0;i<(int)v.size();i++) {
				for (int j=i+1;j<(int)v.size();j++) {
					int x=v[i],y=v[j];
					int l1=get_lcp(s[x].idx_p,s[y].idx_p);
					int l2=get_lcs(s[x].idx_s,s[y].idx_s);
					int id1=s[x].idx,id2=s[y].idx;
					ll seg_hash0=(_hash[id1][m-l2-1][0]-_hash[id1][l1-1][0]*_pow[m-l1-l2])%M1;
					ll seg_hash1=(_hash[id1][m-l2-1][1]-_hash[id1][l1-1][1]*_pow[m-l1-l2])%M2;
					ll seg_hash2=(_hash[id2][m-l2-1][0]-_hash[id2][l1-1][0]*_pow[m-l1-l2])%M1;
					ll seg_hash3=(_hash[id2][m-l2-1][1]-_hash[id2][l1-1][1]*_pow[m-l1-l2])%M2;
					seg_hash0=(seg_hash0+M1)%M1;
					seg_hash2=(seg_hash2+M1)%M1;
					seg_hash1=(seg_hash1+M2)%M2;
					seg_hash3=(seg_hash3+M2)%M2;
					if (seg_hash0==seg_hash2&&seg_hash1==seg_hash3) {
						
					}
				}
			}
		}
	}
	return 0;
}