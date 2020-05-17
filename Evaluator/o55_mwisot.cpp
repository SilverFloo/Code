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
int val[100005];
int dp[100005];
vector<int> edge[100005];
void dfs(int u,int par){
    int l=0,r=0;
    for(auto v:edge[u]){
        if(v!=par)dfs(v,u);
    }
    for(auto v:edge[u]){
        if(v==par)continue;
        for(auto i:edge[v]){
            if(i!=v)r+=dp[i];
        }
        l+=dp[v];
    }
    dp[u]=max(l,r+val[u]);
}

int main(){
    int n;
    cin>>n;
    FOR(i,n){
        scanf("%d",&val[i]);
    }
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(0,-1);
    printf("%d",dp[0]);
}
