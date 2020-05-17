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
vector<int> edge[500000];
bool visit[500000];
int ans=0;
void dfs(int u,int bf,int cnt){
    if(visit[u]==1){ans=max(ans,cnt);return;}
    visit[u]=1;
    for(auto v:edge[u]){
        if(v!=bf)dfs(v,u,cnt+1);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for(int i=0;i<n;i++){
        if(!visit[i]&&edge[i].size()!=0)dfs(i,-1,0);
    }
    printf("%d",ans);
}
