#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=5*1e5+10;
int n,m;
string _s;
vector<string> s;
int idx[N];
bool cmp_prefix(int x,int y) {
	return s[x]<s[y];
}
bool cmp_suffix(int x,int y) {
	string a=s[x],b=s[y];
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	return a<b;
}
/*
int LCP(string &a,string &b) {
	for (int i=0;i<m;i++) {
		if (a[i]!=b[i]) {
			return i;
		}
	}
	return m;
}
int LCS(string &a,string &b) {
	for (int i=m-1;i>=0;i--) {
		if (a[i]!=b[i]) {
			return m-1-i;
		}
	}
	return m;
}*/
int LCP(vector<pair<ll,ll>> _hash[],int x,int y) {
	int l=0,r=m-1;
	int mid=0,ok=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (_hash[x][mid]==_hash[y][mid]) {
			ok=mid;
			l=mid+1;
		} else r=mid-1;
	}
	ok++;
	return ok;
}
int LCS(vector<pair<ll,ll>> _hash2[],int x,int y) {
	int l=0,r=m-1;
	int mid=0,ok=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (_hash2[x][mid]==_hash2[y][mid]) {
			ok=mid;
			r=mid-1;
		} else l=mid+1;
	}
	if (ok==-1) return 0;
	else return m-ok;
}
int f[N],g[N];
int lcp[10001][10001],lcs[10001][10001];
//vector<int> rightmost[N];
vector<int> to[N];
vector<int> cnt;
/*
int find(int idx,int x) {
	int l=0,r=rightmost[idx].size()-1;
	int mid,ok=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (x<=rightmost[idx][mid]) {
			ok=mid;
			r=mid-1;
		} else l=mid+1;
	}
	return (ok==-1)?(-1):rightmost[idx][ok];
}*/
struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2> &pair) const
	{
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};
int main() {
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>_s;
		s.push_back(_s);
	}
	m=s[0].size();
	int bound=1e8;
	if (n<=9000) {
	//if (0) {
		ll M1=998244353,M2=1e9+7;
 		vector<pair<ll,ll>> _hash[N],_hash2[N];
		for (int i=0;i<n;i++) _hash[i].resize(m);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
			if (j==0) _hash[i][j]=make_pair(s[i][j]-'a'+1,s[i][j]-'a'+1);
			else _hash[i][j]=make_pair((_hash[i][j-1].first*27+(s[i][j]-'a'+1))%M1,(_hash[i][j-1].second*27+(s[i][j]-'a'+1))%M2);
		}
		for (int i=0;i<n;i++) _hash2[i].resize(m);
		for (int i=0;i<n;i++) for (int j=m-1;j>=0;j--) {
			if (j==m-1) _hash2[i][j]=make_pair(s[i][j]-'a'+1,s[i][j]-'a'+1);
			else _hash2[i][j]=make_pair((_hash2[i][j+1].first*27+(s[i][j]-'a'+1))%M1,(_hash2[i][j+1].second*27+(s[i][j]-'a'+1))%M2);
		}
		
		for (int i=0;i<n;i++) {
			to[i].resize(m);
			auto &t=s[i];
			int last=0;
			for (int j=1;j<m;j++) {
				if (t[j]<t[j-1]) {
					//rightmost[i].push_back(j-1);
					for (int k=last;k<=j-1;k++) {
						to[i][k]=j-1;
					}
					last=j;
				}
			}
			for (int k=last;k<=m-1;k++) {
				to[i][k]=m-1;
			}
			//rightmost[i].push_back(m-1);
		}
		unordered_map<string,vector<int>> c;
		for (int i=0;i<n;i++) {
			string t=s[i];
			sort(t.begin(),t.end());
			c[t].push_back(i);
		}
		ll ans=0;
		for (auto &e : c) {
			auto &v = e.second;
			int _n=v.size();
			cnt.push_back(_n);
			ll res=0;
			sort(v.begin(),v.end(),cmp_prefix);
			for (int i=0;i<_n-1;i++) f[i]=LCP(_hash,v[i],v[i+1]);
			for (int i=0;i<_n-1;i++) for (int j=i+1;j<_n;j++) {
				int x=v[i],y=v[j];
				if (j==i+1) lcp[x][y]=lcp[y][x]=f[j-1];
				else lcp[x][y]=lcp[y][x]=min(f[j-1],lcp[x][v[j-1]]);
			}
			sort(v.begin(),v.end(),cmp_suffix);
			for (int i=0;i<_n-1;i++) g[i]=LCS(_hash2,v[i],v[i+1]);
			for (int i=0;i<_n-1;i++) for (int j=i+1;j<_n;j++) {
				int x=v[i],y=v[j];
				if (j==i+1) lcs[x][y]=lcs[y][x]=g[j-1];
				else lcs[x][y]=lcs[y][x]=min(g[j-1],lcs[x][v[j-1]]);
			}
			for (int i=0;i<_n;i++) {
				for (int j=i+1;j<_n;j++) {
					int x=v[i],y=v[j];
					int len[2];
					len[0]=lcp[x][y],len[1]=lcs[x][y];
					int l=len[0],r=m-len[1]-1;
					//cout<<s[x]<<" "<<s[y]<<" "<<l<<" "<<r<<" "<<find(x,l)<<","<<find(y,l)<<" ";
					if (to[x][l]>=r||to[y][l]>=r) {
						res++;
					} else {
						res+=2;
					}
				}
			}
			ans+=res;
		}
		ll delta=0;
		for (int i=0;i<(int)cnt.size();i++) {
			int x=cnt[i];
			delta+=1337ll*x*(n-x);
		}
		ans+=delta/2;
		cout<<ans<<endl;
	} else {
		ll M1=998244353,M2=1e9+7;
 
		ll _pow[30][2];
		// m <= 20
		_pow[0][0]=_pow[0][1]=1;
		for (int i=1;i<m;i++) {
			_pow[i][0]=_pow[i-1][0]*27%M1;
			_pow[i][1]=_pow[i-1][1]*27%M2;
		}
 
		vector<pair<ll,ll>> _hash[N];
		for (int i=0;i<n;i++) _hash[i].resize(m);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
			if (j==0) _hash[i][j]=make_pair(s[i][j]-'a'+1,s[i][j]-'a'+1);
			else _hash[i][j]=make_pair((_hash[i][j-1].first*27+(s[i][j]-'a'+1))%M1,(_hash[i][j-1].second*27+(s[i][j]-'a'+1))%M2);
		}
		int chr_cnt[30];
		unordered_map<string,vector<int>> c;
		for (int i=0;i<n;i++) {
			string t=s[i];
			sort(t.begin(),t.end());
			c[t].push_back(i);
		}
		ll ans=0;
		for (auto &e : c) {
			auto &v = e.second;
			int _n=v.size();
			cnt.push_back(_n);
			ll res=0;
			unordered_set<pair<ll,ll>,pair_hash> _set;
			for (int ii=0;ii<_n;ii++) _set.insert(_hash[v[ii]][m-1]);
			unordered_map<pair<ll,ll>,int,pair_hash> be_target;
			vector<unordered_set<pair<ll,ll>,pair_hash>> Record;
			Record.resize(_n);
			for (int ii=0;ii<_n;ii++) {
				int i=v[ii];
				auto &record=Record[ii];
				pair<ll,ll> self_hash=_hash[i][m-1];
				for (int l=0;l<m;l++) {
					fill(chr_cnt,chr_cnt+30,0);
					for (int r=l;r<m;r++) {
						chr_cnt[s[i][r]-'a'+1]++;
						ll local_hash[2]={0};
						for (int chr=1;chr<=26;chr++) {
							for (int j=0;j<chr_cnt[chr];j++) {
								local_hash[0]=(local_hash[0]*27+chr)%M1;
								local_hash[1]=(local_hash[1]*27+chr)%M2;
							}
						}
						pair<ll,ll> t;
						t.first=((l>0?(_hash[i][l-1].first*_pow[m-1-(l-1)][0]):0)+
						local_hash[0]*_pow[m-1-r][0]+
						(_hash[i][m-1].first-_hash[i][r].first*_pow[m-1-r][0]))%M1;
						t.first=(t.first+M1)%M1;
						t.second=((l>0?(_hash[i][l-1].second*_pow[m-1-(l-1)][1]):0)+
						local_hash[1]*_pow[m-1-r][1]+
						(_hash[i][m-1].second-_hash[i][r].second*_pow[m-1-r][1]))%M2;
						t.second=(t.second+M2)%M2;
						//cout<<s[i]<<" "<<local_hash[0]<<" "<<local_hash[1]<<" "<<l<<" "<<r<<" "<<t.first<<" "<<t.second<<endl;
						if (t!=self_hash&&_set.count(t)) {
							pair<ll,ll> tmp=*_set.find(t);
							if (!record.count(tmp)) {
								record.insert(tmp);
								be_target[tmp]++;
							}
						}
					}
				}
			}
			for (int ii=0;ii<_n;ii++) {
				int i=v[ii];
				auto &record=Record[ii];
				int one=record.size()+be_target[_hash[i][m-1]];
				int two=2*(_n-1-one);
				//cout<<s[i]<<" "<<one<<" "<<two/2<<endl;
				res+=one+two;
			}
			//cout<<res<<endl;
			ans+=res;
		}
		ll delta=0;
		for (int i=0;i<(int)cnt.size();i++) {
			int x=cnt[i];
			delta+=1337ll*x*(n-x);
		}
		ans+=delta;
		ans/=2;
		cout<<ans<<endl;
	}
	return 0;
}
