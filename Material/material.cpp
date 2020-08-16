
 //=======KMP========

 int j=0,i=1;
    while(i<m){
        if(b[i]==b[j]){
            lps[i]=j+1;
            j++;i++;
        }
        else {
            if(j>0){j=lps[j-1];}
            else i++;
        }
    }

    while(i<n){
        if(a[i]==b[j]){
            j++;i++;
            if(j==m)cnt++,j=lps[j-1];
        }
        else {
            if(j>0)j=lps[j-1];
            else i++;
        }
    }

//======Articulation Point=====

int num[10005],low[10005],art[10005];
vector<int> e[10005];
int ptr=1;
void findart(int u,int p=0){
    num[u]=low[u]=ptr++;
    int cnt=0;
    for(auto v:e[u]){
        if(num[v]==0){
            findart(v,u);
            low[u]=min(low[u],low[v]);
            cnt++;
            if(p==0&&cnt>1)art[u]=1;
            if(p!=0&&low[v]>=num[u])art[u]=1;
        }
        else if(v!=p)low[u]=min(num[v],low[u]);
    }
}

//=======Convex Hull========
int turn(ii p0,ii p1,ii p2){
    return (p1.f-p0.f)*(p2.s-p0.s)-(p2.f-p0.f)*(p1.s-p0.s);
}
int dist(ii a,ii b){
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}
cmp(ii p1,ii p2){
    int x = turn(p0,p1,p2);
    if(x==0){
        return dist(p0,p1)<dist(p0,p2);
    }
    else
        return x>0;
}
ii p[10005];
vector<ii> s;
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d %d",&p[i].f,&p[i].s);
    sort(p,p+n);
    p0=p[0];
    sort(p+1,p+n,cmp);
    s.pb(p[0]);
    s.pb(p[1]);
    int ptr=1;
    for(int i=2;i<n;i++){
        while(ptr>=1&&turn(s[ptr-1],s[ptr],p[i])<=0){
            s.pop_back();
            ptr--;
        }
        s.pb(p[i]);
        ptr++;
    }
    printf("//ans//\n");
        for(auto i:s)printf("%d %d\n",i.f,i.s);

}

//========LCA========
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m;
int par[N][17], dep[N];
vector<vector<int> > g(N);

void init_lca(int u, int p) {
	dep[u] = dep[p] + 1, par[u][0] = p;
	for(int i = 1; i < 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
	for(int v : g[u]) if(v != p) init_lca(v, u);
}

int get_lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 16; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
	if(a == b) return a;
	for(int i = 16; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
	return par[a][0];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	init_lca(1, 0);
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		printf("lca %d %d : %d\n", u, v, get_lca(u, v));
	}
}