#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
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
vector<int> edge[30005];
int par[30005];
int level[30005];
void dfs(int u,int lv){
    level[u]=lv;
    for(auto v:edge[u]){
            if(v==par[u])continue;
        par[v]=u;
        dfs(v,lv+1);
    }
}
int main(){
    int n;
    cin>>n;
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1,0);
    int q;
    cin>>q;
    int st=1,ed;
    int ans=0;
    while(q--){
        scanf("%d",&ed);
        int cnt=0;
        int x=ed;
        while(level[st]>level[ed]){st=par[st],cnt++;}
        while(level[ed]>level[st]){ed=par[ed],cnt++;}
        while(st!=ed)st=par[st],ed=par[ed],cnt+=2;
        ans+=cnt;
         st=x;
    }
    printf("%d",ans);
}
