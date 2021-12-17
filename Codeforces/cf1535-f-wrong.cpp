#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5*1e5+10;
int n,m;
string _s;
vector<string> s;
int longest_suffix_len(string &a,string &b) {
	int n=a.size();
	for (int i=n-1;i>=0;i--) {
		if (a[i]!=b[i]) {
			return n-1-i;
		}
	}
	return n;
}
map<pair<int,int>,int> rightmost_end;
map<pair<int,char>,int> Tire;
map<int,vector<int>> Tire_point_start;
int Tire_size;
map<pair<int,int>,int> to_Tire;
map<pair<int,int>,int> cnt;
map<int,int> to_str;
void split(string &s,int idx) {
	int n=s.size();
	int last=0;
	for (int i=0;i<n;i++) {
		if (i==0) {
			Tire_point_start[to_Tire[make_pair(idx,i)]].push_back(idx);
			last=i;
		}
		else if (s[i]<s[i-1]) {
			Tire_point_start[to_Tire[make_pair(idx,i)]].push_back(idx);
			for (int j=last;j<=i-1;j++) rightmost_end[make_pair(idx,j)]=i-1;
			last=i;
		}
		else if (i==n-1) {
			for (int j=last;j<=i;j++) rightmost_end[make_pair(idx,j)]=i;
		}
	}
}
void insert(string &s,int idx) {
	// idx: 0 ~ n-1
	if (Tire_size==0) Tire_size++;
	int n=s.size();
	int cur=0;
	for (int i=0;i<n;i++) {
		int nxt=Tire[make_pair(cur,s[i])];
		if (!nxt) {
			nxt=Tire_size;
			Tire[make_pair(cur,s[i])]=nxt;
			Tire_size++;
		}
		cur=nxt;
		to_Tire[make_pair(idx,i)]=cur;
	}
	to_str[cur]=idx;
}
stack<pair<vector<int>,int>> ancestor;
void dfs(int x,int dep) {
	if (dep==m&&!ancestor.empty()) {
		vector<int> last=ancestor.top().first;
		int d=ancestor.top().second;
		for (auto i : last) {
			int len=longest_suffix_len(s[i],s[to_str[x]]);
			int pos=rightmost_end[make_pair(i,d-1)];
			if (m-len<=pos+1&&i<to_str[x]) {
				cnt[make_pair(i,d-1)]++;
				cout<<s[to_str[x]]<<"!!"<<endl;
			}
		}
	}
	if (!Tire_point_start[x].empty()) ancestor.push(make_pair(Tire_point_start[x],dep));
	for (char c='a';c<='z';c++) {
		int y=Tire[make_pair(x,c)];
		if (y) {
			dfs(y,dep+1);
		}
	}
	if (!Tire_point_start[x].empty()) ancestor.pop();
}
ll ans,ANS;
vector<int> sz;
map<string,vector<int>> arrange;
void init() {
	Tire.clear();
	Tire_point_start.clear();
	Tire_size=0;
	to_str.clear();
	while (!ancestor.empty()) ancestor.pop();
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>_s;
		_s="a"+_s;
		s.push_back(_s);
	}
	sort(s.begin(),s.end());
	m=s[0].size();
	string t="";
	for (int i=0;i<n;i++) {
		t=s[i];
		sort(t.begin(),t.end());
		arrange[t].push_back(i);
	}
	for (auto mp : arrange) {
		init();
		for (auto i : mp.second) insert(s[i],i);
		for (auto i : mp.second) split(s[i],i);
		sz.push_back(mp.second.size());
		dfs(0,0);
		ans=0;
		for (auto i : mp.second) {
			int f=0;
			for (int j=0;j<m;j++) {
				f+=cnt[make_pair(i,j)];
			}
			cout<<s[i]<<" "<<f<<endl;
			f+=(sz.back()-1-f);
			ans+=f;
		}
		cout<<"----"<<endl;
		cout<<ans<<endl;
		ANS+=ans;
	}
	ans=0;
	for (int x : sz) {
		ans+=1337ll*x*(n-x);
	}
	ANS+=ans/2;
	cout<<ANS<<endl;
	return 0;
}