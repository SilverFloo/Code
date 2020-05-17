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
ii edge[100005];
int n,m;
bool visit[100005];
int color[100005];
 vector<int> e[100005];
 int st=0;
 void dfs(int u,int c){
    if(color[u]==!c&&color[u]!=-1){st=1;return;}
    if(visit[u])return;
    //printf("%d %d",u,c);
    visit[u]=1;
    color[u]=c;
    for(auto v:e[u])dfs(v,!c);

}
bool bi(int x){
    st=0;
    FOR1(i,n)visit[i]=0,color[i]=-1,e[i].clear();
    FOR(i,x){
        e[edge[i].f].pb(edge[i].s);
        e[edge[i].s].pb(edge[i].f);
    }
    FOR1(i,n){
        if(!visit[i]){
            dfs(i,1);
            if(st==1)return 0;
        }
    }
    return 1;
}

int main(){
    cin>>n>>m;
    int ans=-1;
    FOR(i,m)scanf("%d %d",&edge[i].f,&edge[i].s);
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(bi(mid)){l=mid+1;ans=mid;}
        else r=mid-1;
       // printf("<%d>",mid);
    }
    printf("%d",ans);

}
