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
int scc[200005];
int no[200005];
vector<int> edge[200005],rvedge[200005];
ii e[200005];
bool visit[200005];
stack<int> q;
void dfs(int u){
    if(visit[u])return;
    visit[u]=1;
    q.p(u);
    for(auto v:edge[u]){
        dfs(v);
    }
}
int st=1;
void redfs(int u,int cnt){
    if(scc[u]!=0)return;
    printf("%d->",u);
    scc[u]=cnt;
    if(scc[no[u]]==scc[u]){st=0;return;}
    for(auto v:rvedge[u])redfs(v,cnt);
}
int main(){
    int k=5;
    while(k--){
        int n,m;
        cin>>m>>n;
        FOR1(i,n)edge[i].clear(),rvedge[i].clear(),visit[i]=0,scc[i]=0;
        FOR(i,m)scanf("%d %d",&e[i].f,&e[i].s);
        FOR(i,n/2){
            int a,b;
            scanf("%d %d",&a,&b);
            no[a]=b;
            no[b]=a;
        }
        FOR(i,m){
            edge[no[e[i].f]].pb(e[i].s);
            edge[no[e[i].s]].pb(e[i].f);
            rvedge[e[i].s].pb(no[e[i].f]);
            rvedge[e[i].f].pb(no[e[i].s]);
            printf(">>%d %d\n",no[e[i].f],e[i].s);
            printf(">>%d %d\n",no[e[i].s],e[i].f);
        }
        FOR1(i,n){
            if(!visit[i])dfs(i);
        }
        int cnt=1;
        st=1;
        FOR1(i,n){
            if(scc[i]==0){redfs(i,cnt);cnt++;cout<<endl;}
            if(st==0)break;
        }
        printf("%c",st?'Y':'N');

    }
}
