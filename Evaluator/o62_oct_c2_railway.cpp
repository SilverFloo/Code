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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
vector<ii> e[100005];
ii edge[200005];
int par[100005];
int cost[100005];
ii want[100005];
int have[100005];
int lv[100005];
int ans[100005];
void find(int u){
              //  printf("%d -> %d %d %d\n",u,par[u],cost[u],lv[u]);
    for(auto v:e[u]){
        if(par[v.f]==0){
            par[v.f]=u;
            cost[v.f]=v.s;
            lv[v.f]=lv[u]+1;
            find(v.f);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int xx;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        xx=a;
        e[a].pb(b,c);
        e[b].pb(a,c);
    }
    for(int i=0;i<m-n+1;i++){
        scanf("%d %d %d",&edge[i].f,&edge[i].s,&have[i]);
    }
    par[xx]=-1;
    find(xx);
    for(int i=0;i<m-n+1;i++){
        int u=edge[i].f;
        int v=edge[i].s;
        int mx=0;
        while(lv[u]>lv[v]){
            mx=max(mx,cost[u]);
            u=par[u];
        }
        while(lv[v]>lv[u]){
            mx=max(mx,cost[v]);
            v=par[v];
        }
        while(u!=v){
            mx=max(max(mx,cost[u]),cost[v]);
            u=par[u];
            v=par[v];
        }
        //printf("%d ",mx);
        want[i].f=mx;
        want[i].s=i;
    }
    sort(want,want+m-n+1);
    sort(have,have+m-n+1);
    for(int i=0;i<m-n+1;i++){
        if(have[i]>want[i].f){
            ans[want[i].s]=have[i];
        }
        else{
            printf("0");
            return 0;
        }
    }
    printf("1\n");
    for(int i=0;i<m-n+1;i++){
        printf("%d\n",ans[i]);
    }
}
