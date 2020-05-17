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
vector<int> e[200005];
ii edge[200005];
int c[200005];
void dfs(int u){
    for(auto v:e[u]){
        if(c[v]==0){
            if(c[u]==1)c[v]=2;
            else c[v]=1;
            dfs(v);
        }
        if(c[v]==c[u]){
            printf("NO");
            exit(0);
        }


    }
}
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        e[a].pb(b);
        e[b].pb(a);
        edge[i].f=a;
        edge[i].s=b;
    }
    c[1]=1;
    dfs(1);
    printf("YES\n");
    FOR(i,m){
        if(c[edge[i].s]==1)printf("0");
        else printf("1");
    }
}
