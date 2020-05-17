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
vector<int> e[100005];
int visit[100005];
int par[100005];
int dp1[100005][2],dp2[100005][2];
int root(int i){
    while(i!=par[par[i]]){
        par[i]=par[par[i]];
        i = par[par[i]];
    }
    return i;
}
int ch=0;
ii line;
int find(int u){
    visit[u]=1;
    for(auto v:e[u])if(!visit[v]){find(v);}
    if(u==line.f){
        for(auto v:e[u]){
            dp1[u][1]+=max(dp1[v][1],dp1[v][0]);
        }
    }
    else{
        for(auto v:e[u]){
            dp1[u][0]+=dp1[v][1];
            dp1[u][1]+=max(dp1[v][1],dp1[v][0]);
        }
        dp1[u][0]++;
    }

    if(u==line.f){
        for(auto v:e[u]){
            dp2[u][0]+=dp2[v][1];
        }
        dp2[u][0]++;
    }
    else if(u==line.s){
        for(auto v:e[u]){
            dp2[u][1]+=max(dp2[v][1],dp2[v][0]);
        }
    }
    else{
        for(auto v:e[u]){
            dp2[u][0]+=dp2[v][1];
            dp2[u][1]+=max(dp2[v][1],dp2[v][0]);
        }
            dp2[u][0]++;
    }
   //printf("0 %d -> %d %d\n",u,dp1[u][0],dp1[u][1]);
}
vector<ii> cut;
int main(){
   //rf();
    int T;
    cin>>T;
    while(T--){
        int ans=0;
        int n;
        cin>>n;
        FOR1(i,n)e[i].clear();
        cut.clear();
        FOR1(i,n)par[i]=i;
        FOR1(i,n){
            int x;
            scanf("%d",&x);
            if(root(x)==root(i)){
                cut.pb(x,i);
                continue;
            }
            par[root(x)]=root(i);
            e[i].pb(x);
            e[x].pb(i);
        }
        FOR1(i,n)dp1[i][0]=0,dp1[i][1]=0,dp2[i][0]=0,dp2[i][1]=0,visit[i]=0;
        for(auto i:cut){
                line = i;
               // printf("/%d %d/\n",line.f,line.s);
                find(i.f);
                ans+=max(max(dp1[i.f][0],dp1[i.f][1]),max(dp2[i.f][0],dp2[i.f][1]));
        }
        printf("%d\n",n-ans);
    }
}
