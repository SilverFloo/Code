#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
vector<int> edge[205];
bool visit[205];
int par[205];
int lv[205];
ii q[305];
int so[205][205];
void dfs(int n,int l){
    visit[n]=1;
    lv[n]=l;
    for(auto i:edge[n])if(!visit[i]){par[i]=n,dfs(i,l+1);}
}
bool cmp(ii a,ii b){
    return so[a.f][a.s]>so[b.f][b.s];
}
vector<ii> a;
int ans=305;
int n,m;
vector<ii> tmp;
bool check[205][205];
void find(int cnt,int p){
    if(cnt>10)return;
    if(p==m){
        if(cnt<ans){
            ans=cnt;
            a.clear();
            for(auto i:tmp)a.pb(i);
        }
    }
    bool pass=0;
    int u=q[p].f,v=q[p].s;
    ii ch1={0,0},ch2={0,0};
    while(lv[u]>lv[v]){
        if(check[u][par[u]]){pass=1;break;}
        ch1={u,par[u]};
        u=par[u];
    }
    while(lv[v]>lv[u]){
        if(check[v][par[v]]){pass=1;break;}
        ch2={v,par[v]};
        v=par[v];
    }
    if(!pass){
        while(u!=v){
            if(check[u][par[u]]||check[v][par[v]]){pass=1;break;}
            ch1={u,par[u]};ch2={v,par[v]};
            u=par[u],v=par[v];
        }
    }
    if(pass){
        find(cnt,p+1);
    }
    else{
        if(ch1!=mp(0,0)){
            check[ch1.f][ch1.s]=1;
            tmp.pb(ch1);
            find(cnt+1,p+1);
            tmp.pop_back();
            check[ch1.f][ch1.s]=0;
        }
        if(ch2!=mp(0,0)){
            check[ch2.f][ch2.s]=1;
            tmp.pb(ch2);
            find(cnt+1,p+1);
            check[ch2.f][ch2.s]=0;
            tmp.pop_back();
        }
    }
}
int main(){
    cin>>n>>m;
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1,0);
    FOR(i,m)scanf("%d %d",&q[i].f,&q[i].s);
    FOR(i,m){
        int u=q[i].f;
        int v=q[i].s;
        while(lv[u]>lv[v])u=par[u];
        while(lv[v]>lv[u])v=par[v];
        while(u!=v)u=par[u],v=par[v];
        so[q[i].f][q[i].s]=lv[u];
    }
    sort(q,q+m,cmp);
    //FOR(i,m)printf("/%d %d\n",q[i].f,q[i].s);
    find(0,0);
    printf("%d\n",ans);
    for(auto i:a)printf("%d %d\n",i.f,i.s);
}
