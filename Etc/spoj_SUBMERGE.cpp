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
int ans,ptr;
const int INF=1e9;
int num[10005],low[10005],art[10005];
vector<int> e[10005];
void findart(int u,int p){
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
int main(){
    int n,m;
    while(1){
        cin>>n>>m;
        ans=0,ptr=1;
        if(n==0&&m==0)return 0;
        FOR1(i,n){
            e[i].clear();
            art[i]=0;
            low[i]=0;
            num[i]=0;
        }
        FOR(i,m){
            int a,b;
            cin>>a>>b;
            e[a].pb(b);
            e[b].pb(a);
        }
        findart(1,0);
        FOR1(i,n)if(art[i])ans++;
        printf("%d\n",ans);
    }
}
