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
#define ii pair<long long,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
vector<ii> e[100005];
ll dist[100005];
bool skip[100005];
vector<int> bf[100005];

void find(int u){
    if(skip[u])return;
    //printf("%d>",u);
    skip[u]=1;
    for(auto v:bf[u])find(v);
}
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        e[a].pb(b,c);
        e[b].pb(a,c);
    }
    int a,b;
    cin>>a>>b;
    FOR1(i,n)dist[i]=1e18;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    dist[a]=0;
    q.p(dist[a],a);
    while(!q.empty()){
        ll l=q.top().f;
        int u=q.top().s;
        q.pop();
        if(dist[u]!=l)continue;
        for(auto v:e[u]){
            if(dist[v.f]>dist[u]+(ll)v.s){
                dist[v.f]=dist[u]+(ll)v.s;
                bf[v.f].clear();
                bf[v.f].pb(u);
                q.p(dist[v.f],v.f);
            }
            else if(dist[v.f]==dist[u]+(ll)v.s){
                bf[v.f].pb(u);
            }
        }
    }

    find(b);

    FOR1(i,n)dist[i]=1e18;
    int c,d;
    cin>>c>>d;
    dist[c]=0;

    q.p(dist[c],c);
    while(!q.empty()){
        ll l=q.top().f;
        int u=q.top().s;
        q.pop();
        if(dist[u]!=l)continue;
        for(auto v:e[u]){
            if(skip[u]||skip[v.f])continue;
            if(dist[v.f]>dist[u]+(ll)v.s){
                dist[v.f]=dist[u]+(ll)v.s;
                q.p(dist[v.f],v.f);
            }
        }
    }
    printf("%lld",dist[d]==1e18?-1:dist[d]);
}
