#include <bits/stdc++.h>
using namespace std;

const int N = 2*1e5;
int n,m,c,q;
int tot;
map<int,int> a[N];
int fa[2*N];
int find(int x) {
    return (x==fa[x]) ? x : fa[x] = find(fa[x]);
}
void unite(int x,int y) {
    int u=find(x),v=find(y);
    fa[u]=v;
}
void insert(int x,int y,int z) {
    int u,v;
    if (!a[x].count(z)) a[x][z]=++tot,fa[tot]=tot;
    if (!a[y].count(z)) a[y][z]=++tot,fa[tot]=tot;
    u=a[x][z];
    v=a[y][z];
    unite(u,v);
    unite(u,a[x].begin()->second);
    unite(v,a[y].begin()->second);
}
int main() {
    cin>>n>>m>>c>>q;
    for (int i=0;i<m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        insert(x,y,z);
    }
    for (int i=0;i<q;i++) {
        string op;
        int x,y,z;
        cin>>op>>x>>y;
        if (op=="?") {
            int ok=0;
            if (!a[x].empty()&&!a[y].empty()&&find(a[x].begin()->second)==find(a[y].begin()->second)) ok=1;
            if (ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        } else if (op=="+") {
            cin>>z;
            insert(x,y,z);
        }
    }
    return 0;
}