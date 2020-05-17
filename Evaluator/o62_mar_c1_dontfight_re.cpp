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
ll sum[300005];
vector<int> e[300005];
bool visit[300005];
set<ll> a,b;
ll ans = 2e18;
void dfs(int u){
    visit[u]=1;
    for(auto v:e[u]){
        if(!visit[v])dfs(v),sum[u]+=sum[v];
    }
}
ll diff(ll a,ll b,ll c){
    return max(a,max(b,c))-min(a,min(b,c));
}
void find(int u){
    visit[u]=1;
    ll x = (sum[1]-sum[u])/2;
    if(!a.empty()){
        ll m;
        auto p = a.lower_bound(x);
        if(p==a.begin()){
            m=*p;
        }
        else if(p==a.end()){
            p--;
            m=*p;
        }
        else {

            ll r = *p;
            p--;
            ll l = *p;
            m = x-l<r-x?l:r;
        }
        ans=min(ans,diff(sum[u],m,sum[1]-sum[u]-m));
    }
    x+=sum[u];
    if(!b.empty()){
        ll m;
        auto p = b.lower_bound(x);
        if(p==b.begin()){
            m=*p;
        }
        else if(p==b.end()){
            p--;
            m=*p;
        }
        else {
            ll r = *p;
            p--;
            ll l = *p;
            m = x-l<r-x?l:r;
        }
      // printf("//(%lld)%lld %lld %lld\n",x,sum[u],m-sum[u],sum[1]-m);
        ans=min(ans,diff(sum[u],m-sum[u],sum[1]-m));
    }

    int ch=0;
    if(b.find(sum[u])==b.end())ch=1;
    b.insert(sum[u]);
    for(auto v:e[u])if(!visit[v])find(v);
    if(ch)b.erase(sum[u]);
    a.insert(sum[u]);
}
int main(){
    int n;
    cin>>n;
    FOR1(i,n)scanf("%lld",&sum[i]);
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs(1);
    FOR1(i,n)visit[i]=0;
    find(1);
    printf("%lld",ans);
}
