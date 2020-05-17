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
int dp[305][2005];
typedef struct edge{
int v,w,t;
edge(int v,int w,int t):v(v),w(w),t(t){}
}edge;
vector<edge> e[305];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    FOR1(i,n)FOR(j,k+1)dp[i][j]=-INF;
    int st,ed;
    cin>>st>>ed;
    int ans=-INF;
    FOR(i,m){
    int u,v,w,t;
    scanf("%d %d %d %d",&u,&v,&w,&t);
    e[u].pb(v,w,t);
    e[v].pb(u,w,t);
    }
    dp[st][0]=0;
    FOR(j,k+1){
    FOR1(i,n){//printf("%d ",dp[i][j]);
    if(dp[i][j]>=0){
    for(auto u:e[i]){
            //printf("<%d> ",u.t+j);
    if(u.t+j<=k)dp[u.v][j+u.t]=max(dp[u.v][j+u.t],dp[i][j]+u.w);
    }
    }
    if(i==ed)ans=max(ans,dp[i][j]);
    }//printf("\n");
    }
    if(ans==-INF)printf("Impossible");
    else printf("%d",ans);
}


